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
// #include <dpapi.h>
#include <excpt.h>

#undef RasHangUp
#undef RasDial


#define Stub(Function) StubEx(WINAPI, Function)
#define StubEx(Decl, Function) int Decl Function() { return ProgramErrorDialog(L"Function " #Function " is not implemented yet.\n\nYES - return FALSE\nNO - return TRUE\nCANCEL - exit", FALSE); }

#define StubSilent(Function) StubSilentEx(WINAPI, Function)
#define StubSilentEx(Decl, Function) int Decl Function() { return FALSE; }

#define w32err(Expression) (Expression) && IsDebuggerPresent()

BOOL ProgramErrorDialog(LPCWSTR Text, BOOL YesNo);
