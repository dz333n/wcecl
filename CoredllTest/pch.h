#ifndef PCH_H
#define PCH_H

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>

int __cdecl RegisterDefaultGestureHandler();
DWORD __cdecl Random();
HRESULT StringCbPrintfW(wchar_t* pszDest, size_t cbDest, const wchar_t* pszFormat, ...);

#endif 
