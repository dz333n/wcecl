// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

#undef __stdcall // DllMain should be __stdcall always
BOOL __stdcall DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		MessageBoxExW(
			NULL,
			L"Program works. Now you can attach a debugger or continue.",
			L"Windows CE Compatibility Layer",
			MB_OK,
			MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));
		break;
	};
	//
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

