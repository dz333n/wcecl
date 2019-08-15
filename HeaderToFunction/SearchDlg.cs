using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace HeaderToFunction
{
    public partial class SearchDlg : Form
    {
        public SearchDlg()
        {
            InitializeComponent();
        }

        private void UpdateControls()
        {
            btnCacheSearch.Text = $"...cache\r\n({HeaderSearch.Cache.Count} entries)";
            btnCacheSearch.Enabled = HeaderSearch.ThereIsCache;
            btnClearCache.Enabled = HeaderSearch.ThereIsCache;
        }

        private void SearchDlg_Load(object sender, EventArgs e)
        {
            UpdateControls();
        }

        private void btnClearCache_Click(object sender, EventArgs e)
        {
            HeaderSearch.Cache.Clear();
            GC.Collect();
            GC.WaitForPendingFinalizers();

            UpdateControls();
        }

        private void btnChooseFolder_Click(object sender, EventArgs e)
        {
            using (FolderBrowserDialog f = new FolderBrowserDialog())
            {
                if(f.ShowDialog() == DialogResult.OK)
                {
                    HeaderSearch.SearchWhat = tbSearchWhat.Text.Split(new char[] { ';' }, StringSplitOptions.RemoveEmptyEntries);
                    HeaderSearch.SearchType = HeaderSearch.SearchTypes.Folder;
                    HeaderSearch.SearchTarget = new string[] { f.SelectedPath };

                    new SearchCfgDlg().ShowDialog();

                    HeaderSearch.StartSearch();

                    this.Close();
                }
            }
        }

        private void btnSelectFiles_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog f = new OpenFileDialog())
            {
                f.Multiselect = true;

                if (f.ShowDialog() == DialogResult.OK)
                {
                    HeaderSearch.SearchWhat = tbSearchWhat.Text.Split(new char[] { ';' }, StringSplitOptions.RemoveEmptyEntries);
                    HeaderSearch.SearchType = HeaderSearch.SearchTypes.File;
                    HeaderSearch.SearchTarget = f.FileNames;

                    new SearchCfgDlg().ShowDialog();

                    HeaderSearch.StartSearch();

                    this.Close();
                }
            }
        }

        private void btnCacheSearch_Click(object sender, EventArgs e)
        {
            HeaderSearch.SearchWhat = tbSearchWhat.Text.Split(new char[] { ';' }, StringSplitOptions.RemoveEmptyEntries);
            HeaderSearch.SearchType = HeaderSearch.SearchTypes.Cache;
            HeaderSearch.StartSearch();

            this.Close();
        }

        private void btnPaste_Click(object sender, EventArgs e)
        {
            tbSearchWhat.Clear();
            tbSearchWhat.Paste();
        }
    }
}
