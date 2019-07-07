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

BOOL WINAPI WriteFile_WCECL(
	HANDLE hFile,
	LPCVOID lpBuffer,
	DWORD nNumberOfBytesToWrite,
	LPDWORD lpNumberOfBytesWritten,
	LPOVERLAPPED lpOverlapped)
{
	auto result = ::WriteFile(
		hFile,
		lpBuffer,
		nNumberOfBytesToWrite,
		lpNumberOfBytesWritten,
		lpOverlapped);
	return result;
}

BOOL WINAPI CloseHandle_WCECL(
	HANDLE hObject)
{
	auto result = ::CloseHandle(hObject);
	return result;
}

BOOL WINAPI ReadFile_WCECL(
	HANDLE hFile,
	LPVOID lpBuffer,
	DWORD nNumberOfBytesToRead,
	LPDWORD lpNumberOfBytesRead,
	LPOVERLAPPED lpOverlapped)
{
	auto result = ::ReadFile(
		hFile,
		lpBuffer,
		nNumberOfBytesToRead,
		lpNumberOfBytesRead,
		lpOverlapped);
	return result;
}

DWORD WINAPI SetFilePointer_WCECL(
	HANDLE hFile,
	LONG lDistanceToMove,
	PLONG lpDistanceToMoveHigh,
	DWORD dwMoveMethod)
{
	auto result = ::SetFilePointer(
		hFile,
		lDistanceToMove,
		lpDistanceToMoveHigh,
		dwMoveMethod);
	return result;
}

HANDLE WINAPI CreateFileW_WCECL(
	LPCWSTR lpFileName,
	DWORD dwDesiredAccess,
	DWORD dwShareMode,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition,
	DWORD dwFlagsAndAttributes,
	HANDLE hTemplateFile)
{
	auto result = ::CreateFileW(
		lpFileName,
		dwDesiredAccess,
		dwShareMode,
		lpSecurityAttributes,
		dwCreationDisposition,
		dwFlagsAndAttributes,
		hTemplateFile);
	return result;
}


HANDLE WINAPI CreateEventW_WCECL(
	LPSECURITY_ATTRIBUTES lpEventAttributes,
	BOOL bManualReset,
	BOOL bInitialState,
	LPCWSTR lpName)
{
	auto result = ::CreateEventW(
		lpEventAttributes,
		bManualReset,
		bInitialState,
		lpName);
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

