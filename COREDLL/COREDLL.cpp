// COREDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

namespace COREDLL
{
#ifdef __cplusplus
	extern "C" {
#endif
		BOOL ProgramErrorDialog(LPCWSTR Text);

		BOOL InvalidateRect_WCECL(HWND hWnd, const RECT *lpRect, BOOL bErase)
		{
			// Source: https://docs.microsoft.com/en-us/previous-versions/windows/embedded/ms909857(v%3Dmsdn.10)
			// if hWnd == NULL function must do nothing and return false;
			if (hWnd == NULL)
				return FALSE;
			else
			{
				auto result = ::InvalidateRect(hWnd, lpRect, bErase);
				return result;
			}
		}

		Stub(GetGestureInfo);
		Stub(ImmSIPanelState); // UINT dwCmd, LPVOID pValue
		Stub(StringCchPrintfW);
		Stub(SetAssociatedMenu);
		Stub(GetAssociatedMenu);
		Stub(ImageList_CopyDitherImage);
		Stub(GetOwnerProcess);
		Stub(__dtou);

		void NKDbgPrintfW(LPCWSTR lpszFmt, ...)
		{
			va_list args;
			va_start(args, lpszFmt);
			// todo
			va_end(args);
		}

		Stub(__rt_ursh);
		Stub(SetDialogAutoScrollBar);
		Stub(GetAnimateMessageInfo);
		Stub(GetWindowAutoGesture);
		Stub(SetWindowAutoGesture);
		Stub(GetMessageSource);
		Stub(__GetUserKData);

		HRESULT StringCchCopyExW(
			STRSAFE_LPWSTR  pszDest,
			size_t          cchDest,
			STRSAFE_LPCWSTR pszSrc,
			STRSAFE_LPWSTR  *ppszDestEnd,
			size_t          *pcchRemaining,
			DWORD           dwFlags)
		{
			return ::StringCchCopyExW(pszDest, cchDest, pszSrc, ppszDestEnd, pcchRemaining, dwFlags);
		}

		HRESULT StringCchPrintfExW(STRSAFE_LPWSTR  pszDest,
			size_t          cchDest,
			STRSAFE_LPWSTR  *ppszDestEnd,
			size_t          *pcchRemaining,
			DWORD           dwFlags,
			STRSAFE_LPCWSTR pszFormat,
			...)
		{
			va_list args;
			va_start(args, pszFormat);
			HRESULT result = ::StringCchPrintfExW(pszDest, cchDest, ppszDestEnd, pcchRemaining, dwFlags, pszFormat, args);
			va_end(args);
			return result;
		}

		HRESULT StringCchCopyW(STRSAFE_LPWSTR pszDest, size_t cchDest, STRSAFE_LPCWSTR pszSrc)
		{
			return ::StringCchCopyW(pszDest, cchDest, pszSrc);
		}

		Stub(GetGweApiSetTables);
		Stub(RegisterDefaultGestureHandler);
		Stub(lineAddProvider);

		HCURSOR LoadCursorW_WCECL(HINSTANCE hInstance, LPCWSTR lpCursorName)
		{
			return NULL; // FIX ME currently fails in Solitare (https://github.com/feel-the-dz3n/wcecl/issues/6) so return NULL

			// This functions was replaced by LoadImage, so
			auto result = (HCURSOR)::LoadImageW(hInstance, lpCursorName, IMAGE_CURSOR, 0, 0, LR_SHARED);
			return result;
		}

		int GetObjectW_WCECL(HGDIOBJ hgdiobj, int cbBuffer, LPVOID lpvObject)
		{
			// source: https://docs.microsoft.com/en-us/previous-versions/windows/embedded/ee506071(v%3dwinembedded.60)
			auto result = ::GetObjectW(hgdiobj, cbBuffer, lpvObject);
			return result;
		}

		/*int fwprintf(FILE* const _Stream, wchar_t const* const _Format, ...)
		{
			va_list args;
			va_start(args, _Format);

			int result = ::fwprintf(_Stream, _Format, args);

			va_end(args);
			return result;
		}*/

		DWORD Random() 
		{
			// sources: https://docs.microsoft.com/en-us/previous-versions/windows/embedded/ms860353(v%3Dmsdn.10)
			//          https://docs.microsoft.com/en-us/previous-versions/ms910957(v=msdn.10)
			::srand(::GetTickCount());
			auto result = ::rand();
			return result;
		}

		Stub(CloseGestureInfoHandle);
		Stub(Gesture);
		Stub(GetGestureExtraArguments);
		Stub(SetWindowPosOnRotate);

		LONG RegOpenKeyExW_WCECL(
			HKEY hKey,
			LPCWSTR lpSubKey,
			DWORD ulOptions,
			REGSAM samDesired,
			PHKEY phkResult)
		{
			// source: https://docs.microsoft.com/en-us/previous-versions/windows/embedded/ms891460(v%3Dmsdn.10)
			// samDesired and ulOptions are 0 always
			auto result = ::RegOpenKeyExW(hKey, lpSubKey, 0, 0, phkResult);
			return result;
		}

		HBRUSH CreateSolidBrush_WCECL(COLORREF crColor) 
		{
			auto result = ::CreateSolidBrush(crColor);
			return result;
		}

		HICON LoadIconW_WCECL(HINSTANCE hInstance, LPCWSTR lpIconName) 
		{
			auto result = ::LoadIconW(hInstance, lpIconName);
			return result;
		}

		ATOM RegisterClassW_WCECL(const WNDCLASS *lpWndClass)
		{
			auto result = ::RegisterClass(lpWndClass);
			return result;
		}

		UINT SetTimer_WCECL(HWND hWnd, UINT nIDEvent, UINT uElapse, TIMERPROC lpTimerFunc)
		{
			auto result = ::SetTimer(hWnd, nIDEvent, uElapse, lpTimerFunc);
			return result;
		}

		int GetDeviceCaps_WCECL(HDC hdc, int nIndex)
		{
			auto result = ::GetDeviceCaps(hdc, nIndex);
			return result;
		}

		int ReleaseDC_WCECL(HWND hWnd, HDC hDC)
		{
			auto result = ::ReleaseDC(hWnd, hDC);
			return result;
		}

		HDC GetDC_WCECL(HWND hWnd)
		{
			auto result = ::GetDC(hWnd);
			return result;
		}

		HWND CreateWindowExW_WCECL(
			DWORD dwExStyle,
			LPCWSTR lpClassName,
			LPCWSTR lpWindowName,
			DWORD dwStyle,
			int x,
			int y,
			int nWidth,
			int nHeight,
			HWND hWndParent,
			HMENU hMenu,
			HINSTANCE hInstance,
			LPVOID lpParam)
		{
			auto result = ::CreateWindowExW(
				dwExStyle,
				lpClassName,
				lpWindowName,
				dwStyle,
				x,
				y,
				nWidth,
				nHeight,
				hWndParent,
				hMenu,
				hInstance,
				lpParam);

			return result;
		}

		DWORD RasDial(LPRASDIALEXTENSIONS Arg1, LPCWSTR Arg2, LPRASDIALPARAMSW Arg3, DWORD Arg4, LPVOID Arg5, LPHRASCONN Arg6)
		{
			return ::RasDialW(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6);
		}

		DWORD RasHangup(HRASCONN Arg1) // @344
		{
			return ::RasHangUpW(Arg1);
		}

		DWORD RasHangUp(HRASCONN Arg1) // @343
		{
			return RasHangup(Arg1);
		}

		Stub(sndPlaySoundW);

		HRESULT StringCbPrintfW(STRSAFE_LPWSTR pszDest, size_t cbDest, STRSAFE_LPCWSTR pszFormat, ...) // @1700
		{
			va_list args;
			va_start(args, pszFormat);
			HRESULT result = ::StringCbPrintfW(pszDest, cbDest, pszFormat, args);
			va_end(args);
			return result;
		}


		DWORD _stdcall _except_handler4_common_WCECL(DWORD nBufferLength, LPWSTR lpBuffer)
		{
			int result = MessageBoxExW(
				NULL, 
				L"WARNING: Exception happened!\n\nYES - continue\nNO - exit", 
				L"Windows CE Compatibility Layer",
				MB_YESNO,
				MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));

			if (result == IDYES) return 0;
			else exit(1);

			return 0;
		}

		Stub(_XcptFilter); // unsigned long xcptnum, long pxcptinfoptrs
		StubSilent(__security_gen_cookie2);
		Stub(__report_gsfailure_WCECL);
		Stub(_ftol2);
		Stub(_ftol2_sse);
		Stub(DSA_Search);
		Stub(WeirdThing1865);
		Stub(WeirdThing1866);
		Stub(WeirdThing1846);
		Stub(WeirdThing1849);
		Stub(WeirdThing1841);
		Stub(WeirdThing1840);

		BOOL ProgramErrorDialog(LPCWSTR Text)
		{
			int box = MessageBoxExW(
				NULL,
				Text, 
				L"Windows CE Compatibility Layer", 
				MB_YESNOCANCEL, 
				MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));

			if (box == IDNO) return TRUE;
			else if (box == IDCANCEL) exit(1);
			else return FALSE; // yes/close

			return FALSE;
		}

		HRESULT _declspec(dllexport) _inline _stdcall StringCchVPrintfW_WCECL(
			STRSAFE_LPWSTR pszDest,
			size_t cchDest,
			STRSAFE_LPCWSTR pszFormat,
			va_list argList)
		{
			return ::StringCchVPrintfW(pszDest, cchDest, pszFormat, argList);
		}

		Stub(GetAPIAddress);

#ifdef __cplusplus
	}
#endif
}
