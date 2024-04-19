// wce/imm.h
#include "stdafx.h"

// Functions
HIMC WINAPI ImmAssociateContext_WCECL(HWND hWnd, HIMC hImc)
{
    return ImmAssociateContext(hWnd, hImc);
}

int WINAPI ImmGetCompositionStringW_WCECL(
    HIMC hImc,
    DWORD dw,
    LPVOID lpBuf,
    DWORD dwBufLen)
{
    return ImmGetCompositionStringW(hImc, dw, lpBuf, dwBufLen);
}

HIMC WINAPI ImmGetContext_WCECL(HWND hWnd)
{
    return ImmGetContext(hWnd);
}

BOOL WINAPI ImmReleaseContext_WCECL(HWND hWnd, HIMC hImc)
{
    return ImmReleaseContext(hWnd, hImc);
}


// Stubs
Stub(ImmSIPanelState); // ret: BOOL; args: UINT dwCmd, LPVOID pValue
Stub(ImmSetHotKey_WCECL);
