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
	Assert32Failed(result == NULL, LoadStringW_WCECL);
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

HRSRC WINAPI FindResourceW_WCECL(
	HMODULE hModule,
	LPCWSTR lpName,
	LPCWSTR lpType)
{
	auto result = FindResourceW(NULL, lpName, lpType);
	Assert32Failed(result == NULL, FindResourceW_WCECL);
	return result;
}

DWORD WINAPI GetTickCount_WCECL()
{
	auto result = GetTickCount();
	return result;
}

HGLOBAL WINAPI LoadResource_WCECL(
	HMODULE hModule,
	HRSRC hResInfo)
{
	auto result = LoadResource(NULL, hResInfo);
	Assert32Failed(result == NULL, LoadResource_WCECL);
	return result;
}

DWORD WINAPI FormatMessageW_WCECL(
	DWORD dwFlags,
	LPCVOID lpSource,
	DWORD dwMessageId,
	DWORD dwLanguageId,
	LPWSTR lpBuffer,
	DWORD nSize,
	va_list *Arguments)
{
	BOOL FormatMessageW_Fixed = FALSE;
	Assert32(FormatMessageW_Fixed == TRUE);

	// fix me
	auto result = FormatMessageW(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments);
	return result;
}

HLOCAL WINAPI LocalFree_WCECL(HLOCAL hMem)
{
	auto result = LocalFree(hMem);
	return result;
}

BOOL WINAPI FreeLibrary_WCECL(HMODULE hLibModule)
{
	auto result = FreeLibrary(hLibModule);
	return result;
}

BOOL WINAPI CreateProcessW_WCECL(
	LPCWSTR pszImageName,
	LPCWSTR pszCmdLine,
	LPSECURITY_ATTRIBUTES psaProcess,
	LPSECURITY_ATTRIBUTES psaThread,
	BOOL fInheritHandles,
	DWORD fdwCreate,
	LPVOID pvEnvironment,
	LPWSTR pszCurDir,
	LPSTARTUPINFO psiStartInfo,
	LPPROCESS_INFORMATION pProcInfo)
{
	auto result = CreateProcessW(
		pszImageName,
		(LPWSTR)pszCmdLine,
		psaProcess,
		psaThread,
		fInheritHandles,
		fdwCreate,
		pvEnvironment,
		pszCurDir,
		psiStartInfo,
		pProcInfo);

	Assert32Failed(result == NULL, CreateProcessW_WCECL);

	return result;
}

VOID WINAPI Sleep_WCECL(DWORD dwMilliseconds)
{
	Sleep(dwMilliseconds);
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

LPVOID WINAPI TlsGetValue_WCECL(DWORD dwTlsIndex)
{
	auto result = TlsGetValue(dwTlsIndex);
	return result;
}

BOOL WINAPI TlsSetValue_WCECL(
	DWORD dwTlsIndex,
	LPVOID lpvTlsValue)
{
	auto result = TlsSetValue(dwTlsIndex, lpvTlsValue);
	return result;
}

BOOL WINAPI SetThreadPriority_WCECL(
	HANDLE hThread,
	int nPriority)
{
	auto result = SetThreadPriority(hThread, nPriority);
	return result;
}

DWORD WINAPI GetModuleFileNameW_WCECL(
	HMODULE hModule,
	LPWSTR lpFilename,
	DWORD nSize)
{
	auto result = GetModuleFileNameW(hModule, lpFilename, nSize);
	return result;
}

BOOL WINAPI VirtualFree_WCECL(
	LPVOID lpAddress,
	DWORD dwSize,
	DWORD dwFreeType)
{
	auto result = VirtualFree(lpAddress, dwSize, dwFreeType);
	return result;
}

DWORD WINAPI Random()
{
	int result = rand();
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
	Assert32Failed(result == NULL, LoadLibraryW_WCECL);
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

