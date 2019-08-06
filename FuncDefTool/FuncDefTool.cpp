// FuncDefTool.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "FuncDefTool.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
TCHAR WceclCoredllPath[MAX_PATH] = { };
TCHAR TargetExecutablePath[MAX_PATH] = { };

// Forward declarations of functions included in this code module:
BOOL InitInstance(HINSTANCE, int);

BOOL FileExists(LPCWSTR szPath)
{
	DWORD dwAttrib = GetFileAttributes(szPath);

	return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
		!(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

VOID CheckProcessBtnState(HWND hDlg)
{
	BOOL enabled = false;
	HWND btn = GetDlgItem(hDlg, ID_PROCESS);

	enabled =
		FileExists(WceclCoredllPath)
		&& FileExists(TargetExecutablePath);

	HWND ctrlWceclPath = GetDlgItem(hDlg, IDC_WCECL_PATH);
	SetWindowText(ctrlWceclPath, _tcslen(WceclCoredllPath) >= 1 ? WceclCoredllPath : L"(select path)");

	HWND ctrlTargetPath = GetDlgItem(hDlg, IDC_TARGET_PATH);
	SetWindowText(ctrlTargetPath, _tcslen(TargetExecutablePath) >= 1 ? TargetExecutablePath : L"(select path)");

	EnableWindow(btn, enabled);
}

INT_PTR MainWndDlgProc(
	HWND hDlg,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam)
{
	if (Msg == WM_INITDIALOG)
	{
		// Check add comments checkbox
		HWND cbHwnd = GetDlgItem(hDlg, IDC_CB_ADD_COMMENTS);
		SendMessage(cbHwnd, BM_SETCHECK, BST_CHECKED, 0);

		CheckProcessBtnState(hDlg);

		SetWindowText(
			GetDlgItem(hDlg, IDC_RESULT_BOX),
			L"Result will be here");

		return TRUE;
	}
	else if (Msg == WM_CLOSE)
	{
		EndDialog(hDlg, 0);
		return TRUE;
	}
	else if (Msg == WM_COMMAND)
	{
		switch (LOWORD(wParam))
		{
			case ID_COPY: // broken
			{
				TCHAR Buf[1024];

				HWND ctrlEdit = GetDlgItem(hDlg, IDC_RESULT_BOX);
				GetWindowText(ctrlEdit, Buf, 1024);

				DWORD len = wcslen(Buf);
				HGLOBAL hdst;
				LPWSTR dst;

				hdst = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, (len + 1) * sizeof(WCHAR));
				dst = (LPWSTR)GlobalLock(hdst);
				memcpy(dst, Buf, len * sizeof(WCHAR));
				dst[len] = 0;
				GlobalUnlock(hdst);

				// Set clipboard data
				if (!OpenClipboard(NULL))  return FALSE;
				EmptyClipboard();
				if (!SetClipboardData(CF_UNICODETEXT, hdst)) return FALSE;
				CloseClipboard();

				free(Buf);

				break;
			}
			case ID_SELECT_TARGET:
			{
				OPENFILENAME ofn;

				// Initialize OPENFILENAME
				ZeroMemory(&ofn, sizeof(ofn));
				ofn.lStructSize = sizeof(ofn);
				ofn.hwndOwner = hDlg;
				ofn.lpstrFile = TargetExecutablePath;
				ofn.nMaxFile = sizeof(TargetExecutablePath);
				ofn.lpstrFilter = _T("Executables (*.exe,*.dll)\0*.dll;*.exe\0All Files (*.*)\0*.*\0");
				ofn.nFilterIndex = 1;
				ofn.lpstrFileTitle = NULL;
				ofn.nMaxFileTitle = 0;
				ofn.lpstrInitialDir = NULL;
				ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

				if (GetOpenFileName(&ofn))
					CheckProcessBtnState(hDlg);

				break;
			}
			case ID_SELECT_WCECL:
			{
				OPENFILENAME ofn;

				// Initialize OPENFILENAME
				ZeroMemory(&ofn, sizeof(ofn));
				ofn.lStructSize = sizeof(ofn);
				ofn.hwndOwner = hDlg;
				ofn.lpstrFile = WceclCoredllPath;
				ofn.nMaxFile = sizeof(WceclCoredllPath);
				ofn.lpstrFilter = _T("coredll.dll\0coredll.dll\0All Files (*.*)\0*.*\0");
				ofn.nFilterIndex = 1;
				ofn.lpstrFileTitle = NULL;
				ofn.nMaxFileTitle = 0;
				ofn.lpstrInitialDir = NULL;
				ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

				if (GetOpenFileName(&ofn))
					CheckProcessBtnState(hDlg);

				break;
			}
			default: break;
		}

		return TRUE;
	}

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

