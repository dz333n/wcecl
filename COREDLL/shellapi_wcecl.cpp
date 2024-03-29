// shellapi_wcecl.cpp : wince/shellapi.h
#include "stdafx.h"

// Functions
BOOL SHGetSpecialFolderPath_WCECL(HWND hwndOwner, LPSTR lpszPath, int nFolder, BOOL fCreate)
{
	auto result = ::SHGetSpecialFolderPathA(hwndOwner, lpszPath, nFolder, fCreate);
	return result;
}

BOOL WINAPI ShellExecuteEx_WCECL(LPSHELLEXECUTEINFO lpExecInfo)
{
	auto result = ShellExecuteExW(lpExecInfo);
	return result;
}

BOOL WINAPI Shell_NotifyIcon_WCECL(DWORD dwMessage, PNOTIFYICONDATA lpData)
{
	auto result = Shell_NotifyIcon(dwMessage, lpData);
	return result;
}

HBITMAP WINAPI SHLoadDIBitmap_WCECL(LPCTSTR szFileName)
{
	auto result = (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	return result;
}

DWORD WINAPI SHGetFileInfo_WCECL(LPCTSTR pszPath, DWORD dwFileAttributes, SHFILEINFO FAR* psfi, UINT cbFileInfo, UINT uFlags)
{
	// Win doc: https://learn.microsoft.com/ru-ru/windows/win32/api/shellapi/nf-shellapi-shgetfileinfow
	// WinCE doc: https://learn.microsoft.com/en-us/previous-versions/windows/embedded/aa453700(v=msdn.10)
	auto result = SHGetFileInfo(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags);
	return result;
}

// Stubs
Stub(SHCreateShortcut_WCECL);
