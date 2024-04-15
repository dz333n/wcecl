// dbgapi_wcecl.cpp : wce/dbgapi.h functions
#include "stdafx.h"

// Functions
void WINAPIV NKDbgPrintfW(LPCWSTR lpszFmt, ...)
{
	va_list args;
	va_start(args, lpszFmt);
	
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	vwprintf(lpszFmt, args);

	ProgramErrorDialog(L"Function NKDbgPrintfW is not implemented yet.", FALSE);
	va_end(args);
}

// Stubs

