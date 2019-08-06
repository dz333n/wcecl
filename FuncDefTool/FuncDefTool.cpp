// FuncDefTool.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "FuncDefTool.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance

// Forward declarations of functions included in this code module:
BOOL                InitInstance(HINSTANCE, int);

INT_PTR MainWndDlgProc(
	HWND hDlg,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam)
{
	if (Msg == WM_INITDIALOG)
		return TRUE;

	return FALSE;
	// return DefDlgProc(hDlg, Msg, wParam, lParam);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

	return 0;
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   DialogBox(hInst, MAKEINTRESOURCE(IDD_MAINDLG), NULL, (DLGPROC)MainWndDlgProc);

   return TRUE;
}

