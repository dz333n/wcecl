// dbgapi_wcecl.cpp : wce/dbgapi.h functions
#include "stdafx.h"

// Functions
void WINAPIV NKDbgPrintfW(LPCWSTR lpszFmt, ...)
{
	ProgramErrorDialog(L"Function NKDbgPrintfW is not implemented yet.", FALSE);

	va_list args;
	va_start(args, lpszFmt);
	// todo
	va_end(args);
}

// Stubs

