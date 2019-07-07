// winbase_wcecl.cpp : wce/winbase.h functions
#include "stdafx.h"

// Functions
int WINAPI LoadStringW_WCECL(
	HINSTANCE hInstance,
	UINT uID,
	LPWSTR lpBuffer,
	int nBufferMax)
{
	auto result = ::LoadStringW(NULL, uID, lpBuffer, nBufferMax);

	if (w32err(result == NULL))
	{
		auto win32error = GetLastError();
		DebugBreak();
	}

	return result;
}

DWORD WINAPI Random()
{
	// sources: https://docs.microsoft.com/en-us/previous-versions/windows/embedded/ms860353(v%3Dmsdn.10)
	//          https://docs.microsoft.com/en-us/previous-versions/ms910957(v=msdn.10)
	::srand(::GetTickCount());
	auto result = ::rand();
	return result;
}

HLOCAL WINAPI LocalAlloc_WCECL(
	UINT fuFlags,
	UINT cbBytes)
{
	auto result = ::LocalAlloc(fuFlags, cbBytes);
	return result;
}

HINSTANCE WINAPI LoadLibraryW_WCECL(LPCWSTR lpLibFileName)
{
	auto result = ::LoadLibraryW(lpLibFileName);
	return result;
}

BOOL WINAPI TerminateProcess_WCECL(
	HANDLE hProcess,
	DWORD uExitCode)
{
	auto result = ::TerminateProcess(hProcess, uExitCode);
	return result;
}
// Stubs

