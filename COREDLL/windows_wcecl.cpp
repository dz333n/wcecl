// windows_wcecl.cpp : wce/windows.h functions
#include "stdafx.h"

int EnumFontFamiliesW_WCECL(
	HDC           hdc,
	LPCWSTR       lpLogfont,
	FONTENUMPROCW lpProc,
	LPARAM        lParam)
{
	auto result = ::EnumFontFamilies(hdc, lpLogfont, lpProc, lParam);
	return result;
}

Stub(GetMouseMovePoints_WCECL);
