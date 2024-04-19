// wingdi_wcecl.cpp : wce/wingdi.h functions
#include "stdafx.h"

// Functions
int EndDoc_WCECL(HDC hdc)
{
	auto result = EndDoc(hdc);
	return result;
}

int EndPage_WCECL(HDC hdc)
{
	auto result = EndPage(hdc);
	return result;
}

BOOL PlayEnhMetaFile_WCECL(
	HDC          hdc,
	HENHMETAFILE hmf,
	const RECT* lprect)
{
	auto result = PlayEnhMetaFile(hdc, hmf, lprect);
	return result;
}

int StartPage_WCECL(
	HDC hDC)
{
	auto result = StartPage(hDC);
	return result;
}

int StartDocW_WCECL(HDC hdc, CONST DOCINFO* lpdi)
{
	auto result = StartDoc(hdc, lpdi);
	return result;
}

int SetAbortProc_WCECL(HDC hdc, ABORTPROC lpAbortProc)
{
	auto result = SetAbortProc(hdc, lpAbortProc);
	return result;
}

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

BOOL WINAPI DrawFocusRect_WCECL(HDC hDC, CONST RECT* lprc)
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

int WINAPI FillRect_WCECL(HDC hdc, CONST RECT* lprc, HBRUSH hbr)
{
	auto result = FillRect(hdc, lprc, hbr);
	return result;
}

BOOL WINAPI BitBlt_WCECL(HDC hdc, int x, int y, int cx, int cy, HDC hdcSrc, int x1, int y1, DWORD rop)
{
	auto result = BitBlt(hdc, x, y, cx, cy, hdcSrc, x1, y1, rop);
	return result;
}

int WINAPI CombineRgn_WCECL(HRGN hrgnDst, HRGN hrgnSrc1, HRGN hrgnSrc2, int iMode)
{
	return CombineRgn(hrgnDst, hrgnSrc1, hrgnSrc2, iMode);
}

BOOL WINAPI PatBlt_WCECL(HDC hdc, int x, int y, int w, int h, DWORD rop)
{
	return PatBlt(hdc, x, y, w, h, rop);
}

int WINAPI SetBkMode_WCECL(HDC hDc, int mode)
{
	return SetBkMode(hDc, mode);
}

COLORREF WINAPI SetBkColor_WCECL(HDC hDc, COLORREF color)
{
	return SetBkColor(hDc, color);
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


UINT WINAPI SetTextAlign_WCECL(HDC hDc, UINT align)
{
	return SetTextAlign(hDc, align);
}

BOOL WINAPI SetViewportOrgEx_WCECL(HDC hDc, int x, int y, LPPOINT lpPoint)
{
	return SetViewportOrgEx(hDc, x, y, lpPoint);
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

DWORD WINAPI GetLayout_WCECL(HDC hDc)
{
	return GetLayout(hDc);
}

COLORREF WINAPI GetNearestColor_WCECL(HDC hDc, COLORREF color)
{
	return GetNearestColor(hDc, color);
}

COLORREF WINAPI GetPixel_WCECL(HDC hDc, int x, int y)
{
	return GetPixel(hDc, x, y);
}

int WINAPI IntersectClipRect_WCECL(HDC hDc, int a, int b, int c, int d)
{
	return IntersectClipRect(hDc, a, b, c, d);
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

BOOL WINAPI RestoreDC_WCECL(HDC hDc, int nSavedDc)
{
	return RestoreDC(hDc, nSavedDc);
}

int WINAPI SaveDC_WCECL(HDC hDc)
{
	return SaveDC(hDc);
}

int WINAPI SelectClipRgn_WCECL(HDC hDc, HRGN hRgn)
{
	return SelectClipRgn(hDc, hRgn);
}

HPALETTE WINAPI SelectPalette_WCECL(HDC hDc, HPALETTE hPalette, BOOL bForceBkd)
{
	return SelectPalette(hDc, hPalette, bForceBkd);
}

BOOL WINAPI SetBrushOrgEx_WCECL(HDC hDc, int x, int y, LPPOINT lppt)
{
	return SetBrushOrgEx(hDc, x, y, lppt);
}

DWORD WINAPI SetLayout_WCECL(HDC hDc, DWORD l)
{
	return SetLayout(hDc, l);
}
// Stubs

