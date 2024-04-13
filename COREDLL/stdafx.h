// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <excpt.h>
#include <strsafe.h>
#include <ras.h>
#include <time.h>
// #include <dpapi.h>
#include <shlobj.h>
#include <shlobj_core.h>
#include <psapi.h>
#include <excpt.h>
#include <Mmsystem.h>
#include <ShellApi.h>
#include <string>      // std::string, std::wstring
#include <algorithm>   // std::copy 

// STRUCTS
typedef struct tagWNDCLASSW_WCECL {
	UINT        style;
	WNDPROC     lpfnWndProc;
	int         cbClsExtra;
	int         cbWndExtra;
	HINSTANCE   hInstance;
	HICON       hIcon;
	HCURSOR     hCursor;
	HBRUSH      hbrBackground;
	LPCWSTR     lpszMenuName;
	LPCWSTR     lpszClassName;
} WNDCLASSW_WCECL, *PWNDCLASSW_WCECL, *LPWNDCLASSW_WCECL;

typedef struct tagWIN32_FIND_DATA_WCECL
{
	DWORD dwFileAttributes;
	FILETIME ftCreationTime;
	FILETIME ftLastAccessTime;
	FILETIME ftLastWriteTime; 
	DWORD nFileSizeHigh; 
	DWORD nFileSizeLow; 
	DWORD dwOID;
	TCHAR cFileName[MAX_PATH];
} WIN32_FIND_DATA_WCECL, *PWIN32_FIND_DATA_WCECL, *LPWIN32_FIND_DATA_WCECL;

// MACROS
#undef RasHangUp
#undef RasDial

#ifdef WINAPI
#undef WINAPI
#endif
#define WINAPI __cdecl

#ifdef APIENTRY
#undef APIENTRY
#endif
#define APIENTRY WINAPI

#define Stub(Function) StubEx(WINAPI, Function)
#define StubEx(Decl, Function) int Decl Function() { return ProgramErrorDialog(L"Function " #Function " is not implemented yet.\n\nYES - return FALSE\nNO - return TRUE\nCANCEL - exit", FALSE); }

#define StubSilent(Function) StubSilentEx(WINAPI, Function)
#define StubSilentEx(Decl, Function) int Decl Function() { return FALSE; }

// #define w32err(Expression) (Expression) && IsDebuggerPresent() // obsolete

#define ActuallyAssert(Expression, Comment, ShowLastError) if (Expression) DisplayAssert32ErrorDialog(L"" #Expression "", Comment, ShowLastError)
#define Assert32Ex(Expression, Comment) ActuallyAssert(Expression, Comment, TRUE)
#define Assert32(Expression) Assert32Ex(Expression, L"");
#define Assert32Failed(Expression, FunctionName) Assert32Ex(Expression, L"Function '" #FunctionName "' failed.");
#define AssertFailed(Expression, FunctionName) ActuallyAssert(Expression, L"Function '" #FunctionName "' failed.", FALSE);

// FUNCTIONS
BOOL ProgramErrorDialog(LPCWSTR Text, BOOL YesNo);
VOID DisplayAssert32ErrorDialog(LPCWSTR ExpressionText, LPCWSTR Comment, BOOL ShowLastError);
DWORD GetBaseAddress(HANDLE pHandle);
HMODULE GetModule(HANDLE pHandle);
