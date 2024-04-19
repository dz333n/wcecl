// winuser_wcecl.cpp : Windows CE/winuser.h

#include "stdafx.h"
#include "winuser_wcecl.h"
#include <map>
#include <assert.h>

#define OK_BUTTON_UNIMPLEMENTED

// Functions
UINT EnumClipboardFormats_WCECL(
	UINT format)
{
	auto result = ::EnumClipboardFormats(format);
	return result;
}

BOOL EmptyClipboard_WCECL()
{
	auto result = ::EmptyClipboard();
	return result;
}

UINT RegisterClipboardFormat_WCECL(LPCWSTR lpszFormat)
{
	auto result = ::RegisterClipboardFormat(lpszFormat);
	return result;
}

BOOL IsClipboardFormatAvailable_WCECL(UINT format)
{
	auto result = ::IsClipboardFormatAvailable(format);
	return result;
}

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

/* Checks if the parameter Param is not in memory occupied by the output 
   parameter outParam. */
template<typename T1, typename T2>
static BOOL CheckOutParam(const T1* outParam, const T2& Param)
{
	SIZE_T outParamSize = sizeof(T1);
	ULONG_PTR outParamPtr = (ULONG_PTR)outParam;
	ULONG_PTR paramPtr = (ULONG_PTR)&Param;

	if (paramPtr >= outParamPtr && paramPtr < outParamPtr + outParamSize)
	{
		assert(FALSE);
	}

	paramPtr += sizeof(T2) - 1;
	if (paramPtr >= outParamPtr && paramPtr < outParamPtr + outParamSize)
	{
		assert(FALSE);
	}

	return TRUE;
}


BOOL WINAPI GetMessageW_WCECL(
	LPMSG lpMsg,
	HWND hWnd,
	UINT wMsgFilterMin,
	UINT wMsgFilterMax)
{
	assert(CheckOutParam(lpMsg, lpMsg));
	assert(CheckOutParam(lpMsg, hWnd));
	assert(CheckOutParam(lpMsg, wMsgFilterMin));
	assert(CheckOutParam(lpMsg, wMsgFilterMax));

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

static std::map<std::wstring, WNDPROCWCE> WrappedWndProcs;

BOOL GetWstringClassName(HWND hWnd, std::wstring& result)
{
	WCHAR wszBuffer[MAX_PATH];
	if (GetClassNameW(hWnd, wszBuffer, MAX_PATH) != 0)
	{
		result = std::wstring(wszBuffer);
		return TRUE;
	}

	return FALSE;
}

LRESULT __stdcall WndProcWrapper(
	HWND hWnd, 
	UINT uMessage, 
	WPARAM wParam,
	LPARAM lParam)
{
	std::wstring className;

	if (GetWstringClassName(hWnd, className) == FALSE)
	{
		/* Perhaps the program should crash if an invalid classname somehow 
		   gets to here? */
		return DefWindowProcW(hWnd, uMessage, wParam, lParam);
	}

	if (WrappedWndProcs.find(className) != WrappedWndProcs.end())
	{
		WNDPROCWCE lpfnWceWndProc = WrappedWndProcs.at(className);
		return lpfnWceWndProc(hWnd, uMessage, wParam, lParam);
	}
	else
	{
		Assert32(TRUE);
	}

	return DefWindowProcW(hWnd, uMessage, wParam, lParam);
}

LRESULT __cdecl WndProcReverseWrapper(
	HWND hWnd,
	UINT uMessage,
	WPARAM wParam,
	LPARAM lParam)
{
	WNDPROC win32WndProc = (WNDPROC)GetWindowLongPtrW(hWnd, GWLP_WNDPROC);
	return CallWindowProcW(win32WndProc, hWnd, uMessage, wParam, lParam);
}

BOOL WINAPI GetClassInfoW_WCECL(HINSTANCE hInstance, LPCWSTR lpClassName, PWNDCLASSW_WCECL lpWceClass)
{
	WNDCLASSW win32class;
	BOOL result;

	result = GetClassInfoW(hInstance, lpClassName, &win32class);
	lpWceClass->style = win32class.style;
	if (WrappedWndProcs.count(std::wstring(win32class.lpszClassName)) > 0)
	{
		lpWceClass->lpfnWndProc = WrappedWndProcs.at(std::wstring(win32class.lpszClassName));
	}
	else
	{
		lpWceClass->lpfnWndProc = WndProcReverseWrapper;
	}
	lpWceClass->cbClsExtra = win32class.cbClsExtra;
	lpWceClass->cbWndExtra = win32class.cbWndExtra;
	lpWceClass->hInstance = win32class.hInstance;
	lpWceClass->hIcon = win32class.hIcon;
	lpWceClass->hCursor = win32class.hCursor;
	lpWceClass->hbrBackground = win32class.hbrBackground;
	lpWceClass->lpszMenuName = win32class.lpszMenuName;
	lpWceClass->lpszClassName = win32class.lpszClassName;

	return result;
}

WNDPROC WceclWrapWndProc(LPCWSTR wszClassName, WNDPROCWCE lpfnWceWndProc)
{
	if (WrappedWndProcs.count(std::wstring(wszClassName)) > 0)
	{
		return NULL;
	}

	WrappedWndProcs[wszClassName] = lpfnWceWndProc;
	return WndProcWrapper;
}

ATOM WINAPI RegisterClassW_WCECL(CONST WNDCLASSW_WCECL *lpWndClass)
{
	WNDCLASSW wndClass = { };

	wndClass.style = lpWndClass->style;
	wndClass.lpfnWndProc = WceclWrapWndProc(lpWndClass->lpszClassName, lpWndClass->lpfnWndProc);
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
	if (Msg == WM_USER + 81)
	{
		/* TODO */
		//Msg = TB_SETTOOLTIPS;
		return 0;
	}

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

BOOL WINAPI EnableMenuItem_WCECL(HMENU hMenu, UINT uIDEnableItem, UINT uEnable)
{
	return EnableMenuItem(hMenu, uIDEnableItem, uEnable);
}

HACCEL WINAPI LoadAcceleratorsW_WCECL(HINSTANCE hInstance, LPCWSTR lpTableName)
{
	return LoadAcceleratorsW(hInstance, lpTableName);
}

int WINAPI TranslateAcceleratorW_WCECL(HWND hWnd, HACCEL hAccelTable, LPMSG lpMsg)
{
	return TranslateAcceleratorW(hWnd, hAccelTable, lpMsg);
}

LPWSTR WINAPI CharUpperW_WCECL(LPWSTR lpString)
{
	return CharUpperW(lpString);
}

BOOL WINAPI CheckMenuRadioItem_WCECL(
	HMENU hMenu,
	UINT first,
	UINT last,
	UINT check,
	UINT flags)
{
	return CheckMenuRadioItem(hMenu, first, last, check, flags);
}


BOOL WINAPI UnregisterClassW_WCECL(LPCWSTR wszClassName, HINSTANCE hInstance)
{
	return UnregisterClassW(wszClassName, hInstance);
}

BOOL WINAPI AdjustWindowRectEx_WCECL(
	LPRECT lpRect,
	DWORD dwStyle,
	BOOL bMenu,
	DWORD dwExStyle)
{
	return AdjustWindowRectEx(lpRect, dwStyle, bMenu, dwExStyle);
}

BOOL WINAPI AppendMenuW_WCECL(
	HMENU hMenu,
	UINT uFlags,
	ULONG_PTR uIDNewItem,
	LPCWSTR lpNewItem)
{
	return AppendMenuW(hMenu, uFlags, uIDNewItem, lpNewItem);
}

BOOL WINAPI UnionRect_WCECL(LPRECT lprcDst, const RECT* lpSrc1, const RECT* lpSrc2)
{
	return UnionRect(lprcDst, lpSrc1, lpSrc2);
}


BOOL WINAPI TransparentBlt_WCECL(
	HDC hdcDest,
	int xoriginDest,
	int yoriginDest,
	int wDest,
	int hDest,
	HDC hdcSrc,
	int xoriginSrc,
	int yoriginSrc,
	int wSrc,
	int hSrc,
	UINT crTransparent)
{
	return TransparentBlt(
		hdcDest,
		xoriginDest,
		yoriginDest,
		wDest,
		hDest,
		hdcSrc,
		xoriginSrc,
		yoriginSrc,
		wSrc,
		hSrc,
		crTransparent);
}

BOOL WINAPI SystemParametersInfoW_WCECL(
	UINT uiAction,
	UINT uiParam,
	PVOID pvParam,
	UINT fWinIni)
{
	return SystemParametersInfoW(uiAction, uiParam, pvParam, fWinIni);
}


LONG WINAPI SetWindowLongW_WCECL(HWND hWnd, int nIndex, LONG dwNewLong)
{
	if (nIndex == GWL_WNDPROC)
	{
		Assert32Ex(TRUE, L"Unimplemented");
	}
	return SetWindowLongW(hWnd, nIndex, dwNewLong);
}

BOOL WINAPI SetWindowTextW_WCECL(HWND hWnd, LPCWSTR lpString)
{
	return SetWindowTextW(hWnd, lpString);
}

BOOL WINAPI ShowCaret_WCECL(HWND hWnd)
{
	return ShowCaret(hWnd);
}

BOOL WINAPI SetScrollRange_WCECL(
	HWND hWnd,
	int nBar,
	int nMinPos,
	int nMaxPos,
	BOOL bRedraw)
{
	return SetScrollRange(hWnd, nBar, nMinPos, nMaxPos, bRedraw);
}

int WINAPI ClientToScreen_WCECL(HWND hWnd, LPPOINT lpPoint)
{
	return ClientToScreen(hWnd, lpPoint);
}

BOOL WINAPI ScreenToClient_WCECL(HWND hWnd, LPPOINT lpPoint)
{
	return ScreenToClient(hWnd, lpPoint);
}

BOOL WINAPI CloseClipboard_WCECL()
{
	return CloseClipboard();
}

BOOL WINAPI OpenClipboard_WCECL(HWND hWndNewOrder)
{
	return OpenClipboard(hWndNewOrder);
}

SHORT WINAPI GetAsyncKeyState_WCECL(int key)
{
	return GetAsyncKeyState(key);
}

HANDLE WINAPI GetClipboardData_WCECL(UINT uFormat)
{
	return GetClipboardData(uFormat);
}

BOOL WINAPI GetClipCursor_WCECL(LPRECT lpRect)
{
	return GetClipCursor(lpRect);
}

int WINAPI GetDlgCtrlID_WCECL(HWND hWnd)
{
	return GetDlgCtrlID(hWnd);
}

HWND WINAPI GetFocus_WCECL()
{
	return GetFocus();
}

HWND WINAPI GetForegroundWindow_WCECL()
{
	return GetForegroundWindow();
}

BOOL WINAPI GetUpdateRect_WCECL(HWND hWnd, LPRECT lpRect, BOOL bErase)
{
	return GetUpdateRect(hWnd, lpRect, bErase);
}

int WINAPI GetUpdateRgn_WCECL(HWND hWnd, HRGN hRgn, BOOL bErase)
{
	return GetUpdateRgn(hWnd, hRgn, bErase);
}

HWND WINAPI GetWindow_WCECL(HWND hWnd, UINT uCmd)
{
	return GetWindow(hWnd, uCmd);
}

LONG WINAPI GetWindowLongW_WCECL(HWND hWnd, int nIndex)
{
	return GetWindowLongW(hWnd, nIndex);
}

int WINAPI GetWindowTextLengthW_WCECL(HWND hWnd)
{
	return GetWindowTextLengthW(hWnd);
}

int WINAPI GetWindowTextW_WCECL(HWND hWnd, LPWSTR lpString, int nMaxCount)
{
	return GetWindowTextW(hWnd, lpString, nMaxCount);
}

BOOL WINAPI HideCaret_WCECL(HWND hWnd)
{
	return HideCaret(hWnd);
}

HANDLE WINAPI GetPropW_WCECL(HWND hWnd, LPCWSTR lpString)
{
	return GetPropW(hWnd, lpString);
}

BOOL WINAPI GetScrollInfo_WCECL(HWND hWnd, int nBar, LPSCROLLINFO lpsi)
{
	return GetScrollInfo(hWnd, nBar, lpsi);
}

DWORD WINAPI GetMessagePos_WCECL()
{
	return GetMessagePos();
}

HWND WINAPI GetNextDlgTabItem_WCECL(HWND hDlg, HWND hCtl, BOOL bPrevious)
{
	return GetNextDlgTabItem(hDlg, hCtl, bPrevious);
}

HWND WINAPI GetParent_WCECL(HWND hWnd)
{
	return GetParent(hWnd);
}

BOOL WINAPI MessageBeep_WCECL(UINT uType)
{
	return MessageBeep(uType);
}

HMONITOR WINAPI MonitorFromPoint_WCECL(POINT pt, DWORD dwFlags)
{
	return MonitorFromPoint(pt, dwFlags);
}

int WINAPI MoveWindow_WCECL(
	HWND hWnd,
	int x,
	int y,
	int nWidth,
	int nHeight,
	BOOL bRepaint)
{
	return MoveWindow(hWnd, x, y, nWidth, nHeight, bRepaint);
}

DWORD WINAPI MsgWaitForMultipleObjectsEx_WCECL(
	DWORD nCount,
	const HANDLE* pHandles,
	DWORD dwMilliseconds,
	DWORD dwWakeMask,
	DWORD dwFlags)
{
	return MsgWaitForMultipleObjectsEx(
		nCount,
		pHandles,
		dwMilliseconds,
		dwWakeMask,
		dwFlags);
}

BOOL WINAPI OffsetRect_WCECL(LPRECT lpRect, int x, int y)
{
	return OffsetRect(lpRect, x, y);
}

BOOL WINAPI RedrawWindow_WCECL(
	HWND hWnd,
	const RECT* lprcUpdate,
	HRGN hrgnUpdate,
	UINT flags)
{
	return RedrawWindow(hWnd, lprcUpdate, hrgnUpdate, flags);
}

int WINAPI ScrollWindowEx_WCECL(
	HWND hWnd,
	int dx,
	int dy,
	const RECT* prcScroll,
	const RECT* prcClip,
	HRGN hrgnUpdate,
	LPRECT prcUpdate,
	UINT flags)
{
	return ScrollWindowEx(
		hWnd,
		dx,
		dy,
		prcScroll,
		prcClip,
		hrgnUpdate,
		prcUpdate,
		flags);
}

LRESULT WINAPI SendDlgItemMessageW_WCECL(
	HWND hDlg,
	int nIDDlgItem,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam)
{
	return SendDlgItemMessageW(
		hDlg,
		nIDDlgItem,
		Msg,
		wParam,
		lParam);
}

HCURSOR WINAPI SetCursor_WCECL(HCURSOR hCursor)
{
	return SetCursor(hCursor);
}

BOOL WINAPI SendNotifyMessageW_WCECL(
	HWND hWnd,
	UINT uMessage,
	WPARAM wParam,
	LPARAM lParam)
{
	return SendNotifyMessageW(hWnd, uMessage, wParam, lParam);
}

// Stubs
Stub(GetGestureInfo);
