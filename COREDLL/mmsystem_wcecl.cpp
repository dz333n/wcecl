// mmsystem_wcecl.cpp : wce/mmsystem.h functions
#include "stdafx.h"
#include <MMSystem.h>

#ifdef __stdcall
#undef __stdcall
typedef BOOL(__stdcall *sndPlaySoundW_Invoke)(LPCWSTR lpszSoundName, UINT fuSound);
#define __stdcall __cdecl
#endif

// Functions
BOOL APIENTRY sndPlaySoundW_WCECL(LPCWSTR lpszSoundName, UINT fuSound)
{
	HINSTANCE h = LoadLibraryW(L"winmm.dll");

	if (w32err(!h))
	{
		auto win32error = GetLastError();
		DebugBreak();
	}

	sndPlaySoundW_Invoke func = (sndPlaySoundW_Invoke)GetProcAddress(h, "sndPlaySoundW");

	if (w32err(!func))
		DebugBreak();

	auto result = func(lpszSoundName, fuSound);

	FreeLibrary(h);

	return result;
}

// Stubs
