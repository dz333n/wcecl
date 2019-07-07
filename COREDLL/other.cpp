// other.cpp : contains unknown and weird functions
#include "stdafx.h"

// Functions
Stub(delete_WCECL);
Stub(new_WCECL);

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

// Stubs
Stub(CloseGestureInfoHandle);
Stub(Gesture);
Stub(GetGestureExtraArguments);
Stub(SetWindowPosOnRotate);
Stub(sndPlaySoundW);
Stub(SetAssociatedMenu);
Stub(GetAssociatedMenu);
Stub(GetOwnerProcess);
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
Stub(DSA_Search);
Stub(WeirdThing1865);
Stub(WeirdThing1866);
Stub(WeirdThing1846);
Stub(WeirdThing1849);
Stub(WeirdThing1841);
Stub(WeirdThing1840);
