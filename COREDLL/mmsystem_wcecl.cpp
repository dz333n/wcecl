// mmsystem_wcecl.cpp : wce/mmsystem.h functions
#include "stdafx.h"
#include <MMSystem.h>

// Functions
BOOL APIENTRY sndPlaySoundW_WCECL(LPCWSTR lpszSoundName, UINT fuSound)
{
	return FALSE;
	// auto result = sndPlaySoundW(lpszSoundName, fuSound); // unresolved for some reason, please fix
	// return result;
}

// Stubs
