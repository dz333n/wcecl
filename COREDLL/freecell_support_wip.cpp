#include "stdafx.h"
#include "winuser_wcecl.h"

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

HBITMAP WINAPI CreateBitmap_WCECL(
    int nWidth, 
    int nHeight, 
    UINT nPlanes, 
    UINT nBitcount, 
    const void* lpBits)
{
    return CreateBitmap(nWidth, nHeight, nPlanes, nBitcount, lpBits);
}

HANDLE WINAPI CreateFileMappingW_WCECL(
    HANDLE hFile,
    LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    DWORD flProtect,
    DWORD dwMaximumSizeHigh,
    DWORD dwMaximumSizeLow,
    LPCWSTR lpName)
{
    return CreateFileMappingW(
        hFile, 
        lpFileMappingAttributes, 
        flProtect, 
        dwMaximumSizeHigh,
        dwMaximumSizeLow,
        lpName);
}

HPEN WINAPI CreatePen_WCECL(int iStyle, int cWidth, COLORREF colorRef)
{
    return CreatePen(iStyle, cWidth, colorRef);
}

HPEN WINAPI CreatePenIndirect_WCECL(const LOGPEN* plPen)
{
    return CreatePenIndirect(plPen);
}

HRGN WINAPI CreateRectRgn_WCECL(int x1, int y1, int x2, int y2)
{
    return CreateRectRgn(x1, y1, x2, y2);
}

HRGN WINAPI CreateRectRgnIndirect_WCECL(const RECT* lpRect)
{
    return CreateRectRgnIndirect(lpRect);
}

void WINAPI DeleteCriticalSection_WCECL(LPCRITICAL_SECTION pCriticalSection)
{
    DeleteCriticalSection(pCriticalSection);
}

void WINAPI EnterCriticalSection_WCECL(LPCRITICAL_SECTION pCriticalSection)
{
    EnterCriticalSection(pCriticalSection);
}

void WINAPI LeaveCriticalSection_WCECL(LPCRITICAL_SECTION pCriticalSection)
{
    LeaveCriticalSection(pCriticalSection);
}

void WINAPI InitializeCriticalSection_WCECL(LPCRITICAL_SECTION pCriticalSection)
{
    InitializeCriticalSection(pCriticalSection);
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

DWORD WINAPI GetFileSize_WCECL(HANDLE hFile, LPDWORD lpFileSizeHigh)
{
    return GetFileSize(hFile, lpFileSizeHigh);
}

HWND WINAPI GetFocus_WCECL()
{
    return GetFocus();
}

HWND WINAPI GetForegroundWindow_WCECL()
{
    return GetForegroundWindow();
}

LANGID WINAPI GetSystemDefaultLangID_WCECL()
{
    return GetSystemDefaultLangID();
}

LCID WINAPI GetSystemDefaultLCID_WCECL()
{
    return GetSystemDefaultLCID();
}

UINT WINAPI GetTextAlign_WCECL(HDC hDc)
{
    return GetTextAlign(hDc);
}

BOOL WINAPI GetTextExtentExPointW_WCECL(
    HDC hDc,
    LPCWSTR lpszString,
    int cchString,
    int nMaxExtent,
    LPINT lpnFit,
    LPINT lpnDx,
    LPSIZE lpSize)
{
    return GetTextExtentExPointW(
        hDc, 
        lpszString,
        cchString,
        nMaxExtent,
        lpnFit,
        lpnDx,
        lpSize);
}

BOOL WINAPI GetTextMetricsW_WCECL(HDC hDc, LPTEXTMETRICW lpTextMetric)
{
    return GetTextMetricsW(hDc, lpTextMetric);
}

BOOL WINAPI GetUpdateRect_WCECL(HWND hWnd, LPRECT lpRect, BOOL bErase)
{
    return GetUpdateRect(hWnd, lpRect, bErase);
}

int WINAPI GetUpdateRgn_WCECL(HWND hWnd, HRGN hRgn, BOOL bErase)
{
    return GetUpdateRgn(hWnd, hRgn, bErase);
}

LCID WINAPI GetUserDefaultLCID_WCECL()
{
    return GetUserDefaultLCID();
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

ATOM WINAPI GlobalAddAtomW_WCECL(LPCWSTR lpString)
{
    return GlobalAddAtomW(lpString);
}

int WINAPI GradientFill_WCECL(
    HDC hdc,
    PTRIVERTEX pVertex,
    ULONG nVertex,
    PVOID pMesh,
    ULONG nMesh,
    ULONG ulMode)
{
    return GradientFill(hdc, pVertex, nVertex, pMesh, nMesh, ulMode);
}

int WINAPI HeapFree_WCECL(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem)
{
    return HeapFree(hHeap, dwFlags, lpMem);
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

BOOL WINAPI GetStringTypeExW_WCECL(
    LCID locale,
    DWORD dwInfoType,
    LPCWCH lpSrcStr,
    int cchSrc,
    LPWORD lpCharType)
{
    return GetStringTypeExW(locale, dwInfoType, lpSrcStr, cchSrc, lpCharType);
}

DWORD WINAPI GetLayout_WCECL(HDC hDc)
{
    return GetLayout(hDc);
}

DWORD WINAPI GetMessagePos_WCECL()
{
    return GetMessagePos();
}

COLORREF WINAPI GetNearestColor_WCECL(HDC hDc, COLORREF color)
{
    return GetNearestColor(hDc, color);
}

HWND WINAPI GetNextDlgTabItem_WCECL(HWND hDlg, HWND hCtl, BOOL bPrevious)
{
    return GetNextDlgTabItem(hDlg, hCtl, bPrevious);
}

int WINAPI GetNumberFormatW_WCECL(
    LCID Locale,
    DWORD dwFlags,
    LPCWSTR lpValue,
    NUMBERFMTW* lpFormat,
    LPWSTR lpNumberStr,
    int cchNumber)
{
    return GetNumberFormatW(
        Locale, 
        dwFlags, 
        lpValue, 
        lpFormat, 
        lpNumberStr,
        cchNumber);
}

HWND WINAPI GetParent_WCECL(HWND hWnd)
{
    return GetParent(hWnd);
}

COLORREF WINAPI GetPixel_WCECL(HDC hDc, int x, int y)
{
    return GetPixel(hDc, x, y);
}

HANDLE WINAPI GetProcessHeap_WCECL()
{
    return GetProcessHeap();
}

HIMC WINAPI ImmAssociateContext_WCECL(HWND hWnd, HIMC hImc)
{
    return ImmAssociateContext(hWnd, hImc);
}

int WINAPI ImmGetCompositionStringW_WCECL(
    HIMC hImc, 
    DWORD dw, 
    LPVOID lpBuf,
    DWORD dwBufLen)
{
    return ImmGetCompositionStringW(hImc, dw, lpBuf, dwBufLen);
}

HIMC WINAPI ImmGetContext_WCECL(HWND hWnd)
{
    return ImmGetContext(hWnd);
}

BOOL WINAPI ImmReleaseContext_WCECL(HWND hWnd, HIMC hImc)
{
    return ImmReleaseContext(hWnd, hImc);
}

int WINAPI IntersectClipRect_WCECL(HDC hDc, int a, int b, int c, int d)
{
    return IntersectClipRect(hDc, a, b, c, d);
}

int WINAPI LCMapStringW_WCECL(
    LCID Locale,
    DWORD dwMapFlags,
    LPCWSTR lpSrcStr,
    int cchSrc,
    LPWSTR lpDestStr,
    int cchDest)
{
    return LCMapStringW(
        Locale, 
        dwMapFlags,
        lpSrcStr,
        cchSrc,
        lpDestStr, 
        cchDest);
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

int WINAPI MulDiv_WCECL(int nNumber, int nNumerator, int nDenominator)
{
    return MulDiv(nNumber, nNumber, nDenominator);
}

BOOL WINAPI OffsetRect_WCECL(LPRECT lpRect, int x, int y)
{
    return OffsetRect(lpRect, x, y);
}

BOOL WINAPI Polygon_WCECL(HDC hDc, const POINT* apt, int cpt)
{
    return Polygon(hDc, apt, cpt);
}

BOOL WINAPI Polyline_WCECL(HDC hDc, const POINT* apt, int cpt)
{
    return Polyline(hDc, apt, cpt);
}

UINT WINAPI RealizePalette_WCECL(HDC hDc)
{
    return RealizePalette(hDc);
}

BOOL WINAPI Rectangle_WCECL(HDC hDc, int left, int top, int right, int bottom)
{
    return Rectangle(hDc, left, top, right, bottom);
}

BOOL WINAPI RedrawWindow_WCECL(
    HWND hWnd,
    const RECT* lprcUpdate,
    HRGN hrgnUpdate,
    UINT flags)
{
    return RedrawWindow(hWnd, lprcUpdate, hrgnUpdate, flags);
}

BOOL WINAPI RestoreDC_WCECL(HDC hDc, int nSavedDc)
{
    return RestoreDC(hDc, nSavedDc);
}

int WINAPI SaveDC_WCECL(HDC hDc)
{
    return SaveDC(hDc);
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

int WINAPI SelectClipRgn_WCECL(HDC hDc, HRGN hRgn)
{
    return SelectClipRgn(hDc, hRgn);
}

HPALETTE WINAPI SelectPalette_WCECL(HDC hDc, HPALETTE hPalette, BOOL bForceBkd)
{
    return SelectPalette(hDc, hPalette, bForceBkd);
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

BOOL WINAPI SendNotifyMessageW_WCECL(
    HWND hWnd,
    UINT uMessage,
    WPARAM wParam,
    LPARAM lParam)
{
    return SendNotifyMessageW(hWnd, uMessage, wParam, lParam);
}

BOOL WINAPI SetBrushOrgEx_WCECL(HDC hDc, int x, int y, LPPOINT lppt)
{
    return SetBrushOrgEx(hDc, x, y, lppt);
}

HCURSOR WINAPI SetCursor_WCECL(HCURSOR hCursor)
{
    return SetCursor(hCursor);
}

DWORD WINAPI SetLayout_WCECL(HDC hDc, DWORD l)
{
    return SetLayout(hDc, l);
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

UINT WINAPI SetTextAlign_WCECL(HDC hDc, UINT align)
{
    return SetTextAlign(hDc, align);
}

BOOL WINAPI SetViewportOrgEx_WCECL(HDC hDc, int x, int y, LPPOINT lpPoint)
{
    return SetViewportOrgEx(hDc, x, y, lpPoint);
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

int WINAPI StretchDIBits_WCECL(
    HDC hdc,
    int xDest,
    int yDest, 
    int DestWidth,
    int DestHeight,
    int xSrc,
    int ySrc,
    int SrcWidth,
    int SrcHeight,
    const void* lpBits,
    const BITMAPINFO* lpbmi,
    UINT iUsage,
    DWORD rop)
{
    return StretchDIBits(
        hdc,
        xDest,
        yDest,
        DestWidth,
        DestHeight,
        xSrc,
        ySrc,
        SrcWidth,
        SrcHeight,
        lpBits,
        lpbmi,
        iUsage,
        rop);
}

BOOL WINAPI SystemParametersInfoW_WCECL(
    UINT uiAction,
    UINT uiParam,
    PVOID pvParam,
    UINT fWinIni)
{
    return SystemParametersInfoW(uiAction, uiParam, pvParam, fWinIni);
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

BOOL WINAPI UnionRect_WCECL(LPRECT lprcDst, const RECT* lpSrc1, const RECT* lpSrc2)
{
    return UnionRect(lprcDst, lpSrc1, lpSrc2);
}

BOOL WINAPI UnmapViewOfFile_WCECL(LPCVOID pAddress)
{
    return UnmapViewOfFile(pAddress);
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

int WINAPI SetBkMode_WCECL(HDC hDc, int mode)
{
    return SetBkMode(hDc, mode);
}

COLORREF WINAPI SetBkColor_WCECL(HDC hDc, COLORREF color)
{
    return SetBkColor(hDc, color);
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

void WINAPI OutputDebugStringW_WCECL(LPCWSTR str)
{
    wprintf(L"%s", str);
}

BOOL WINAPI PatBlt_WCECL(HDC hdc, int x, int y, int w, int h, DWORD rop)
{
    return PatBlt(hdc, x, y, w, h, rop);
}

HACCEL WINAPI LoadAcceleratorsW_WCECL(HINSTANCE hInstance, LPCWSTR lpTableName)
{
    return LoadAcceleratorsW(hInstance, lpTableName);
}

int WINAPI TranslateAcceleratorW_WCECL(HWND hWnd, HACCEL hAccelTable, LPMSG lpMsg)
{
    return TranslateAcceleratorW(hWnd, hAccelTable, lpMsg);
}

BOOL WINAPI EnableMenuItem_WCECL(HMENU hMenu, UINT uIDEnableItem, UINT uEnable)
{
    return EnableMenuItem(hMenu, uIDEnableItem, uEnable);
}

int WINAPI CombineRgn_WCECL(HRGN hrgnDst, HRGN hrgnSrc1, HRGN hrgnSrc2, int iMode)
{
    return CombineRgn(hrgnDst, hrgnSrc1, hrgnSrc2, iMode);
}