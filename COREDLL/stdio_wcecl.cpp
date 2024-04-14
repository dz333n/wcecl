#include "stdafx.h"
#include <assert.h>
#include <io.h>

static DWORD GetWin32ConsoleModeFromWce(DWORD wceConsoleMode)
{
	DWORD out = 0;

	if (wceConsoleMode & CECONSOLE_MODE_ECHO_INPUT)
	{
		out |= ENABLE_ECHO_INPUT;
	}
	if (wceConsoleMode & CECONSOLE_MODE_LINE_INPUT)
	{
		out |= ENABLE_LINE_INPUT;
	}
	if (wceConsoleMode & CECONSOLE_MODE_PROCESSED_OUTPUT)
	{
		out |= ENABLE_PROCESSED_OUTPUT;
	}

	return out;
}

static DWORD GetWceConsoleModeFromWin32(DWORD win32ConsoleMode)
{
	DWORD out = 0;

	if (win32ConsoleMode & ENABLE_ECHO_INPUT)
	{
		out |= CECONSOLE_MODE_ECHO_INPUT;
	}
	if (win32ConsoleMode & ENABLE_LINE_INPUT)
	{
		out |= CECONSOLE_MODE_LINE_INPUT;
	}
	if (win32ConsoleMode & ENABLE_PROCESSED_OUTPUT)
	{
		out |= CECONSOLE_MODE_PROCESSED_OUTPUT;
	}

	return out;
}

static BOOL WceclConsoleSetMode(
	HANDLE hDevice,
	DWORD* lpInBuf,
	DWORD nInBufSize)
{
	if (nInBufSize < sizeof(DWORD))
	{
		return FALSE;
	}
	return SetConsoleMode(
		hDevice,
		GetWin32ConsoleModeFromWce(*lpInBuf));
}

static BOOL WceclConsoleGetMode(
	HANDLE hDevice,
	DWORD* lpOutBuf,
	DWORD nOutBufSize)
{
	DWORD win32ConsoleMode;
	BOOL result;

	if (nOutBufSize < sizeof(DWORD))
	{
		return FALSE;
	}
	result = GetConsoleMode(hDevice, &win32ConsoleMode);
	if (!result)
	{
		return FALSE;
	}
	*((DWORD*)lpOutBuf) = GetWceConsoleModeFromWin32(win32ConsoleMode);
	return TRUE;
}

static BOOL WceclConsoleSetTitle(
	LPCSTR lpInBuf,
	DWORD nInBufSize)
{
	BOOL result;
	
	/* Create a copy of the buffer to not read garbage if the original buffer 
	   is short. */
	char* bufferCopy = new char[nInBufSize + 1];
	bufferCopy[nInBufSize] = '\0';
	memcpy(bufferCopy, lpInBuf, nInBufSize);

	result = SetConsoleTitleA(bufferCopy);

	delete[] bufferCopy;
	return result;
}

static BOOL WceclConsoleGetTitle(
	LPSTR lpOutBuf,
	DWORD nOutBufSize)
{
	return GetConsoleTitleA(lpOutBuf, nOutBufSize);
}

BOOL WceclConsoleIoControl(
	HANDLE hDevice,
	DWORD dwIoControlCode,
	LPVOID lpInBuf,
	DWORD nInBufSize,
	LPVOID lpOutBuf,
	DWORD nOutBufSize,
	LPDWORD lpBytesReturned,
	LPOVERLAPPED lpOverlapped)
{
	switch (dwIoControlCode)
	{
	case IOCTL_CONSOLE_SETMODE:
		return WceclConsoleSetMode(hDevice, (DWORD*)lpInBuf, nInBufSize);
	case IOCTL_CONSOLE_GETMODE:
		return WceclConsoleGetMode(hDevice, (DWORD*)lpOutBuf, nOutBufSize);
	case IOCTL_CONSOLE_SETTITLE:
		return WceclConsoleSetTitle((LPCSTR)lpInBuf, nInBufSize);
	case IOCTL_CONSOLE_GETTITLE:
		return WceclConsoleGetTitle((LPSTR)lpOutBuf, nOutBufSize);
	case IOCTL_CONSOLE_CLS:
		/* TODO */
		return TRUE;
	default:
		/* TODO */
		return FALSE;
	}

	return FALSE;
}

FILE* WINAPI _getstdfilex_WCECL(DWORD type)
{
	switch (type)
	{
	case 0:
		return stdin;
	case 1:
		return stdout;
	case 2:
		return stderr;
	default:
		Assert32(FALSE);
		return NULL;
	}
}

BOOL WINAPI SetStdioPathW_WCECL(
	DWORD id,
	PWSTR pwszPath)
{
	/* TODO: test */
	switch (id)
	{
	case 0:
		return (_wfreopen(pwszPath, L"r", stdin) != NULL);
	case 1:
		return (_wfreopen(pwszPath, L"w", stdout) != NULL);
	case 2:
		return (_wfreopen(pwszPath, L"w", stderr) != NULL);
	default:
		Assert32(FALSE);
		return NULL;
	}
}

BOOL WINAPI GetStdioPathW_WCECL(
	DWORD id,
	PWSTR pwszBuf,
	LPDWORD lpdwLen)
{
	/* TODO: test */
	FILE* filePtr = _getstdfilex_WCECL(id);
	HANDLE hFile = (HANDLE)_get_osfhandle(_fileno(filePtr));
	if (GetFinalPathNameByHandleW(hFile, pwszBuf, *lpdwLen, 0) < *lpdwLen)
	{
		return TRUE;
	}

	return FALSE;
}