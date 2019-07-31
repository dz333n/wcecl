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

BOOL WINAPI LineTo_WCECL(HDC hdc, int x, int y)
{
	auto result = LineTo(hdc, x, y);
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

COLORREF WINAPI SetPixel_WCECL(HDC hdc, int x, int y, COLORREF color)
{
	auto result = SetPixel(hdc, x, y, color);
	return result;
}

int WINAPI GetDeviceCaps_WCECL(HDC hdc, int nIndex)
{
	auto result = ::GetDeviceCaps(hdc, nIndex);
	return result;
}

HDC WINAPI CreateCompatibleDC_WCECL(HDC hdc)
{
	auto result = ::CreateCompatibleDC(hdc);
	return result;
}

HBITMAP WINAPI CreateCompatibleBitmap_WCECL(HDC hdc, int width, int height)
{
	auto result = ::CreateCompatibleBitmap(hdc, width, height);
	return result;
}

int WINAPI GetClipBox_WCECL(HDC hdc, LPRECT lprect)
{
	auto result = GetClipBox(hdc, lprect);
	return result;
}

BOOL WINAPI DrawFocusRect_WCECL(HDC hDC, CONST RECT * lprc)
{
	auto result = DrawFocusRect(hDC, lprc);
	return result;
}

BOOL WINAPI DeleteDC_WCECL(HDC hdc)
{
	auto result = DeleteDC(hdc);
	return result;
}

HGDIOBJ WINAPI SelectObject_WCECL(HDC hdc, HGDIOBJ h)
{
	auto result = SelectObject(hdc, h);
	return result;
}

int WINAPI FillRect_WCECL(HDC hdc, CONST RECT * lprc, HBRUSH hbr)
{
	auto result = FillRect(hdc, lprc, hbr);
	return result;
}

BOOL WINAPI BitBlt_WCECL(HDC hdc, int x, int y, int cx, int cy, HDC hdcSrc, int x1, int y1, DWORD rop)
{
	auto result = BitBlt(hdc, x, y, cx, cy, hdcSrc, x1, y1, rop);
	return result;
}

// Stubs

