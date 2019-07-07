// excpt_wcecl.cpp : wce/excpt.h functions and some other related
#include "stdafx.h"

// Functions
DWORD WINAPI _except_handler4_common_WCECL(DWORD nBufferLength, LPWSTR lpBuffer)
{
	// fix me: exception handler

	int result = MessageBoxExW(
		NULL,
		L"WARNING: Exception happened!\n\nYES - continue\nNO - exit",
		L"Windows CE Compatibility Layer",
		MB_YESNO,
		MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));

	if (result == IDYES) return 0;
	else exit(1);

	return 0;
}

// Stubs
StubEx(__cdecl, _XcptFilter_WCECL); // unsigned long a1, struct _EXCEPTION_POINTERS * a2
StubSilent(__security_gen_cookie2);
Stub(__report_gsfailure_WCECL);
