#include "stdafx.h"

int WINAPI ImageList_Add_WCECL(HIMAGELIST hImageList, HBITMAP hBitmap, HBITMAP hMask)
{
    return ImageList_Add(hImageList, hBitmap, hMask);
}

int WINAPI ImageList_AddMasked_WCECL(HIMAGELIST hImageList, HBITMAP hBitmap, COLORREF crMask)
{
    return ImageList_AddMasked(hImageList, hBitmap, crMask);
}

int WINAPI ImageList_BeginDrag_WCECL(HIMAGELIST hImageList, int iTrack, int dxHotspot, int dyHotspot)
{
    return ImageList_BeginDrag(hImageList, iTrack, dxHotspot, dyHotspot);
}

HIMAGELIST WINAPI ImageList_Create_WCECL(int cx, int cy, UINT flags, int cInitial, int cGrow)
{
    return ImageList_Create(cx, cy, flags, cInitial, cGrow);
}

BOOL WINAPI ImageList_Destroy_WCECL(HIMAGELIST hImageList)
{
    return ImageList_Destroy(hImageList);
}

BOOL WINAPI ImageList_DragEnter_WCECL(HWND hwndLock, int x, int y)
{
    return ImageList_DragEnter(hwndLock, x, y);
}

BOOL WINAPI ImageList_DragLeave_WCECL(HWND hwndLock)
{
    return ImageList_DragLeave(hwndLock);
}

BOOL WINAPI ImageList_DragMove_WCECL(int x, int y)
{
    return ImageList_DragMove(x, y);
}

BOOL WINAPI ImageList_DragShowNolock_WCECL(BOOL fShow)
{
    return ImageList_DragShowNolock(fShow);
}

BOOL WINAPI ImageList_Draw_WCECL(
    HIMAGELIST hImageList,
    int i,
    HDC hDcDest,
    int x,
    int y,
    UINT fStyle)
{
    return ImageList_Draw(hImageList, i, hDcDest, x, y, fStyle);
}

BOOL WINAPI ImageList_DrawEx_WCECL(
    HIMAGELIST hImageList, 
    int i, 
    HDC hDcDest, 
    int x, 
    int y, 
    int dx, 
    int dy, 
    COLORREF rgbBk,
    COLORREF rgbFg,
    UINT fStyle)
{
    return ImageList_DrawEx(
        hImageList, 
i, hDcDest, x, y, dx, dy, rgbBk, rgbFg, fStyle);
}

BOOL WINAPI ImageList_DrawIndirect_WCECL(IMAGELISTDRAWPARAMS* pImlDp)
{
    return ImageList_DrawIndirect(pImlDp);
}

void WINAPI ImageList_EndDrag_WCECL()
{
    ImageList_EndDrag();
}

COLORREF WINAPI ImageList_GetBkColor_WCECL(HIMAGELIST hImageList)
{
    return ImageList_GetBkColor(hImageList);
}

HIMAGELIST WINAPI ImageList_GetDragImage_WCECL(PPOINT pOutPt, PPOINT pPtHotspot)
{
    return ImageList_GetDragImage(pOutPt, pPtHotspot);
}

HICON WINAPI ImageList_GetIcon_WCECL(HIMAGELIST hImageList, int i, UINT uFlags)
{
    return ImageList_GetIcon(hImageList, i, uFlags);
}

BOOL WINAPI ImageList_GetIconSize_WCECL(
    HIMAGELIST hImageList, 
    int *pOutCx, 
    int* pOutCy)
{
    return ImageList_GetIconSize(hImageList, pOutCx, pOutCy);
}

int WINAPI ImageList_GetImageCount_WCECL(HIMAGELIST hImageList)
{
    return ImageList_GetImageCount(hImageList);
}

BOOL WINAPI ImageList_GetImageInfo_WCECL(
    HIMAGELIST hImageList,
    int i, 
    IMAGEINFO* pImageInfo)
{
    return ImageList_GetImageInfo(hImageList, i, pImageInfo);
}

HIMAGELIST WINAPI ImageList_LoadImage_WCECL(
    HINSTANCE hInstance,
    LPCWSTR lpBmp,
    int cx, 
    int cGrow,
    COLORREF crMask,
    UINT uType,
    UINT uFlags)
{
    return ImageList_LoadImageW(
        hInstance,
        lpBmp,
        cx,
        cGrow,
        crMask,
        uType,
        uFlags);
}

HIMAGELIST WINAPI ImageList_Merge_WCECL(
    HIMAGELIST hImageList1,
    int i1,
    HIMAGELIST hImageList2,
    int i2, 
    int dx,
    int dy)
{
    return ImageList_Merge(
        hImageList1,
        i1,
        hImageList2,
        i2,
        dx,
        dy);
}

BOOL WINAPI ImageList_Remove_WCECL(HIMAGELIST hImageList, int i)
{
    return ImageList_Remove(
        hImageList,
        i);
}

BOOL WINAPI ImageList_Replace_WCECL(
    HIMAGELIST hImageList, 
    int i, 
    HBITMAP hImage,
    HBITMAP hMask)
{
    return ImageList_Replace(hImageList, i, hImage, hMask);
}

int WINAPI ImageList_ReplaceIcon_WCECL(
    HIMAGELIST hImageList,
    int i, 
    HICON hIcon)
{
    return ImageList_ReplaceIcon(hImageList, i, hIcon);
}

COLORREF WINAPI ImageList_SetBkColor_WCECL(HIMAGELIST hImageList, COLORREF clrBk)
{
    return ImageList_SetBkColor(hImageList, clrBk);
}

BOOL WINAPI ImageList_SetDragCursorImage_WCECL(HIMAGELIST hImageList, int iDrag, int dxHotspot, int dyHotspot)
{
    return ImageList_SetDragCursorImage(hImageList, iDrag, dxHotspot, dyHotspot);
}

BOOL WINAPI ImageList_SetIconSize_WCECL(HIMAGELIST hImageList, int cx, int cy)
{
    return ImageList_SetIconSize(hImageList, cx, cy);
}

BOOL WINAPI ImageList_SetOverlayImage_WCECL(HIMAGELIST hImageList, int iImage, int iOverlay)
{
    return ImageList_SetOverlayImage(hImageList, iImage, iOverlay);
}

BOOL WINAPI ImageList_Copy_WCECL(
    HIMAGELIST hImlDst, 
    int iDst,
    HIMAGELIST hImlSrc,
    int iSrc,
    UINT uFlags)
{
    return ImageList_Copy(hImlDst, iDst, hImlSrc, iSrc, uFlags);
}

HIMAGELIST WINAPI ImageList_Duplicate_WCECL(HIMAGELIST hImageList)
{
    return ImageList_Duplicate(hImageList);
}

BOOL WINAPI ImageList_SetImageCount_WCECL(HIMAGELIST hImageList, UINT uNewCount)
{
    return ImageList_SetImageCount(hImageList, uNewCount);
}