// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "winuser_wcecl.h"

typedef UINT(__cdecl* CE_ENTRYPOINT)(HINSTANCE, HINSTANCE, LPCWSTR, int);
void WceclEntrypointWrapper();

#ifdef _M_IX86
#pragma pack(push, 1)

static struct
{
	BYTE Push;
	void* Address;
	BYTE Ret;
}
EntrypointHijackCode[] = { {0x68, WceclEntrypointWrapper, 0xC3} };
#pragma pack(pop)
#else
/* FIXME: No patching code for architectures other than x86. */
#endif

static BYTE EntrypointRepairCode[sizeof(EntrypointHijackCode)];
CE_ENTRYPOINT Entrypoint;

static void WceclEntrypointWrapper()
{
	STARTUPINFOW startupInfo;
	LPCWSTR commandLine;
	BOOL bQuoted;
	UINT result;
	int nCmdShow;

	GetStartupInfoW(&startupInfo);
	commandLine = GetCommandLineW();

	/* FIXME: It seems WinCE programs do not want the image path to be included
	   in the commandLine passed to them. 
	   
	   For now, find the first argument and skip its length worth of bytes
	   from the command line. */
	bQuoted = FALSE;

	while (*commandLine)
	{
		if (*commandLine == '"')
		{
			bQuoted = !bQuoted;
		}
		if (bQuoted == FALSE)
		{
			if (iswspace(*commandLine))
			{
				while (iswspace(*commandLine)) commandLine++;
				break;
			}
		}
		commandLine++;
	}

	nCmdShow = 1;
	if (startupInfo.dwFlags & STARTF_USESHOWWINDOW)
	{
		switch (startupInfo.wShowWindow)
		{
		case SW_RESTORE:
			nCmdShow = WINCE_SW_RESTORE;
			break;
		case SW_MAXIMIZE:
			nCmdShow = WINCE_SW_MAXIMIZE;
			break;
		}
	}

	memcpy(Entrypoint, EntrypointRepairCode, sizeof(EntrypointRepairCode));
	FlushInstructionCache(GetCurrentProcess(), Entrypoint, sizeof(EntrypointRepairCode));
	result = Entrypoint(GetModuleHandleW(NULL), NULL, commandLine, nCmdShow);
	ExitProcess(result);
}

static BOOL WceclPatchEntrypoint()
{
	MODULEINFO moduleInfo;
	HMODULE hModule;
	PIMAGE_DOS_HEADER dosHeader;
	DWORD dwOld;
	MEMORY_BASIC_INFORMATION mbi;
	CE_ENTRYPOINT entrypoint;

	hModule = GetModuleHandleW(NULL);
	dosHeader = (PIMAGE_DOS_HEADER)hModule;

	if (GetModuleInformation(
		GetCurrentProcess(),
		hModule,
		&moduleInfo,
		sizeof(moduleInfo)) == FALSE)
	{
		return FALSE;
	}
	entrypoint = (CE_ENTRYPOINT)moduleInfo.EntryPoint;

	/* Unprotect the entrypoint, so it is possible to hijack it, and
	   to later repair it. */

	VirtualQuery(entrypoint, &mbi, sizeof(mbi));
	mbi.Protect &= ~(PAGE_READONLY | PAGE_EXECUTE_READ);
	mbi.Protect |= PAGE_EXECUTE_READWRITE;
	
	if (VirtualProtect(
			mbi.BaseAddress, 
			mbi.RegionSize,
			mbi.Protect,
			&dwOld) == FALSE)
	{
		return FALSE;
	}

	memcpy(EntrypointRepairCode, entrypoint, sizeof(EntrypointRepairCode));
	memcpy(entrypoint, EntrypointHijackCode, sizeof(EntrypointHijackCode));
	FlushInstructionCache(GetCurrentProcess(), entrypoint, sizeof(EntrypointHijackCode));

	Entrypoint = entrypoint;
	
	return TRUE;
}

BOOL __stdcall DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		AllocConsole();
		freopen("CONOUT$", "w", stdout);
		freopen("CONIN$", "r", stdin);

		if (MessageBoxExW(
			NULL,
			L"Attach a debugger now?",
			L"Windows CE Compatibility Layer",
			MB_YESNO,
			MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US)) == IDYES)
		{
			WCHAR VSJitDebugger[MAX_PATH], CmdLineBuf[256], SystemDirectory[MAX_PATH];
			PROCESS_INFORMATION Info = { };
			STARTUPINFO StartupInfo = { };

			GetSystemDirectoryW(SystemDirectory, MAX_PATH);
			swprintf_s(VSJitDebugger, MAX_PATH, L"%s\\vsjitdebugger.exe", SystemDirectory);
			swprintf_s(CmdLineBuf, 256, L"%s -p %d", VSJitDebugger, GetCurrentProcessId());

			StartupInfo.wShowWindow = TRUE;

			// MessageBoxW(NULL, CmdLineBuf, VSJitDebugger, 0);

			Assert32(CreateProcess(
				VSJitDebugger,
				CmdLineBuf,
				NULL, NULL,
				FALSE, NORMAL_PRIORITY_CLASS,
				NULL, NULL, &StartupInfo, &Info) == FALSE);

			WaitForSingleObject(Info.hProcess, -1);

			CloseHandle(Info.hProcess);
			CloseHandle(Info.hThread);
		}
#ifdef _M_IX86
		WceclPatchEntrypoint();
#else
		/* FIXME: No patching code for architectures other than x86. */
#endif
		break;
	};
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

