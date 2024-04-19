#include "stdafx.h"

BOOL WINAPI GetStringTypeExW_WCECL(
    LCID locale,
    DWORD dwInfoType,
    LPCWCH lpSrcStr,
    int cchSrc,
    LPWORD lpCharType)
{
    return GetStringTypeExW(locale, dwInfoType, lpSrcStr, cchSrc, lpCharType);
}

int WINAPI WideCharToMultiByte_WCECL(
	UINT CodePage,
	DWORD dwFlags,
	LPCWSTR lpWideCharStr,
	int cchWideChar,
	LPSTR lpMultiByteStr,
	int cbMultiByte,
	LPCSTR lpDefaultChar,
	LPBOOL lpUsedDefaultChar)
{
	return WideCharToMultiByte(
		CodePage,
		dwFlags,
		lpWideCharStr,
		cchWideChar,
		lpMultiByteStr,
		cbMultiByte,
		lpDefaultChar,
		lpUsedDefaultChar);
}

int WINAPI MultiByteToWideChar_WCECL(
	UINT CodePage,
	DWORD dwFlags,
	LPCCH lpMultiByteStr,
	int cbMultiByte,
	LPWSTR lpWideCharStr,
	int cchWideChar)
{
	return MultiByteToWideChar(
		CodePage, 
		dwFlags, 
		lpMultiByteStr,
		cbMultiByte,
		lpWideCharStr, 
		cchWideChar);
}