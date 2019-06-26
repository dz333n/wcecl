// COREDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

namespace COREDLL
{
#ifdef __cplusplus
	extern "C" {
#endif
		BOOL Unimplemented(LPCWSTR Text);

		BOOL __stdcall InvalidateRect_WCECL(HWND hWnd, const RECT *lpRect, BOOL bErase)
		{
			// Source: https://docs.microsoft.com/en-us/previous-versions/windows/embedded/ms909857(v%3Dmsdn.10)
			// if hWnd == NULL function must do nothing and return false;
			if (hWnd == NULL)
				return FALSE;
			else
				return ::InvalidateRect(hWnd, lpRect, bErase);
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
			return NULL;
			// This functions was replaced by LoadImage, so
			return (HCURSOR)::LoadImageW(hInstance, lpCursorName, IMAGE_CURSOR, 0, 0, LR_SHARED);
		}

		int GetObjectW_WCECL(HGDIOBJ hgdiobj, int cbBuffer, LPVOID lpvObject)
		{
			// source: https://docs.microsoft.com/en-us/previous-versions/windows/embedded/ee506071(v%3dwinembedded.60)
			return ::GetObjectW(hgdiobj, cbBuffer, lpvObject);
		}

		/*int fwprintf(FILE* const _Stream, wchar_t const* const _Format, ...)
		{
			va_list args;
			va_start(args, _Format);

			int result = ::fwprintf(_Stream, _Format, args);

			va_end(args);
			return result;
		}*/

		int Random() { return ::rand(); }

		Stub(CloseGestureInfoHandle);
		Stub(Gesture);
		Stub(GetGestureExtraArguments);
		Stub(SetWindowPosOnRotate);

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
			MessageBox(NULL, L"WARNING: Exception happened!", L"WCECL Exception", 0);
			return 0;// return Unimplemented(L"_except_handler4_common_WCECL");
		}

		Stub(_XcptFilter); // unsigned long xcptnum, long pxcptinfoptrs
		Stub(__security_gen_cookie2);
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

		BOOL Unimplemented(LPCWSTR Text)
		{
			MessageBox(NULL, Text, L"WCECL - Unimplemented Function", 0);
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
