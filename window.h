#ifndef WINDOW_H
#define WINDOW_H



#include <windows.h>



#include "error.h"



static const LPCWSTR W32_MAIN_CLASS_NAME = L"W32_Main";



int W32_InitWindow(WNDPROC window_procedure) {

        WNDCLASSEXW wc = {

                .cbSize = sizeof(WNDCLASSEX),
                .lpfnWndProc = window_procedure,
                .lpszClassName = W32_MAIN_CLASS_NAME

        };

        if (!RegisterClassExW(&wc)) {
                W32_ErrorExit(L"ERROR: Failed to register window class");
                return 0;
        }



        HWND w32_hwnd = CreateWindowExW(
                0,
                W32_MAIN_CLASS_NAME,
                L"",
                WS_OVERLAPPEDWINDOW,
                300,
                300,
                1024,
                768,
                NULL,
                NULL,
                GetModuleHandleW(NULL),
                NULL
        );

        if (!w32_hwnd) {
                W32_ErrorExit(L"ERROR: Failed to create window");
                return 0;
        }



        ShowWindow(w32_hwnd, SW_SHOW);



                // Main loop

        MSG msg;
        while (GetMessageW(&msg, NULL, 0, 0) > 0) {
                TranslateMessage(&msg);
                DispatchMessageW(&msg);
        }



        return 1;

}



#endif // WINDOW_H