// shellapi_wcecl.cpp : wince/shellapi.h
#include "stdafx.h"

// Functions
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

// Stubs
