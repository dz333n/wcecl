// winuser_wcecl.cpp : Windows CE/winuser.h
#include "stdafx.h"

// Functions
HDC WINAPI GetDC_WCECL(HWND hwnd)
{
	auto result = ::GetDC(hwnd);
	return result;
}

UINT WINAPI SetTimer_WCECL(
	HWND hwnd,
	UINT idTimer,
	UINT uTimeOut,
	TIMERPROC pfnTimerProc)
{
	// review me
	auto result = ::SetTimer(hwnd, idTimer, uTimeOut, pfnTimerProc);
	return result;
}

HBITMAP WINAPI LoadBitmapW_WCECL(
	HINSTANCE hInstance,
	LPCWSTR lpBitmapName)
{
	auto result = ::LoadBitmapW(hInstance, lpBitmapName);
	return result;
}

HICON WINAPI LoadIconW_WCECL(
	HINSTANCE hInstance,
	LPCWSTR lpIconName)
{
	auto result = ::LoadIconW(NULL, lpIconName);
	return result;
}

HWND WINAPI CreateWindowExW_WCECL(
	DWORD dwExStyle,
	LPCWSTR lpClassName,
	LPCWSTR lpWindowName,
	DWORD dwStyle,
	int X,
	int Y,
	int nWidth,
	int nHeight,
	HWND hWndParent,
	HMENU hMenu,
	HINSTANCE hInstance,
	LPVOID lpParam)
{
	auto result = ::CreateWindowExW(
		dwExStyle,
		lpClassName,
		lpWindowName,
		dwStyle,
		X,
		Y,
		nWidth,
		nHeight,
		hWndParent,
		hMenu,
		hInstance,
		lpParam);

	if (w32err(result == NULL))
	{
		auto win32error = GetLastError();
		DebugBreak();
	}

	return result;
}

HWND WINAPI FindWindowW_WCECL(
	LPCWSTR lpClassName,
	LPCWSTR lpWindowName)
{
	auto result = ::FindWindowW(lpClassName, lpWindowName);
	return result;
}

BOOL WINAPI SetForegroundWindow_WCECL(HWND hWnd)
{
	auto result = ::SetForegroundWindow(hWnd);
	return result;
}

ATOM WINAPI RegisterClassW_WCECL(CONST WNDCLASSW *lpWndClass)
{
	auto result = ::RegisterClassW(lpWndClass);
	return result;
}

BOOL WINAPI KillTimer_WCECL(
	HWND hwnd,
	UINT idEvent)
{
	auto result = ::KillTimer(hwnd, idEvent);
	return result;
}

int WINAPI ReleaseDC_WCECL(
	HWND hwnd,
	HDC hdc)
{
	auto result = ::ReleaseDC(hwnd, hdc);
	return result;
}

BOOL WINAPI InvalidateRect_WCECL(
	HWND hwnd,
	LPCRECT prc,
	BOOL fErase)
{
	// Source: https://docs.microsoft.com/en-us/previous-versions/windows/embedded/ms909857(v%3Dmsdn.10)
	// if hWnd == NULL function must do nothing and return false;

	if (hwnd == NULL)
		return FALSE;
	else
	{
		auto result = ::InvalidateRect(hwnd, prc, fErase);
		return result;
	}
}

HCURSOR WINAPI LoadCursorW_WCECL(
	HINSTANCE hInstance,
	LPCWSTR lpCursorName)
{
	// This functions was replaced by LoadImage, so
	auto result = (HCURSOR)::LoadImageW(NULL, lpCursorName, IMAGE_CURSOR, 0, 0, LR_SHARED);
	return result;
}

// Stubs
Stub(GetGestureInfo);
