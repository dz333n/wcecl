#include "stdafx.h"
#include <io.h>

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