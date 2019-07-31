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
	/*else
	{
		ShowWindow(result, SW_SHOWDEFAULT);
		UpdateWindow(result);
		MSG Msg;
		while (GetMessage(&Msg, NULL, 0, 0) > 0)
		{
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
	}*/

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

LRESULT
WINAPI
DefWindowProcW_WCECL(
	HWND hWnd,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam)
{
	auto result = DefWindowProcW(hWnd, Msg, wParam, lParam);
	return result;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

ATOM WINAPI RegisterClassW_WCECL(CONST WNDCLASSW_WCECL *lpWndClass)
{
	WNDCLASSW wndClass = { };

	wndClass.style = 0;// lpWndClass->style; // may be different, review!
	wndClass.lpfnWndProc = lpWndClass->lpfnWndProc; (WNDPROC)WndProc; // TEMPORARY -- FIXME -- CreateWindowEx fails with correct WndProc
	wndClass.cbClsExtra = lpWndClass->cbClsExtra;
	wndClass.cbWndExtra = lpWndClass->cbWndExtra;
	wndClass.hInstance = lpWndClass->hInstance;
	wndClass.hIcon = lpWndClass->hIcon; // LoadIconW(0, IDI_WINLOGO); // 
	wndClass.hCursor = lpWndClass->hCursor;// LoadCursorW(0, IDC_ARROW); // 
	wndClass.hbrBackground = lpWndClass->hbrBackground;
	wndClass.lpszMenuName = lpWndClass->lpszMenuName;
	wndClass.lpszClassName = lpWndClass->lpszClassName;

	auto result = ::RegisterClass(&wndClass);

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

LRESULT
WINAPI
DefDlgProcW_WCECL(
	HWND hDlg,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam)
{
	auto result = DefDlgProcW(hDlg, Msg, wParam, lParam);
	return result;
}

BOOL WINAPI GetWindowRect_WCECL(
	HWND hwnd,
	LPRECT prc)
{
	auto result = GetWindowRect(hwnd, prc);
	return result;
}

BOOL WINAPI IsWindowVisible_WCECL(HWND hWnd)
{
	auto result = IsWindowVisible(hWnd);
	return result;
}

LONG WINAPI DispatchMessageW_WCECL(CONST MSG *lpMsg)
{
	auto result = DispatchMessageW(lpMsg);
	return result;
}

BOOL WINAPI PostMessageW_WCECL(
	HWND hWnd,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam)
{
	auto result = PostMessageW(hWnd, Msg, wParam, lParam);
	return result;
}

BOOL WINAPI SetRect_WCECL(
	LPRECT lprc,
	int xLeft,
	int yTop,
	int xRight,
	int yBottom)
{
	auto result = SetRect(lprc, xLeft, yTop, xRight, yBottom);
	return result;
}

BOOL WINAPI CopyRect_WCECL(
	LPRECT lprcDst,
	CONST RECT *lprcSrc)
{
	auto result = CopyRect(lprcDst, lprcSrc);
	return result;
}

BOOL WINAPI InflateRect_WCECL(
	LPRECT lprc,
	int dx,
	int dy)
{
	auto result = InflateRect(lprc, dx, dy);
	return result;
}

BOOL WINAPI EnableWindow_WCECL(
	HWND hWnd,
	BOOL bEnable)
{
	auto result = EnableWindow(hWnd, bEnable);
	return result;
}

BOOL WINAPI IsWindowEnabled_WCECL(HWND hWnd)
{
	auto result = IsWindowEnabled(hWnd);
	return result;
}

int WINAPI MessageBoxW_WCECL(
	HWND hWnd,
	LPCWSTR lpText,
	LPCWSTR lpCaption,
	UINT uType)
{
	auto result = MessageBoxW(hWnd, lpText, lpCaption, uType);
	return result;
}

BOOL WINAPI EndDialog_WCECL(
	HWND hDlg,
	int nResult)
{
	auto result = EndDialog(hDlg, nResult);
	return result;
}

BOOL WINAPI CheckRadioButton_WCECL(
	HWND hDlg,
	int nIDFirstButton,
	int nIDLastButton,
	int nIDCheckButton)
{
	auto result = CheckRadioButton(hDlg, nIDFirstButton, nIDLastButton, nIDCheckButton);
	return result;
}

BOOL WINAPI DestroyWindow_WCECL(HWND hwnd)
{
	auto result = DestroyWindow(hwnd);
	return result;
}

UINT WINAPI GetDoubleClickTime_WCECL()
{
	auto result = GetDoubleClickTime();
	return result;
}

BOOL WINAPI SetDlgItemTextW_WCECL(
	HWND hDlg,
	int nIDDlgItem,
	LPCWSTR lpString)
{
	auto result = SetDlgItemTextW(hDlg, nIDDlgItem, lpString);
	return result;
}

BOOL WINAPI ShowWindow_WCECL(
	HWND hwnd,
	INT nCmdShow)
{
	auto result = ShowWindow(hwnd, nCmdShow);
	return result;
}

BOOL WINAPI UpdateWindow_WCECL(HWND hwnd)
{
	auto result = UpdateWindow(hwnd);
	return result;
}

BOOL WINAPI SetWindowPos_WCECL(
	HWND hwnd,
	HWND hwndInsertAfter,
	int x,
	int y,
	int dx,
	int dy,
	UINT fuFlags)
{
	auto result = SetWindowPos(hwnd, hwndInsertAfter, x, y, dx, dy, fuFlags);
	return result;
}

HWND WINAPI CreateDialogIndirectParamW_WCECL(
	HINSTANCE hInstance,
	LPCDLGTEMPLATEW lpTemplate,
	HWND hWndParent,
	DLGPROC lpDialogFunc,
	LPARAM dwInitParam)
{
	auto result = CreateDialogIndirectParamW(hInstance, lpTemplate, hWndParent, lpDialogFunc, dwInitParam);
	return result;
}

HWND WINAPI SetFocus_WCECL(HWND hWnd)
{
	auto result = SetFocus(hWnd);
	return result;
}

LRESULT WINAPI SendMessageW_WCECL(
	HWND hWnd,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam)
{
	auto result = SendMessageW(hWnd, Msg, wParam, lParam);
	return result;
}

HWND WINAPI GetDlgItem_WCECL(
	HWND hDlg,
	int  iCtrlID)
{
	auto result = GetDlgItem(hDlg, iCtrlID);
	return result;
}

HANDLE WINAPI LoadImageW_WCECL(
	HINSTANCE hInstance,
	LPCWSTR name,
	UINT type,
	int cx,
	int cy,
	UINT fuLoad)
{
	auto result = LoadImageW(hInstance, name, type, cx, cy, fuLoad);
	return result;
}

// Stubs
Stub(GetGestureInfo);
