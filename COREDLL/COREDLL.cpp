// COREDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

namespace COREDLL
{
#ifdef __cplusplus
	extern "C" {
#endif
		BOOL Unimplemented(LPCWSTR Text);

		BOOL _declspec(dllexport) __stdcall InvalidateRectCELayer(HWND hWnd, const RECT *lpRect, BOOL bErase)
		{
			// Source: https://docs.microsoft.com/en-us/previous-versions/windows/embedded/ms909857(v%3Dmsdn.10)
			// if hWnd == NULL function must do nothing and return false;
			if (hWnd == NULL)
				return FALSE;
			else
				return ::InvalidateRect(hWnd, lpRect, bErase);
		}

		int GetGestureInfo()  // unimplemented
		{
			return Unimplemented(L"GetGestureInfo");
		}

		bool _declspec(dllexport) EnumSystemLocalesW(long lpLocaleEnumProc, DWORD dwFlags)  // unimplemented
		{
			return Unimplemented(L"EnumSystemLocalesW");
		}

		bool ImmSIPanelState(UINT dwCmd, LPVOID pValue) // unimplemented
		{
			return Unimplemented(L"ImmSIPanelState");
		}

		int StringCchPrintfW()  // unimplemented
		{
			return Unimplemented(L"StringCchPrintfW");
		}

		int SetAssociatedMenu() // unimplemented
		{
			return Unimplemented(L"SetAssociatedMenu");
		}

		int GetAssociatedMenu() // unimplemented
		{
			return Unimplemented(L"GetAssociatedMenu");
		}

		int ImageList_CopyDitherImage() // unimplemented
		{
			return Unimplemented(L"ImageList_CopyDitherImage");
		}

		int GetOwnerProcess() // unimplemented
		{
			return Unimplemented(L"GetOwnerProcess");
		}

		int __dtou() // unimplemented
		{
			return Unimplemented(L"__dtou");
		}

		void NKDbgPrintfW(LPCWSTR lpszFmt, ...)
		{
			va_list args;
			va_start(args, lpszFmt);
			// todo
			va_end(args);
		}

		int __rt_ursh() // unimplemented
		{
			return Unimplemented(L"__rt_ursh");
		}

		int SetDialogAutoScrollBar() // unimplemented
		{
			return Unimplemented(L"SetDialogAutoScrollBar");
		}

		int GetAnimateMessageInfo() // unimplemented
		{
			return Unimplemented(L"GetAnimateMessageInfo");
		}

		int GetWindowAutoGesture() // unimplemented
		{
			return Unimplemented(L"GetWindowAutoGesture");
		}

		bool SetWindowAutoGesture() // unimplemented
		{
			return Unimplemented(L"SetWindowAutoGesture");
		}

		int GetMessageSource() // unimplemented
		{
			return Unimplemented(L"GetMessageSource");
		}

		int __GetUserKData() // unimplemented
		{
			return Unimplemented(L"__GetUserKData");
		}

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

		int GetGweApiSetTables()
		{
			return Unimplemented(L"GetGweApiSetTables");
		}

		int RegisterDefaultGestureHandler() // @2928 // unimplemented
		{
			return Unimplemented(L"RegisterDefaultGestureHandler");
		}

		int lineAddProvider() // @375 // unimplemented
		{
			return Unimplemented(L"lineAddProvider");
		}

		/*int fwprintf(FILE* const _Stream, wchar_t const* const _Format, ...)
		{
			va_list args;
			va_start(args, _Format);

			int result = ::fwprintf(_Stream, _Format, args);

			va_end(args);
			return result;
		}*/

		int Random() // unimplemented
		{
			return ::rand();
		}

		bool CloseGestureInfoHandle() // unimplemented
		{
			return Unimplemented(L"CloseGestureInfoHandle");
		}

		bool Gesture() // unimplemented
		{
			return Unimplemented(L"Gesture");
		}

		bool GetGestureExtraArguments() // unimplemented
		{
			return Unimplemented(L"GetGestureExtraArguments");
		}

		bool SetWindowPosOnRotate() // unimplemented
		{
			return Unimplemented(L"SetWindowPosOnRotate");
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

		int sndPlaySoundW() // @377 // unimplemented
		{
			return Unimplemented(L"sndPlaySoundW");
		}

		HRESULT StringCbPrintfW(STRSAFE_LPWSTR pszDest, size_t cbDest, STRSAFE_LPCWSTR pszFormat, ...) // @1700
		{
			va_list args;
			va_start(args, pszFormat);
			HRESULT result = ::StringCbPrintfW(pszDest, cbDest, pszFormat, args);
			va_end(args);
			return result;
		}

		int _XcptFilter(unsigned long xcptnum, long pxcptinfoptrs) // @1645 // unimplemented
		{
			return Unimplemented(L"_XcptFilter");
		}

		int _except_handler4_common_CELayer()
		{
			return Unimplemented(L"_except_handler4_common_CELayer");
		}

		int _ftol2() 
		{
			return Unimplemented(L"_ftol2");
		}

		int _ftol2_sse()
		{
			return Unimplemented(L"_ftol2_sse");
		}

		int __security_gen_cookie2() // @2696  // unimplemented
		{
			return Unimplemented(L"__security_gen_cookie2");
		}

		int __report_gsfailure() // @1876 // unimplemented
		{
			return Unimplemented(L"__report_gsfailure");
		}

		int DSA_Search()
		{
			return Unimplemented(L"DSA_Search");
		}

		int WeirdThing1865()
		{
			return Unimplemented(L"WeirdThing1865");
		}

		int WeirdThing1866()
		{
			return Unimplemented(L"WeirdThing1866");
		}

		int WeirdThing1846()
		{
			return Unimplemented(L"WeirdThing1846");
		}

		int WeirdThing1849()
		{
			return Unimplemented(L"WeirdThing1849");
		}

		int WeirdThing1841()
		{
			return Unimplemented(L"WeirdThing1841");
		}

		int WeirdThing1840()
		{
			return Unimplemented(L"WeirdThing1840");
		}

		BOOL Unimplemented(LPCWSTR Text)
		{
			MessageBox(NULL, Text, L"WCECL - Unimplemented Function", 0);
			return FALSE;
		}

#ifdef __cplusplus
	}
#endif
}
