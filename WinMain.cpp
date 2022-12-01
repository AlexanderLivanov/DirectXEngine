#include <tchar.h>
#include <Windows.h>
#include <iostream>
#include "WindowsMessageMap.h"

using namespace std;

const auto pClassName = _T("3D ENGINE");

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch (msg)
    {
    case WM_CLOSE:
        PostQuitMessage(69);
        cout << ":: exit program";
        break;
    case WM_KEYDOWN:
        if(wParam == 'F'){
            SetWindowText(hWnd, _T("text"));
        }
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    WNDCLASSEX wc = {0};

    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = nullptr;
    wc.hCursor = nullptr;
    wc.hbrBackground = nullptr;
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = pClassName;
    wc.hIconSm = nullptr;
    RegisterClassEx(&wc);

    HWND hWnd = CreateWindowEx(0, pClassName, pClassName, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, 200, 200, 640, 480, nullptr, nullptr, hInstance, nullptr);
    ShowWindow(hWnd, SW_SHOW);
    
    // test message

    BOOL gResult;
    MSG msg;
    while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    if(gResult == -1){
        return -1;
    }else{
        return msg.wParam;
    }

    return 0;
}