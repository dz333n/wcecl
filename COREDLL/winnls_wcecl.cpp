#include "stdafx.h"

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

LCID WINAPI GetUserDefaultLCID_WCECL()
{
    return GetUserDefaultLCID();
}

LANGID WINAPI GetSystemDefaultLangID_WCECL()
{
    return GetSystemDefaultLangID();
}

LCID WINAPI GetSystemDefaultLCID_WCECL()
{
    return GetSystemDefaultLCID();
}