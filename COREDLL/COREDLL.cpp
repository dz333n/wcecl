// COREDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

namespace COREDLL
{
#ifdef __cplusplus
	extern "C" {
#endif

		int GetGestureInfo()
		{
			return 0;
		}

		bool _declspec(dllexport) EnumSystemLocalesW(long lpLocaleEnumProc, DWORD dwFlags)
		{
			return true;
		}

		bool ImmSIPanelState(UINT dwCmd, LPVOID pValue)
		{
			return true;
		}

		int StringCchPrintfW()  // unimplemented
		{
			return 0;
		}

		int SetAssociatedMenu() // unimplemented
		{
			return 0;
		}

		int GetAssociatedMenu() // unimplemented
		{
			return 0;
		}

		int ImageList_CopyDitherImage() // unimplemented
		{
			return 0;
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
			return 0;
		}

		int RegisterDefaultGestureHandler() // @2928 // unimplemented
		{
 			return 0;
		}

		int lineAddProvider() // @375 // unimplemented
		{
			return 0;
		}

		/*int fwprintf(FILE* const _Stream, wchar_t const* const _Format, ...)
		{
			va_list args;
			va_start(args, _Format);

			int result = ::fwprintf(_Stream, _Format, args);

			va_end(args);
			return result;
		}*/

		int Random()
		{
			return ::rand();
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
			return 0;
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
			return 0;
		}

		int __security_gen_cookie2() // @2696  // unimplemented
		{
			return 0;
		}

		int __report_gsfailure() // @1876 // unimplemented
		{
			return 0;
		}

		int DSA_Search()
		{
			return 0;
		}

		int WeirdThing1865()
		{
			return 1;
		}

		int WeirdThing1866()
		{
			return 1;
		}

		int WeirdThing1846()
		{
			return 1;
		}

		int WeirdThing1849()
		{
			return 1;
		}

		int WeirdThing1841()
		{
			return 1;
		}

		int WeirdThing1840()
		{
			return 1;
		}

#ifdef __cplusplus
	}
#endif
}
