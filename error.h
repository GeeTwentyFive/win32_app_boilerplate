#ifndef ERROR_H
#define ERROR_H



#include <windows.h>



void W32_ErrorExit(LPCWSTR out) {

        MessageBoxW(NULL, out, NULL, MB_TOPMOST);

        PostQuitMessage(-1);

}



#endif // ERROR_H