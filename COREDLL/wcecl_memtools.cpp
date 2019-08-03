#include "stdafx.h"

DWORD GetBaseAddress(HANDLE pHandle)
{
	return (DWORD)GetModule(pHandle);
}

HMODULE GetModule(HANDLE pHandle)
{
	HMODULE hMods[1024];
	DWORD cbNeeded;
	unsigned int i;
	WCHAR ProcessName[MAX_PATH];

	GetProcessImageFileNameW(pHandle, (LPWSTR)ProcessName, MAX_PATH);

	if (EnumProcessModules(pHandle, hMods, sizeof(hMods), &cbNeeded))
	{
		for (i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{
			TCHAR szModName[MAX_PATH];
			if (GetModuleFileNameExW(pHandle, hMods[i], szModName, sizeof(szModName) / sizeof(TCHAR)))
			{
				if (wcscmp(szModName, ProcessName) == 0)
					return hMods[i];
			}
		}
	}
	return nullptr;
}
