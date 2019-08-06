// SubsystemTool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

int ProcessPath(_TCHAR* path, _TCHAR* subsys, BOOL ResetVersion);

BOOL DirectoryExists(LPCTSTR szPath)
{
	DWORD dwAttrib = GetFileAttributes(szPath);

	return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
		(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

_TCHAR* GetSubsystemByVal(int subsys)
{
	switch (subsys)
	{
	case 0: return (TCHAR*)TEXT("unknown");
	case 1: return (TCHAR*)TEXT("native");
	case 2: return (TCHAR*)TEXT("win32gui");
	case 3: return (TCHAR*)TEXT("win32cui");
	case 5: return (TCHAR*)TEXT("os2cui");
	case 7: return (TCHAR*)TEXT("posixcui");
	case 9: return (TCHAR*)TEXT("wince");
	case 10: return (TCHAR*)TEXT("efi_app");
	case 11: return (TCHAR*)TEXT("efi_boot_service_driver");
	case 12: return (TCHAR*)TEXT("efi_runtime_driver");
	case 13: return (TCHAR*)TEXT("efi_rom");
	case 14: return (TCHAR*)TEXT("xbox");
	case 16: return (TCHAR*)TEXT("windows_boot_app");
	default: return (TCHAR*)TEXT("undefined");
	}
}

int SearchForFilesThere(_TCHAR* path, _TCHAR* append, _TCHAR* subsys, BOOL CheckForFolder, BOOL ResetVersion)
{
	_TCHAR fullFileName[MAX_PATH] = { };
	_TCHAR szDir[MAX_PATH] = { };
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	// Add path and append additional text
	StringCchCopy(szDir, MAX_PATH, path);
	StringCchCat(szDir, MAX_PATH, append);

	// Search for the files there
	hFind = FindFirstFile(szDir, &FindFileData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		_tprintf(TEXT("Can't enumerate files (%d)\n"), GetLastError());
		return 2;
	}
	else
	{
		while (true)
		{
			StringCchCopy(fullFileName, MAX_PATH, path);
			StringCchCat(fullFileName, MAX_PATH, TEXT("\\"));
			StringCchCat(fullFileName, MAX_PATH, FindFileData.cFileName);

			int result = 0;
			if (!CheckForFolder) result = ProcessPath(fullFileName, subsys, ResetVersion);
			else if (CheckForFolder && DirectoryExists(fullFileName)) result = ProcessPath(fullFileName, subsys, ResetVersion);

			if (result != 0) // Failed to process file
			{
				FindClose(hFind);
				return result;
			}

			// Search for the next or continue
			if (!FindNextFile(hFind, &FindFileData)) break;
		}

		FindClose(hFind);
	}

	return 0;
}

int ProcessPath(_TCHAR* path, _TCHAR* subsys, BOOL ResetVersion)
{
	if (DirectoryExists(path))
	{
		if (path[0] == '.') return 0; // skip folder starting from .

		int result = 0;

		// 1st look for folder inside and do ProcessPath there (currently not working!)
		// result = SearchForFilesThere(path, (_TCHAR*)TEXT("\\*"), subsys, TRUE);
		// if (result != 0) return result; // failed

		// 2nd search for *.exe and *.dll files in current folder and ProcessPath them
		result = SearchForFilesThere(path, (_TCHAR*)TEXT("\\*.exe"), subsys, FALSE, ResetVersion);
		if (result != 0) return result; // failed

		result = SearchForFilesThere(path, (_TCHAR*)TEXT("\\*.dll"), subsys, FALSE, ResetVersion);
		if (result != 0) return result; // failed
	}
	else  // File
	{
		_tprintf(TEXT("File %s\n"), path);

		// Open file for reading
		HANDLE hFile = CreateFile(
			path,
			GENERIC_READ,
			NULL,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL);

		if (hFile == INVALID_HANDLE_VALUE)
		{
			_tprintf(TEXT("Unable to open file for reading.\n"));
			return 5;
		}

	/*	if (GetFileSize(hFile, NULL) >= FILE_BUF_SIZE)
		{
			_tprintf(TEXT("Error: File is too big\n"));
			return 5;
		}
*/
		LPDWORD bytesWritten = 0;
		DWORD bRead = NULL, fLen = GetFileSize(hFile, NULL);
		char* fileBuf = new char[fLen];

		if (!ReadFile(hFile, fileBuf, fLen, &bRead, NULL))
		{
			_tprintf(TEXT("Failed to read file (%d)\n"), GetLastError());
			return 5;
		}
		
		// load headers from buffer
		PIMAGE_DOS_HEADER dosHeader = (PIMAGE_DOS_HEADER)fileBuf; // the MZ (DOS) header
		PIMAGE_NT_HEADERS ntHeaders = (PIMAGE_NT_HEADERS)((BYTE*)dosHeader + dosHeader->e_lfanew); //  get the OFFSET of the PE (NT) header

		// Parse for prepared strings
		if (!_tcscmp(subsys, TEXT("wince"))) subsys = (TCHAR*)TEXT("9");
		else if (!_tcscmp(subsys, TEXT("win32gui"))) subsys = (TCHAR*)TEXT("2");
		else if (!_tcscmp(subsys, TEXT("win32cui"))) subsys = (TCHAR*)TEXT("3");

		// Convert subsystem to int
		int subsysVal = _tstoi(subsys);

		_tprintf(TEXT("          Subsystem: %d (%s) -> %d (%s)\n"), ntHeaders->OptionalHeader.Subsystem, GetSubsystemByVal(ntHeaders->OptionalHeader.Subsystem), subsysVal, GetSubsystemByVal(subsysVal));

		// Change subsystem number
		ntHeaders->OptionalHeader.Subsystem = subsysVal;

		if (ResetVersion)
		{
			// Reset subsystem version
			_tprintf(TEXT("  Subsystem Version: %d.%d -> 4.0\n"), ntHeaders->OptionalHeader.MajorSubsystemVersion, ntHeaders->OptionalHeader.MinorSubsystemVersion);

			ntHeaders->OptionalHeader.MajorSubsystemVersion = 4;
			ntHeaders->OptionalHeader.MinorSubsystemVersion = 0;
		}

		// Free memory
		LocalFree(dosHeader);
		LocalFree(ntHeaders);

		CloseHandle(hFile);

		// Recreate file for writing
		hFile = CreateFile(
			path,
			GENERIC_WRITE,
			NULL,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL);

		if (hFile == INVALID_HANDLE_VALUE)
		{
			_tprintf(TEXT("Unable to open file for writing.\n"));
			return 5;
		}

		// Write buffer to the created file
		if (!WriteFile(hFile, fileBuf, fLen, bytesWritten, NULL))
		{
			_tprintf(TEXT("Failed to save file (%d)\n"), GetLastError());
			return 5;
		}
		
		delete fileBuf;

		CloseHandle(hFile);
	}

	return 0;
}

BOOL ThereIsArgument(int argc, _TCHAR* argv[], _TCHAR* arg)
{
	for (int i = 1; i < argc; i++) 
	{
		if (!_tcscmp(argv[i], arg))
			return TRUE;
	}

	return FALSE;
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc <= 1 
		|| ThereIsArgument(argc, argv, (_TCHAR*)TEXT("/help"))
		|| ThereIsArgument(argc, argv, (_TCHAR*)TEXT("--help"))
		|| ThereIsArgument(argc, argv, (_TCHAR*)TEXT("/?"))
		|| ThereIsArgument(argc, argv, (_TCHAR*)TEXT("/h"))
		|| ThereIsArgument(argc, argv, (_TCHAR*)TEXT("-h")))
	{
		_tprintf(TEXT("Usage: SubsytemTool.exe [PATH] [SUBSYSTEM NUMBER OR NAME] [/rv]\n\n"));
		_tprintf(TEXT("[PATH] can be directory path or file path.\n\n"));
		_tprintf(TEXT("You can enter any subsystem number or one from the available names:\n"));
		_tprintf(TEXT("wince, win32gui (default), win32cui.\n\n"));
		_tprintf(TEXT("Include /rv after subsystem if you want to reset subsystem version.\n"));
		return 1;
	}

	BOOL ResetVersion = ThereIsArgument(argc, argv, (_TCHAR*)TEXT("/rv"));
	return ProcessPath(argv[1], (argc >= 3 ? argv[2] : (_TCHAR*)TEXT("win32gui")), ResetVersion);
}
