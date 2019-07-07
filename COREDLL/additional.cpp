// additional.cpp : additonal WCECL functions
#include "stdafx.h"

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
