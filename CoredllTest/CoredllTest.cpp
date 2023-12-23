// CoredllTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#include <windows.h>

#include <iostream>
#include <tchar.h>

// COREDLL exports
int __cdecl RegisterDefaultGestureHandler();
DWORD __cdecl Random();
HRESULT StringCbPrintfW(wchar_t *pszDest, size_t cbDest, const wchar_t *pszFormat, ...);

void RandomTest(int number)
{
    printf("Testing Random #%i:\n", number);
    printf("%i", Random());
    for (int i = 0; i < 50; i++)
        printf(", %i", Random());
    printf("\n");
}

int main()
{
    printf("Testing unimplemented RegisterDefaultGestureHandler:\n");
    printf("%i\n\n", RegisterDefaultGestureHandler());
    RandomTest(1);
    printf("Wait 2500 ms...\n");
    Sleep(2500);
    RandomTest(2);
    printf("\n");

    wchar_t buf[256];
    StringCbPrintfW(buf, 256, L"Should be 5: %d  Should be 1: %i\n", 5, 1);
    _tprintf(buf);
}
