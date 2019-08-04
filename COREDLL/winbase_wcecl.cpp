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

HANDLE WINAPI OpenProcess_WCECL(
	DWORD fdwAccess,
	BOOL fInherit,
	DWORD IDProcess)
{
	auto result = OpenProcess(fdwAccess, fInherit, IDProcess);
	return result;
}

BOOL WINAPI CreateDirectoryW_WCECL(
	LPCWSTR lpPathName,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
	auto result = CreateDirectoryW(lpPathName, lpSecurityAttributes);
	return result;
}

BOOL WINAPI GetExitCodeProcess_WCECL(
	HANDLE hProcess,
	LPDWORD lpExitCode)
{
	auto result = GetExitCodeProcess(hProcess, lpExitCode);
	return result;
}

LONG WINAPI CompareFileTime_WCECL(const FILETIME *lpft1, const FILETIME *lpft2)
{
	auto result = CompareFileTime(lpft1, lpft2);
	return result;
}

BOOL GetDiskFreeSpaceExW_WCECL(LPCWSTR lpDirectoryName, PULARGE_INTEGER lpFreeBytesAvailableToCaller,
	PULARGE_INTEGER lpTotalNumberOfBytes, PULARGE_INTEGER lpTotalNumberOfFreeBytes)
{
	auto result = GetDiskFreeSpaceExW(lpDirectoryName, lpFreeBytesAvailableToCaller, lpTotalNumberOfBytes, lpTotalNumberOfFreeBytes);
	return result;
}

BOOL WINAPI FileTimeToSystemTime_WCECL(const FILETIME *lpft, LPSYSTEMTIME lpst)
{
	auto result = FileTimeToSystemTime(lpft, lpst);
	return result;
}

BOOL WINAPI SystemTimeToFileTime_WCECL(const SYSTEMTIME *lpst, LPFILETIME lpft)
{
	auto result = SystemTimeToFileTime(lpst, lpft);
	return result;
}

BOOL WINAPI SetFileAttributesW_WCECL(
	LPCWSTR lpFileName,
	DWORD dwFileAttributes)
{
	auto result = SetFileAttributesW(lpFileName, dwFileAttributes);
	return result;
}

BOOL WINAPI SetLocalTime_WCECL(CONST SYSTEMTIME *lpSystemTime)
{
	auto result = SetLocalTime(lpSystemTime);
	return result;
}

BOOL WINAPI MoveFileW_WCECL(
	LPCWSTR lpExistingFileName,
	LPCWSTR lpNewFileName)
{
	auto result = MoveFileW(lpExistingFileName, lpNewFileName);
	return result;
}

BOOL WINAPI CopyFileW_WCECL(
	LPCWSTR lpExistingFileName,
	LPCWSTR lpNewFileName,
	BOOL bFailIfExists)
{
	auto result = CopyFileW(lpExistingFileName, lpNewFileName, bFailIfExists);
	return result;
}

BOOL WINAPI GetFileTime_WCECL(HANDLE hFile, LPFILETIME lpCreation, LPFILETIME lpLastAccess, LPFILETIME lpLastWrite)
{
	auto result = GetFileTime(hFile, lpCreation, lpLastAccess, lpLastWrite);
	return result;
}

BOOL WINAPI SetFileTime_WCECL(HANDLE hFile, CONST FILETIME *lpCreation, CONST FILETIME *lpLastAccess, CONST FILETIME *lpLastWrite)
{
	auto result = SetFileTime(hFile, lpCreation, lpLastAccess, lpLastWrite);
	return result;
}

VOID WINAPI GetLocalTime_WCECL(LPSYSTEMTIME lpSystemTime)
{
	GetLocalTime(lpSystemTime);
}

BOOL WINAPI RemoveDirectoryW_WCECL(LPCWSTR lpPathName)
{
	auto result = RemoveDirectoryW(lpPathName);
	return result;
}

BOOL WINAPI DeleteFileW_WCECL(LPCWSTR lpFileName)
{
	auto result = DeleteFileW(lpFileName);
	return result;
}

HANDLE WINAPI FindFirstFileW_WCECL(
	LPCWSTR lpFileName,
	LPWIN32_FIND_DATAW lpFindFileData)
{
	auto result = FindFirstFileW(lpFileName, lpFindFileData);
	return result;
}

BOOL WINAPI FindNextFileW_WCECL(
	HANDLE hFindFile,
	LPWIN32_FIND_DATAW lpFindFileData)
{
	auto result = FindNextFileW(hFindFile, lpFindFileData);
	return result;
}

BOOL WINAPI FindClose_WCECL(HANDLE hFindFile)
{
	auto result = FindClose(hFindFile);
	return result;
}

HLOCAL WINAPI LocalReAlloc_WCECL(
	HLOCAL hMem,
	UINT cbBytes,
	UINT fuFlags)
{
	auto result = LocalReAlloc(hMem, cbBytes, fuFlags);
	return result;
}

DWORD WINAPI GetFileAttributesW_WCECL(LPCWSTR lpFileName)
{
	auto result = GetFileAttributesW(lpFileName);
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

HMODULE WINAPI GetModuleHandleW_WCECL(LPCWSTR lpModuleName)
{
	auto result = GetModuleHandleW(lpModuleName);
	return result;
}

std::string WStringToString(const std::wstring& s)
{
	std::string temp(s.length(), ' ');
	std::copy(s.begin(), s.end(), temp.begin());
	return temp;
}

FARPROC WINAPI GetProcAddressW_WCECL(
	HMODULE hModule,
	LPCWSTR lpProcName)
{
	std::string narrow_str(WStringToString(lpProcName));
	LPCSTR win_str = narrow_str.c_str();

	auto result = GetProcAddress(hModule, win_str);
	return result;
}

BOOL WINAPI DeviceIoControl_WCECL(
	HANDLE hDevice,
	DWORD dwIoControlCode,
	LPVOID lpInBuf,
	DWORD nInBufSize,
	LPVOID lpOutBuf,
	DWORD nOutBufSize,
	LPDWORD lpBytesReturned,
	LPOVERLAPPED lpOverlapped)
{
	auto result = DeviceIoControl(
		hDevice,
		dwIoControlCode,
		lpInBuf,
		nInBufSize,
		lpOutBuf,
		nOutBufSize,
		lpBytesReturned,
		lpOverlapped);
	return result;
}

BOOL WINAPI TerminateThread_WCECL(
	HANDLE hThread,
	DWORD dwExitCode)
{
	auto result = TerminateThread(hThread, dwExitCode);
	return result;
}

HANDLE WINAPI CreateThread_WCECL(
	LPSECURITY_ATTRIBUTES lpsa,
	DWORD   cbStack,
	LPTHREAD_START_ROUTINE lpStartAddr,
	LPVOID lpvThreadParam,
	DWORD fdwCreate,
	LPDWORD lpIDThread)
{
	auto result = CreateThread(lpsa, cbStack, lpStartAddr, lpvThreadParam, fdwCreate, lpIDThread);
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

DWORD WINAPI WaitForSingleObject_WCECL(
	HANDLE hHandle,
	DWORD dwMilliseconds)
{
	auto result = WaitForSingleObject(hHandle, dwMilliseconds);
	return result;
}

DWORD WINAPI WaitForMultipleObjects_WCECL(
	DWORD cObjects,
	CONST HANDLE *lphObjects,
	BOOL fWaitAll,
	DWORD dwTimeout)
{
	auto result = WaitForMultipleObjects(cObjects, lphObjects, fWaitAll, dwTimeout);
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

