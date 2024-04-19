// other.cpp : contains unknown for me and other weird functions )
#include "stdafx.h"
#include <io.h>

// Functions
HANDLE GetOwnerProcess_WCECL()
{
	auto result = ::GetCurrentProcess();
	return result;
}

void DeleteAndRenameFile_WCECL()
{
	// wtf is this?
}

void* new_WCECL(size_t size)
{
	void* p = ::malloc(size);
	return p;
}

void delete_WCECL(void* p) noexcept {
	::free(p);
}

int WINAPI GetLocaleInfoW_WCECL(
	IN LCID     Locale,
	IN LCTYPE   LCType,
	OUT LPWSTR  lpLCData,
	IN int      cchData)
{
	auto result = GetLocaleInfoW(Locale, LCType, lpLCData, cchData);
	return result;
}

int WINAPI GetTimeFormatW_WCECL(
	LCID             Locale,
	DWORD            dwFlags,
	CONST SYSTEMTIME *lpTime,
	LPCWSTR          lpFormat,
	LPWSTR          lpTimeStr,
	int              cchTime)
{
	auto result = GetTimeFormatW(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime);
	return result;
}

int WINAPI GetDateFormatW_WCECL(
	LCID             Locale,
	DWORD            dwFlags,
	CONST SYSTEMTIME *lpDate,
	LPCWSTR          lpFormat,
	LPWSTR          lpDateStr,
	int              cchDate)
{
	auto result = GetDateFormatW(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate);
	return result;
}

int __cdecl vfwprintf_WCECL(FILE * stream, const wchar_t * fmt, va_list args)
{
	auto result = vfwprintf(stream, fmt, args);
	return result;
}

int __cdecl fwprintf_WCECL(FILE * file, const wchar_t * fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	
	auto result = _vfwprintf_s_l(file, fmt, NULL, args);

	va_end(args);
	return result;
}

LCID WINAPI ConvertDefaultLocale_WCECL(LCID Locale)
{
	auto result = ConvertDefaultLocale(Locale);
	return result;
}

int _snwprintf_WCECL(wchar_t * buf, size_t bufCount, const wchar_t * fmt, ...)
{
#pragma warning( push )
#pragma warning( disable: 4995 4996)
	va_list args;
	va_start(args, fmt);

	auto result = _vsnwprintf(buf, bufCount, fmt, args);

	va_end(args);

#pragma warning( pop )

	return result;
}

int __cdecl swscanf_WCECL(const wchar_t * buf, const wchar_t * fmt, ...)
{
#pragma warning( push )
#pragma warning( disable: 4995 4996 )
	va_list args;
	va_start(args, fmt);

	auto result = vswscanf(buf, fmt, args);

	va_end(args);
#pragma warning( pop )

	return result;
}

int swprintf_WCECL(wchar_t * buf, const wchar_t * _format, ...)
{
#pragma warning( push )
#pragma warning( disable: 4995 4996 )
	va_list args;
	va_start(args, _format);

	auto result = vswprintf(buf, _format, args);

	va_end(args);
#pragma warning( pop )

	return result;
}


int sprintf_WCECL(char* buffer, const char* format, ...)
{
#pragma warning( push )
#pragma warning( disable: 4995 4996 )
	va_list args;
	va_start(args, format);

	auto result = vsprintf(buffer, format, args);

	va_end(args);
#pragma warning( pop )

	return result;
}

int _wcsicmp_WCECL(
	const wchar_t *string1,
	const wchar_t *string2)
{
	auto result = _wcsicmp(string1, string2);
	return result;
}

DWORD WINAPI RasDial_WCECL(LPRASDIALEXTENSIONS Arg1, LPCWSTR Arg2, LPRASDIALPARAMSW Arg3, DWORD Arg4, LPVOID Arg5, LPHRASCONN Arg6)
{
	// review me
	auto result = ::RasDialW(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6);
	return result;
}


DWORD WINAPI RasHangup_WCECL(HRASCONN Arg1) // @344
{
	auto result = ::RasHangUpW(Arg1);
	return result;
}

DWORD WINAPI RasHangUp_WCECL(HRASCONN Arg1) // @343
{
	auto result = ::RasHangUpW(Arg1);
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

void terminate_WCECL()
{
	exit(0); // std::terminate should be used here
}

void CeLogSetZones(DWORD dwZoneUser,        // User-defined zones
	DWORD dwZoneCE,          // Predefined zones
	DWORD dwZoneProcess)
{
	// wtf!?
}

void* _fileno_WCECL(FILE* file)
{
	void* result = WceclTryGetOrAllocStdHandle(file);
	if (result != NULL)
	{
		return result;
	}

	/* https://stackoverflow.com/a/3989842 */
	return (void*)_get_osfhandle(_fileno(file));
}

int WINAPI GetSystemMetrics_WCECL(int i)
{
	return GetSystemMetrics(i);
}

int WINAPI DrawTextW_WCECL(
	HDC hDc, 
	LPCWSTR lpchText, 
	int cchText, 
	LPRECT lprc, 
	UINT format)
{
	return DrawTextW(hDc, lpchText, cchText, lprc, format);
}

COLORREF WINAPI SetTextColor_WCECL(HDC hDc, COLORREF color) 
{
	return SetTextColor(hDc, color);
}

DWORD WINAPI GetLastError_WCECL() 
{
	return GetLastError();
}

void WINAPI SetLastError_WCECL(DWORD dwErrorCode)
{
	SetLastError(dwErrorCode);
}

DWORD WINAPI GetSysColor_WCECL(int index) 
{
	return GetSysColor(index);
}

HBRUSH WINAPI GetSysColorBrush_WCECL(int nIndex)
{
	return GetSysColorBrush(nIndex);
}

DWORD GetProcessVersion_WCECL(DWORD ProcessId)
{
	return GetProcessVersion(ProcessId);
}

// Stubs
Stub(_chkstk_WCECL);
Stub(WaitForAPIReady);
Stub(RegisterDefaultGestureHandler_WCECL);
Stub(CloseGestureInfoHandle_WCECL);
Stub(GetGestureExtraArguments_WCECL);
Stub(GetGestureInfo_WCECL);
Stub(_setjmp3_WCECL);
Stub(_allmul_WCECL);
Stub(_alldiv_WCECL);
Stub(_SEH_epilog_WCECL);
Stub(_SEH_prolog_WCECL);
Stub(__security_gen_cookie_WCECL);
Stub(GetProcessIndexFromID);
Stub(type_info);
Stub(CeLogReSync);
Stub(TlsCall_WCECL) // DWORD WINAPI TlsCall(DWORD p1, DWORD p2);
Stub(EventModify_WCECL); // HANDLE hEvent, DWORD func
Stub(_ftol_WCECL);
Stub(THCreateSnapshot);
Stub(GetHeapSnapshot);
Stub(CloseGestureInfoHandle);
Stub(Gesture);
Stub(GetGestureExtraArguments);
Stub(SetWindowPosOnRotate);
Stub(SetAssociatedMenu);
Stub(GetAssociatedMenu);
Stub(__dtou);
Stub(__rt_ursh);
Stub(SetDialogAutoScrollBar);
Stub(GetAnimateMessageInfo);
Stub(GetWindowAutoGesture);
Stub(SetWindowAutoGesture);
Stub(GetMessageSource);
Stub(__GetUserKData);
Stub(GetAPIAddress);
Stub(GetGweApiSetTables);
Stub(RegisterDefaultGestureHandler);
Stub(lineAddProvider);
Stub(DSA_Clone_WCECL)
Stub(DSA_Search);
Stub(WeirdThing1865);
Stub(WeirdThing1866);
Stub(WeirdThing1846);
Stub(WeirdThing1849);
Stub(WeirdThing1841);
Stub(WeirdThing1840);
Stub(_ftol2_WCECL);
Stub(_ftol2_sse_WCECL);
Stub(_CIsqrt_WCECL);
Stub(_aulldiv_WCECL);
