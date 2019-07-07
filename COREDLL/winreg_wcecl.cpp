// winreg_wcecl.cpp : wce/winreg.h functions
#include "stdafx.h"

// Functions
LONG APIENTRY RegOpenKeyExW_WCECL(
	HKEY hKey,
	LPCWSTR lpSubKey,
	DWORD ulOptions,
	REGSAM samDesired,
	PHKEY phkResult)
{
	// source: https://docs.microsoft.com/en-us/previous-versions/windows/embedded/ms891460(v%3Dmsdn.10)
	// samDesired and ulOptions are 0 always
	auto result = ::RegOpenKeyExW(hKey, lpSubKey, 0, 0, phkResult);
	return result;
}

LONG
APIENTRY
RegQueryValueExW_WCECL(
	HKEY hKey,
	LPCWSTR lpValueName,
	LPDWORD lpReserved,
	LPDWORD lpType,
	LPBYTE lpData,
	LPDWORD lpcbData)
{
	auto result = ::RegQueryValueExW(
		hKey,
		lpValueName,
		lpReserved,
		lpType,
		lpData,
		lpcbData);
	return result;
}

LONG APIENTRY RegCloseKey_WCECL(HKEY hKey)
{
	auto result = ::RegCloseKey(hKey);
	return result;
}

// Stubs

