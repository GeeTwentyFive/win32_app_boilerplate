#include <windows.h>



#include "window.h"



LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

        switch (uMsg) {

                case WM_DESTROY:
                        PostQuitMessage(0);
                        return 0;



                // TODO

        }



        return DefWindowProcW(hwnd, uMsg, wParam, lParam);

}



int main() {

        if (!W32_InitWindow(&WndProc))
                return -1;

        return 0;

}
