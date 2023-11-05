// strsafe_wcecl.cpp : wce/strsafe.h functions
#include "stdafx.h"

// Functions
HRESULT StringCbCopyExW_WCECL(
	STRSAFE_LPWSTR  pszDest,
	size_t          cbDest,
	STRSAFE_LPCWSTR pszSrc,
	STRSAFE_LPWSTR* ppszDestEnd,
	size_t* pcbRemaining,
	DWORD           dwFlags)
{
	auto result = ::StringCbCopyExW(pszDest, cbDest, pszSrc, ppszDestEnd, pcbRemaining, dwFlags);
	return result;
}

HRESULT StringCchLengthW_WCECL(
	PCNZWCH psz,
	size_t          cchMax,
	size_t* pcchLength)
{
	auto result = ::StringCchLength(psz, cchMax, pcchLength);
	return result;
}

HRESULT StringCchCatW_WCECL(
	LPWSTR  pszDest,
	size_t          cchDest,
	LPCWSTR pszSrc
) {
	auto result = ::StringCchCat(pszDest, cchDest, pszSrc);
	return result;
}

HRESULT StringCchCopyNW_WCECL(LPWSTR pszDest, size_t cchDest, PCNZWCH pszSrc, size_t cchSrc)
{
	auto result = StringCchCopyN(pszDest, cchDest, pszSrc, cchSrc);
	return result;
}

HRESULT WINAPI StringCchCopyExW_WCECL(wchar_t* pszDest, size_t cchDest, const wchar_t* pszSrc, wchar_t** ppszDestEnd, size_t* pcchRemaining, unsigned long dwFlags)
{
	auto result = ::StringCchCopyExW(pszDest, cchDest, pszSrc, ppszDestEnd, pcchRemaining, dwFlags);
	return result;
}

HRESULT WINAPI StringCchPrintfW_WCECL(wchar_t* pszDest, size_t cchDest, const wchar_t* pszFormat, ...)
{
	HRESULT result;
	va_list args;

	va_start(args, pszFormat);

	result = ::StringCchPrintfW(pszDest, cchDest, pszFormat, args);

	va_end(args);

	return result;
}

HRESULT WINAPI StringCchPrintfExW_WCECL(wchar_t* pszDest, size_t cchDest, wchar_t** ppszDestEnd, size_t* pcchRemaining, unsigned long dwFlags, const wchar_t* pszFormat, ...)
{
	HRESULT result;
	va_list args;

	va_start(args, pszFormat);

	result = ::StringCchPrintfExW(pszDest, cchDest, ppszDestEnd, pcchRemaining, dwFlags, pszFormat, args);

	va_end(args);

	return result;
}

HRESULT WINAPI StringCchVPrintfW_WCECL(wchar_t* pszDest, size_t cchDest, const wchar_t* pszFormat, va_list argList)
{
	auto result = ::StringCchVPrintfW(pszDest, cchDest, pszFormat, argList);
	return result;
}

HRESULT WINAPI StringCbPrintfW_WCECL(wchar_t* pszDest, size_t cbDest, const wchar_t* pszFormat, ...)
{
	va_list args;
	va_start(args, pszFormat);
	HRESULT result = ::StringCchVPrintfW_WCECL(pszDest, cbDest, pszFormat, args);
	va_end(args);
	return result;
}

HRESULT WINAPI StringCchCopyW_WCECL(wchar_t* pszDest, size_t cchDest, const wchar_t* pszSrc)
{
	auto result = ::StringCchCopyW(pszDest, cchDest, pszSrc);
	return result;
}

// Stubs

