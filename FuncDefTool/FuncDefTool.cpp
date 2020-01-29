// FuncDefTool.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "FuncDefTool.h"

#define MAX_LOADSTRING 100
#define S(quote) (TCHAR*)L##quote

// Global Variables:
HINSTANCE hInst;                                // current instance
TCHAR WceclCoredllPath[MAX_PATH] = { };
TCHAR TargetExecutablePath[MAX_PATH] = { };
TCHAR OrigLibPath[MAX_PATH] = { };

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
		&& FileExists(TargetExecutablePath)
		&& FileExists(OrigLibPath);

	HWND ctrlWceclPath = GetDlgItem(hDlg, IDC_WCECL_PATH);
	SetWindowText(ctrlWceclPath, _tcslen(WceclCoredllPath) >= 1 ? WceclCoredllPath : L"(select WCECL coredll.dll path)");

	HWND ctrlTargetPath = GetDlgItem(hDlg, IDC_TARGET_PATH);
	SetWindowText(ctrlTargetPath, _tcslen(TargetExecutablePath) >= 1 ? TargetExecutablePath : L"(select target executable path)");

	HWND ctrlOrigPath = GetDlgItem(hDlg, IDC_ORIG_DLL_PATH);
	SetWindowText(ctrlOrigPath, _tcslen(OrigLibPath) >= 1 ? OrigLibPath : L"(select Windows CE coredll.dll path)");

	EnableWindow(btn, enabled);
}

void AppendText(const HWND &hwnd, TCHAR *newText)
{
	// get edit control from dialog
	HWND hwndOutput = GetDlgItem(hwnd, IDC_RESULT_BOX);

	// get new length to determine buffer size
	int outLength = GetWindowTextLength(hwndOutput) + lstrlen(newText) + 1;

	// create buffer to hold current and new text
	TCHAR * buf = (TCHAR *)GlobalAlloc(GPTR, outLength * sizeof(TCHAR));
	if (!buf) return;

	// get existing text from edit control and put into buffer
	GetWindowText(hwndOutput, buf, outLength);

	// append the newText to the buffer
	_tcscat_s(buf, outLength, newText);

	// Set the text in the edit control
	SetWindowText(hwndOutput, buf);

	// free the buffer
	GlobalFree(buf);
}

void AppendTextLine(const HWND &hwnd, TCHAR *newText)
{
	AppendText(hwnd, newText);
	AppendText(hwnd, S("\r\n"));
}

VOID SetResultText(HWND hMainWnd, LPCWSTR Text)
{
	SetWindowText(
		GetDlgItem(hMainWnd, IDC_RESULT_BOX),
		Text);
}

VOID EnableProcessButtons(HWND hDlg, BOOL Enable)
{
	EnableWindow(GetDlgItem(hDlg, ID_SELECT_WCECL), Enable);
	EnableWindow(GetDlgItem(hDlg, ID_SELECT_TARGET), Enable);
	EnableWindow(GetDlgItem(hDlg, ID_SELECT_ORIG), Enable);
	EnableWindow(GetDlgItem(hDlg, ID_PROCESS), Enable);
}

VOID Display32ErrorDialog(HWND Parent, LPCWSTR Comment)
{
	WCHAR Buffer[512];
	DWORD Error = GetLastError();
	WCHAR ErrorBuffer[256];

	if (Error == 0) wcscpy_s(ErrorBuffer, 256, L"Unknown");
	else FormatMessageW(
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		Error,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		ErrorBuffer,
		(sizeof(ErrorBuffer) / sizeof(WCHAR)),
		NULL);

	swprintf_s(
		Buffer, 512,
		L"%s\nError %d - %s",
		Comment,
		Error,
		ErrorBuffer);

	MessageBoxW(Parent, Buffer, L"WCECL FuncDefTool", MB_OK);
}

DWORD FinishProcessThreadProc(HWND hwnd)
{
	EnableProcessButtons(hwnd, TRUE);
	CheckProcessBtnState(hwnd);

	ExitThread(0);

	return 0;
}

DWORD WINAPI ProcessThreadProc(CONST LPVOID lpParam) 
{
	HWND hwnd = (HWND)lpParam;
	WCHAR buf[1024];
	
	EnableProcessButtons(hwnd, FALSE);

	SetResultText(hwnd, L"");

	// ==========================================================
	AppendTextLine(hwnd, S("Loading WCECL executables..."));

	HANDLE hFileWCECL = CreateFile(
		WceclCoredllPath,
		GENERIC_READ,
		NULL,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hFileWCECL == INVALID_HANDLE_VALUE)
	{
		AppendTextLine(hwnd, S("Error happened."));
		Display32ErrorDialog(hwnd, L"Unable to open WCECL COREDLL.DLL");
		
		return FinishProcessThreadProc(hwnd);
	}

	DWORD fWceclLen = GetFileSize(hFileWCECL, NULL);
	char* bufFileWCECL = new char[fWceclLen];

	if (!ReadFile(hFileWCECL, bufFileWCECL, fWceclLen, NULL, NULL))
	{
		AppendTextLine(hwnd, S("Error happened."));
		Display32ErrorDialog(hwnd, L"Unable to read WCECL COREDLL.DLL");

		CloseHandle(hFileWCECL);
		delete bufFileWCECL;

		return FinishProcessThreadProc(hwnd);
	}

	// ==========================================================
	AppendTextLine(hwnd, S("Loading target executable..."));

	HANDLE hFileTarget = CreateFile(
		TargetExecutablePath,
		GENERIC_READ,
		NULL,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hFileTarget == INVALID_HANDLE_VALUE)
	{
		AppendTextLine(hwnd, S("Error happened."));
		Display32ErrorDialog(hwnd, L"Unable to open target executable");

		CloseHandle(hFileWCECL);
		delete bufFileWCECL;

		return FinishProcessThreadProc(hwnd);
	}

	DWORD fTargetLen = GetFileSize(hFileTarget, NULL);
	char* bufFileTarget = new char[fTargetLen];

	if (!ReadFile(hFileTarget, bufFileTarget, fTargetLen, NULL, NULL))
	{
		AppendTextLine(hwnd, S("Error happened."));
		Display32ErrorDialog(hwnd, L"Unable to read target executable");

		CloseHandle(hFileWCECL);
		CloseHandle(hFileTarget);
		delete bufFileWCECL;
		delete bufFileTarget;

		return FinishProcessThreadProc(hwnd);
	}

	// ==========================================================
	AppendTextLine(hwnd, S("Loading original library..."));

	HANDLE hFileOrig = CreateFile(
		OrigLibPath,
		GENERIC_READ,
		NULL,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hFileOrig == INVALID_HANDLE_VALUE)
	{
		AppendTextLine(hwnd, S("Error happened."));
		Display32ErrorDialog(hwnd, L"Unable to open original library");

		CloseHandle(hFileWCECL);
		CloseHandle(hFileTarget);
		delete bufFileWCECL;
		delete bufFileTarget;

		return FinishProcessThreadProc(hwnd);
	}

	DWORD fOrigLen = GetFileSize(hFileOrig, NULL);
	char* bufFileOrig = new char[fOrigLen];

	if (!ReadFile(hFileOrig, bufFileOrig, fOrigLen, NULL, NULL))
	{
		AppendTextLine(hwnd, S("Error happened."));
		Display32ErrorDialog(hwnd, L"Unable to read original library");

		CloseHandle(hFileWCECL);
		CloseHandle(hFileTarget);
		CloseHandle(hFileOrig);
		delete bufFileWCECL;
		delete bufFileTarget;
		delete bufFileOrig;

		return FinishProcessThreadProc(hwnd);
	}

	// ==========================================================
	delete bufFileWCECL;
	delete bufFileTarget;
	delete bufFileOrig;
	CloseHandle(hFileWCECL);
	CloseHandle(hFileTarget);
	FinishProcessThreadProc(hwnd);
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

		SetResultText(hDlg, L"Result will be here");

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
			case ID_PROCESS:
			{
				CreateThread(
					NULL,
					0,
					&ProcessThreadProc,
					hDlg,
					0,
					NULL);

				break;
			}
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
			case ID_SELECT_ORIG:
			{
				OPENFILENAME ofn;

				// Initialize OPENFILENAME
				ZeroMemory(&ofn, sizeof(ofn));
				ofn.lStructSize = sizeof(ofn);
				ofn.hwndOwner = hDlg;
				ofn.lpstrFile = OrigLibPath;
				ofn.nMaxFile = sizeof(OrigLibPath);
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
