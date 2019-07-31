// shellapi_wcecl.cpp : wince/shellapi.h
#include "stdafx.h"
#include <ShellAPI.h>

#ifdef __stdcall
#undef __stdcall
typedef BOOL(__stdcall *Shell_NotifyIconW_Shell32)(DWORD dwMessage, PNOTIFYICONDATA lpData);
#define __stdcall __cdecl
#endif

// Functions
BOOL WINAPI Shell_NotifyIcon_WCECL(DWORD dwMessage, PNOTIFYICONDATA lpData)
{
	HINSTANCE h = LoadLibraryW(L"shell32.dll");

	if (w32err(!h))
	{
		auto win32error = GetLastError();
		DebugBreak(); 
	}

	Shell_NotifyIconW_Shell32 func = (Shell_NotifyIconW_Shell32)GetProcAddress(h, "Shell_NotifyIconW");

	if (w32err(!func))
		DebugBreak();

	auto result = func(dwMessage, lpData);

	FreeLibrary(h);

	return result;
}

HBITMAP WINAPI SHLoadDIBitmap_WCECL(LPCTSTR szFileName)
{
	auto result = (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	return result;
}

// Stubs
