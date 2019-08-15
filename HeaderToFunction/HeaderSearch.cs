using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

namespace HeaderToFunction
{
    public static class HeaderSearch
    {
        public enum SearchStatus
        {
            Started,
            Finished,
            Error,
            FoundSomething
        }

        public enum SearchTypes
        {
            Folder,
            File,
            Cache
        }

        public delegate void SearchStatusChangedHandler(SearchStatus status, object StringOrExceptionOrNull = null);
        public static event SearchStatusChangedHandler StatusChanged;

        public delegate void SearchFileHandler(string fileName, int count = -1, int total = -1);
        public static event SearchFileHandler SearchFileChanged;

        public static List<HeaderSearchCache> Cache = new List<HeaderSearchCache>();

        public static bool ThereIsCache => Cache.Count >= 1;

        public static bool UseCache = true;
        public static string[] SearchWhat = { };
        public static string[] SearchTarget = { };
        public static SearchTypes SearchType = SearchTypes.File;
        public static bool Cancel = false;

        public static void StartSearch()
        {
            new Thread(() =>
            {
                Cancel = false;

                StatusChanged?.Invoke(SearchStatus.Started);
                SearchFileChanged?.Invoke("Starting...");

                try
                {
                    if (SearchType == SearchTypes.Folder)
                    {
                        string folder = SearchTarget[0];

                        SearchFileChanged?.Invoke(folder);

                        SearchTarget = Directory.GetFiles(folder, "*.h", SearchOption.AllDirectories);
                        SearchType = SearchTypes.File;
                    }

                    if (SearchType == SearchTypes.File)
                    {
                        for (int i = 0; i < SearchTarget.Length; i++)
                        {
                            var file = new FileInfo(SearchTarget[i]);
                            SearchFileChanged?.Invoke(file.FullName, i + 1, SearchTarget.Length);

                            var cache = GetCacheForFile(file);

                            var searchResult = cache.SearchHere(SearchWhat);

                            foreach (var result in searchResult)
                            {
                                StatusChanged?.Invoke(SearchStatus.FoundSomething, result);
                            }
                        }
                    }

                    if (SearchType == SearchTypes.Cache)
                    {
                        for (int i = 0; i < Cache.Count; i++)
                        {
                            var cache = Cache[i];
                            SearchFileChanged?.Invoke(cache.File.FullName, i + 1, Cache.Count);

                            var searchResult = cache.SearchHere(SearchWhat);

                            foreach (var result in searchResult)
                            {
                                StatusChanged?.Invoke(SearchStatus.FoundSomething, result);
                            }
                        }
                    }
                }
                catch (Exception ex)
                {
                    StatusChanged?.Invoke(SearchStatus.Error, ex);
                }

                StatusChanged?.Invoke(SearchStatus.Finished);
            }).Start();
        }

        public static HeaderSearchCache GetCacheForFile(FileInfo file)
        {
            var normal = Cache.FirstOrDefault(x => x.File.FullName == file.FullName);

            if (normal == null)
            {
                var cache = new HeaderSearchCache(file);
                if (UseCache) Cache.Add(cache);
                return cache;
            }
            else return normal;
        }
    }

    public class HeaderSearchCache
    {
        public FileInfo File;
        public string Content;
        public long Size = 0;

        public HeaderSearchCache(FileInfo file)
        {
            File = file;
            ValidateSize();
        }

        public HeaderSearchCache(FileInfo file, string content)
        {
            File = file;
            Content = content;
            Size = file.Length;
        }

        public void ValidateSize()
        {
            if (Size == 0 || Size != File.Length)
            {
                using (StreamReader r = new StreamReader(File.FullName))
                    Content = r.ReadToEnd();

                Size = File.Length;
            }
        }

        public string[] SearchHere(string[] what)
        {
            ValidateSize();
            List<string> result = new List<string>();

            foreach (var w in what)
            {
                var index = Content.IndexOf(w);

                again:
                if (index == -1) continue;

                // the next character before ; should be (
                bool GoodCharFound = false;
                for (int i = index + w.Length; i < Content.Length; i++)
                {
                    var c = Content[i];

                    if (string.IsNullOrWhiteSpace(c.ToString()))
                        continue;

                    if (c == '(') { GoodCharFound = true; break; }
                    else break;
                }

                if (!GoodCharFound)
                {
                    index = Content.IndexOf(w, index + 1);
                    goto again;
                }

                // search for new line before 
                int startIndex1 = 0;
                for (startIndex1 = index; startIndex1 >= 0; startIndex1--)
                {
                    if (Content[startIndex1] == '\r' || Content[startIndex1] == '\n') break;
                }

                // search for new line after 
                int endIndex1 = 0;
                for (endIndex1 = index + w.Length; endIndex1 < Content.Length; endIndex1++)
                {
                    if (Content[endIndex1] == '\r' || Content[endIndex1] == '\n') break;
                }

                string line = Content.Substring(startIndex1, endIndex1 - startIndex1).Trim(new char[] { '\r', '\n' });

                if (line.StartsWith("//") || line.Contains("/*") || line.Contains("*/"))
                {
                    index = Content.IndexOf(w, index + 1);
                    goto again;
                }

                // search for ; before 
                int startIndex = 0;
                for (startIndex = index; startIndex >= 0; startIndex--)
                {
                    if (Content[startIndex] == ';') break;
                }

                // search for ; after 
                int endIndex = 0;
                for (endIndex = index; endIndex < Content.Length; endIndex++)
                {
                    if (Content[endIndex] == ';') break;
                }

                string full = Content.Substring(startIndex, endIndex - startIndex)
                    .Trim().Trim(new char[] { ';' }).Trim() + ';';

                result.Add(full);
            }

            return result.ToArray();
        }
    }
}
