// mmsystem_wcecl.cpp : wce/mmsystem.h functions
#include "stdafx.h"


// Functions
BOOL APIENTRY sndPlaySoundW_WCECL(LPCWSTR lpszSoundName, UINT fuSound)
{
	auto result = sndPlaySoundW(lpszSoundName, fuSound);
	return result;
}

// Stubs
