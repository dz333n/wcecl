// winuser_wcecl.cpp : Windows CE/winuser.h

#include "stdafx.h"
#include "winuser_wcecl.h"

#define OK_BUTTON_UNIMPLEMENTED

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

BOOL WINAPI ReleaseCapture_WCECL()
{
	auto result = ReleaseCapture();
	return result;
}

BOOL WINAPI DestroyWindow_WCECL(HWND hwnd)
{
	auto result = DestroyWindow(hwnd);
	return result;
}

HDC WINAPI BeginPaint_WCECL(
	HWND hwnd,
	LPPAINTSTRUCT pps)
{
	auto result = BeginPaint(hwnd, pps);
	return result;
}

BOOL WINAPI EndPaint_WCECL(
	HWND hwnd,
	LPPAINTSTRUCT pps)
{
	auto result = EndPaint(hwnd, pps);
	return result;
}

BOOL WINAPI TranslateMessage_WCECL(CONST MSG   *pMsg)
{
	auto result = TranslateMessage(pMsg);
	return result;
}

BOOL WINAPI IsDialogMessageW_WCECL(
	HWND hDlg,
	LPMSG lpMsg)
{
	auto result = IsDialogMessageW(hDlg, lpMsg);
	return result;
}

BOOL WINAPI GetMessageW_WCECL(
	LPMSG lpMsg,
	HWND hWnd,
	UINT wMsgFilterMin,
	UINT wMsgFilterMax)
{
	auto result = GetMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
	return result;
}

VOID WINAPI PostQuitMessage_WCECL(int nExitCode)
{
	PostQuitMessage(nExitCode);
}

HWND WINAPI SetCapture_WCECL(HWND hWnd)
{
	auto result = SetCapture(hWnd);
	return result;
}

BOOL WINAPI GetClientRect_WCECL(
	HWND hwnd,
	LPRECT prc)
{
	auto result = GetClientRect(hwnd, prc);
	return result;
}

HDWP WINAPI BeginDeferWindowPos_WCECL(int nNumWindows)
{
	auto result = BeginDeferWindowPos(nNumWindows);
	return result;
}

HDWP WINAPI DeferWindowPos_WCECL(
	HDWP hWinPosInfo,
	HWND hWnd,
	HWND hWndInsertAfter,
	int x,
	int y,
	int cx,
	int cy,
	UINT uFlags)
{
	auto result = DeferWindowPos(
		hWinPosInfo,
		hWnd,
		hWndInsertAfter,
		x,
		y,
		cx,
		cy,
		uFlags);
	return result;
}


BOOL WINAPI EndDeferWindowPos_WCECL(HDWP hWinPosInfo)
{
	auto result = EndDeferWindowPos(hWinPosInfo);
	return result;
}

DWORD CeWsExToWin(DWORD dwExStyle)
{
	DWORD result = dwExStyle;

	result &= ~WINCE_WS_EX_CAPTIONOKBTN;
	result &= ~WINCE_WS_EX_NODRAG;
	result &= ~WINCE_WS_EX_ABOVESTARTUP;
	result &= ~WINCE_WS_EX_INK;
	result &= ~WINCE_WS_EX_NOANIMATION;

	return result;
}

DWORD CeWsToWin(DWORD dwStyle)
{
	DWORD result = dwStyle;
	return result;
}

VOID CreateWindowCaptionOKButton(HINSTANCE hInstance, HWND hwnd)
{
#ifndef OK_BUTTON_UNIMPLEMENTED
	// Create window
	HWND okHwnd = CreateWindowExW(0, L"BUTTON", L"OK", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 0, 25, 25, hwnd, NULL, hInstance, NULL);

	Assert32Failed(!okHwnd, CreateWindowCaptionOKButton);
#else
	ActuallyAssert(TRUE == FALSE, L"Caption OK Button is not implemented yet.", FALSE);
#endif
}

VOID CheckWsEx(HINSTANCE hInstance, HWND hwnd, DWORD dwExStyle)
{
	if (dwExStyle & WINCE_WS_EX_CAPTIONOKBTN)
	{
		CreateWindowCaptionOKButton(hInstance, hwnd);
	}
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
	DWORD ex = CeWsExToWin(dwExStyle);
	DWORD style = CeWsToWin(dwStyle);

	auto result = ::CreateWindowExW(
		ex,
		lpClassName,
		lpWindowName,
		style,
		X,
		Y,
		nWidth,
		nHeight,
		hWndParent,
		hMenu,
		hInstance,
		lpParam);

	Assert32Failed(result == NULL, CreateWindowExW_WCECL);

	if (result != NULL)
	{
		CheckWsEx(hInstance, result, dwExStyle);
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

LRESULT WINAPI DefWindowProcW_WCECL(
	HWND hWnd,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam)
{
	auto result = DefWindowProcW(hWnd, Msg, wParam, lParam);
	return result;
}

ATOM WINAPI RegisterClassW_WCECL(CONST WNDCLASSW_WCECL *lpWndClass)
{
	WNDCLASSW wndClass = { };

	wndClass.style = lpWndClass->style;
	wndClass.lpfnWndProc = lpWndClass->lpfnWndProc;
	wndClass.cbClsExtra = lpWndClass->cbClsExtra;
	wndClass.cbWndExtra = lpWndClass->cbWndExtra;
	wndClass.hInstance = lpWndClass->hInstance;
	wndClass.hIcon = lpWndClass->hIcon; // LoadIconW(0, IDI_WINLOGO); //
	wndClass.hCursor = lpWndClass->hCursor;// LoadCursorW(0, IDC_ARROW); //
	wndClass.hbrBackground = lpWndClass->hbrBackground;
	wndClass.lpszMenuName = lpWndClass->lpszMenuName;
	wndClass.lpszClassName = lpWndClass->lpszClassName;

	auto result = ::RegisterClassW(&wndClass);

	Assert32Failed(!result, RegisterClassW_WCECL);

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

BOOL WINAPI ValidateRect_WCECL(
	HWND hWnd,
	CONST RECT *lpRect)
{
	auto result = ValidateRect(hWnd, lpRect);
	return result;
}

BOOL WINAPI PeekMessageW_WCECL(
	PMSG pMsg,
	HWND hWnd,
	UINT wMsgFilterMin,
	UINT wMsgFilterMax,
	UINT wRemoveMsg)
{
	auto result = PeekMessageW(pMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
	return result;
}

BOOL WINAPI PtInRect_WCECL(
	CONST RECT *lprc,
	POINT pt)
{
	auto result = PtInRect(lprc, pt);
	return result;
}

SHORT WINAPI GetKeyState_WCECL(int nVirtKey)
{
	auto result = GetKeyState(nVirtKey);
	return result;
}

BOOL WINAPI IntersectRect_WCECL(
	LPRECT lprcDst,
	CONST RECT *lprcSrc1,
	CONST RECT *lprcSrc2)
{
	auto result = IntersectRect(lprcDst, lprcSrc1, lprcSrc2);
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
	INT nCmdShowActual = 0;

	switch (nCmdShow)
	{
		case WINCE_SW_SHOWMAXIMIZED:
			nCmdShowActual = SW_SHOWMAXIMIZED;
			break;
		case WINCE_SW_MAXIMIZE:
			nCmdShowActual = SW_MAXIMIZE;
			break;
		case WINCE_SW_RESTORE:
			nCmdShowActual = SW_RESTORE;
			break;
		default:
			nCmdShowActual = nCmdShow;
			break;
	}

	if (nCmdShowActual >= 12)
		nCmdShowActual = SW_SHOWMAXIMIZED;

	auto result = ShowWindow(hwnd, nCmdShowActual);
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
	DLGTEMPLATE *dlgTemplate = (DLGTEMPLATE*)malloc(sizeof(DLGTEMPLATE));
	RtlZeroMemory(dlgTemplate, sizeof(DLGTEMPLATE));

	DWORD style = CeWsToWin(lpTemplate->style);
	DWORD exstyle = CeWsExToWin(lpTemplate->dwExtendedStyle);

	dlgTemplate->cdit = lpTemplate->cdit;
	dlgTemplate->cx = lpTemplate->cx;
	dlgTemplate->cy = lpTemplate->cy;
	dlgTemplate->x = lpTemplate->x;
	dlgTemplate->y = lpTemplate->y;
	dlgTemplate->style = style;
	dlgTemplate->dwExtendedStyle = exstyle;

	AssertFailed(dlgTemplate->style != style, CreateDialogIndirectParamW_WCECL);
	AssertFailed(dlgTemplate->dwExtendedStyle != exstyle, CreateDialogIndirectParamW_WCECL);

	auto result = CreateDialogIndirectParamW(NULL, /*dlgTemplate*/ lpTemplate, hWndParent, lpDialogFunc, dwInitParam);

	Assert32Failed(!result, CreateDialogIndirectParamW_WCECL);

	if (result != NULL)
	{
		CheckWsEx(hInstance, result, lpTemplate->dwExtendedStyle);
	}

	return result;
}

int WINAPI DialogBoxIndirectParamW_WCECL(
	HINSTANCE hInstance,
	LPCDLGTEMPLATEW hDialogTemplate,
	HWND hWndParent,
	DLGPROC lpDialogFunc,
	LPARAM dwInitParam)
{
#ifndef OK_BUTTON_UNIMPLEMENTED
	HWND hwnd = CreateDialogIndirectParamW_WCECL(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam);
	ShowWindow(hwnd, SW_SHOW); // FIX ME: should be a dialog
	return 0;
#else
	auto result = DialogBoxIndirectParamW(
		hInstance,
		hDialogTemplate,
		hWndParent,
		lpDialogFunc,
		dwInitParam);
	return result;
#endif
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
