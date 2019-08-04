#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include "stdafx.h"

VOID DisplayAssert32ErrorDialog(LPCWSTR ExpressionText, LPCWSTR Comment, BOOL ShowLastError)
{
	WCHAR Buffer[512];
	DWORD Error = ShowLastError ? GetLastError() : 0xD3ADB33F;
	WCHAR ErrorBuffer[256];

	if (Error == 0) wcscpy_s(ErrorBuffer, 256, L"Unknown");
	else if (Error == 0xD3ADB33F) wcscpy_s(ErrorBuffer, 256, L"Not Win32 Error");
	else FormatMessageW(
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		Error,
		MAKELANGID(LANG_ENGLISH, SUBLANG_DEFAULT),
		ErrorBuffer,
		(sizeof(ErrorBuffer) / sizeof(WCHAR)),
		NULL);

	swprintf_s(
		Buffer, 512,
		L"%s%sExpression\n\n%s\n\nis TRUE.\n\n\nError %d - %s",
		Comment,
		wcslen(Comment) >= 1 ? L"\n\n\n" : L"",
		ExpressionText,
		Error,
		ErrorBuffer);

	MessageBoxW(NULL, Buffer, L"Windows CE Compatbility Layer", MB_OK);
}

BOOL ProgramErrorDialog(LPCWSTR Text, BOOL YesNo)
{
	int box = MessageBoxExW(
		NULL,
		Text,
		L"Windows CE Compatibility Layer",
		(YesNo ? MB_YESNO : MB_YESNOCANCEL),
		MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));

	if (box == IDNO && !YesNo) return TRUE;
	else if ((box == IDCANCEL) || (box == IDNO && YesNo)) exit(1);
	else return FALSE; // yes/close

	return FALSE;
}
