// wingdi_wcecl.cpp : wce/wingdi.h functions
#include "stdafx.h"

// Functions
int WINAPI GetObjectW_WCECL(
	HGDIOBJ hgdiobj,
	int cbBuffer,
	LPVOID lpvObject)
{
	// source: https://docs.microsoft.com/en-us/previous-versions/windows/embedded/ee506071(v%3dwinembedded.60)
	auto result = ::GetObjectW(hgdiobj, cbBuffer, lpvObject);
	return result;
}

HGDIOBJ WINAPI GetStockObject_WCECL(int i) 
{
	auto result = ::GetStockObject(i);
	return result;
}

BOOL WINAPI DeleteObject_WCECL(HGDIOBJ hObject)
{
	auto result = ::DeleteObject(hObject);
	return result;
}

HBRUSH WINAPI CreateSolidBrush_WCECL(COLORREF crColor)
{
	auto result = ::CreateSolidBrush(crColor);
	return result;
}

int WINAPI GetDeviceCaps_WCECL(HDC hdc, int nIndex)
{
	auto result = ::GetDeviceCaps(hdc, nIndex);
	return result;
}

// Stubs

