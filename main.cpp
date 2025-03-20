// v1.3.0
#include <windows.h>
#include <commdlg.h>
#include <fstream>
#include <string>
#include <shlwapi.h>
#include "resource.h"

const wchar_t* CLASS_NAME = L"Notepad";
HWND hwndEdit;
WNDPROC originalEditProc;
std::wstring currentFileName = L"Untitled";
std::wstring currentFilePath = L"";
bool isModified = false;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK EditProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void SaveFileAs(HWND hwnd, HWND hwndEdit);

std::wstring StringToWString(const std::string& str) {
    return std::wstring(str.begin(), str.end());
}

void UpdateWindowTitle(HWND hwnd) {
    std::wstring title = (isModified ? L"*" : L"") + currentFileName + L" - Notepad";
    SetWindowTextW(hwnd, title.c_str());
}

void OpenFile(HWND hwnd) {
    OPENFILENAMEW ofn;
    wchar_t szFile[260] = {0};

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile) / sizeof(wchar_t);
    ofn.lpstrFilter = L"Text Files\0*.TXT\0All Files\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileNameW(&ofn)) {
        std::ifstream file(ofn.lpstrFile, std::ios::binary);
        if (file.is_open()) {
            std::string content((std::istreambuf_iterator<char>(file)),
                                std::istreambuf_iterator<char>());
            file.close();

            std::wstring wContent = StringToWString(content);
            SetWindowTextW(hwndEdit, wContent.c_str());

            currentFilePath = ofn.lpstrFile;
            currentFileName = PathFindFileNameW(ofn.lpstrFile);
            isModified = false;
            UpdateWindowTitle(hwnd);

            int tabWidth = 4 * 4;
            SendMessage(hwndEdit, EM_SETTABSTOPS, 1, (LPARAM)&tabWidth);
        } else {
            MessageBoxW(hwnd, L"Failed to open the file.", L"Error", MB_OK | MB_ICONERROR);
        }
    }
}

void SaveFile(HWND hwnd, HWND hwndEdit) {
    if (!currentFilePath.empty()) {
        int len = GetWindowTextLengthW(hwndEdit) + 1;
        wchar_t* buffer = new wchar_t[len];
        GetWindowTextW(hwndEdit, buffer, len);
        std::wofstream file(currentFilePath.c_str());
        if (file.is_open()) {
            file.write(buffer, len - 1);
            file.close();
            isModified = false;
            UpdateWindowTitle(hwnd);
        }
        delete[] buffer;
    } else {
        SaveFileAs(hwnd, hwndEdit);
    }
}

void SaveFileAs(HWND hwnd, HWND hwndEdit) {
    OPENFILENAMEW ofn;
    wchar_t szFile[260] = {0};

    wcscpy_s(szFile, L"*.txt");

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile) / sizeof(wchar_t);
    ofn.lpstrFilter = L"Text Documents (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT;

    if (GetSaveFileNameW(&ofn)) {
        std::wstring filePath(ofn.lpstrFile);
        if (filePath.find(L".") == std::wstring::npos) {
            filePath += L".txt";
        }

        int len = GetWindowTextLengthW(hwndEdit) + 1;
        wchar_t* buffer = new wchar_t[len];
        GetWindowTextW(hwndEdit, buffer, len);
        std::wofstream file(filePath.c_str());
        if (file.is_open()) {
            file.write(buffer, len - 1);
            file.close();

            currentFilePath = filePath;
            currentFileName = PathFindFileNameW(filePath.c_str());
            isModified = false;
            UpdateWindowTitle(hwnd);
        }
        delete[] buffer;
    }
}

void CheckUnsavedChanges(HWND hwnd) {
    if (isModified) {
        int result = MessageBoxW(hwnd, 
            L"You have unsaved changes. Do you want to save them?",
            L"Unsaved Changes", MB_YESNOCANCEL | MB_ICONWARNING);
        if (result == IDYES) {
            SaveFile(hwnd, hwndEdit);
        } else if (result == IDCANCEL) {
            return;
        }
    }
}

LRESULT CALLBACK EditProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_KEYDOWN) {
        if (GetAsyncKeyState(VK_CONTROL) & 0x8000) {
            if (wParam == 'A') {
                SendMessage(hwnd, EM_SETSEL, 0, -1);
                return 0;
            }
        }
    } else if (uMsg == WM_CHAR || uMsg == WM_PASTE) {
        isModified = true;
        UpdateWindowTitle(GetParent(hwnd));
    }
    return CallWindowProc(originalEditProc, hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP_ICON));
    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"Notepad",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    if (hwnd == NULL)
        return 0;

    ACCEL accel[] = {
        { FVIRTKEY | FCONTROL, 'S', 3 },
        { FVIRTKEY | FCONTROL | FSHIFT, 'S', 9 }
    };
    HACCEL hAccel = CreateAcceleratorTable(accel, 2);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindowTitle(hwnd);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        if (!TranslateAccelerator(hwnd, hAccel, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    DestroyAcceleratorTable(hAccel);
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            HMENU hMenu = CreateMenu();
            HMENU hFileMenu = CreateMenu();
            HMENU hEditMenu = CreateMenu();

            AppendMenuW(hFileMenu, MF_STRING, 1, L"New");
            AppendMenuW(hFileMenu, MF_STRING, 2, L"Open");
            AppendMenuW(hFileMenu, MF_STRING, 3, L"Save");
            AppendMenuW(hFileMenu, MF_STRING, 9, L"Save As");
            AppendMenuW(hFileMenu, MF_SEPARATOR, 0, NULL);
            AppendMenuW(hFileMenu, MF_STRING, 4, L"Exit");

            AppendMenuW(hEditMenu, MF_STRING, 5, L"Undo");
            AppendMenuW(hEditMenu, MF_STRING, 6, L"Cut");
            AppendMenuW(hEditMenu, MF_STRING, 7, L"Copy");
            AppendMenuW(hEditMenu, MF_STRING, 8, L"Paste");

            AppendMenuW(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, L"File");
            AppendMenuW(hMenu, MF_POPUP, (UINT_PTR)hEditMenu, L"Edit");
            SetMenu(hwnd, hMenu);

            hwndEdit = CreateWindowExW(
                0, L"EDIT", L"",
                WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_WANTRETURN,
                0, 0, CW_USEDEFAULT, CW_USEDEFAULT,
                hwnd, (HMENU)101, GetModuleHandle(NULL), NULL
            );

            HFONT hFont = CreateFontW(
                -MulDiv(11, GetDeviceCaps(GetDC(hwnd), LOGPIXELSY), 72),
                0, 0, 0, FW_NORMAL,
                FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                DEFAULT_QUALITY, FF_MODERN | FIXED_PITCH, L"Consolas"
            );
            SendMessage(hwndEdit, WM_SETFONT, (WPARAM)hFont, TRUE);
            originalEditProc = (WNDPROC)SetWindowLongPtr(hwndEdit, GWLP_WNDPROC, (LONG_PTR)EditProc);
        }
        break;

        case WM_SIZE: {
            RECT rcClient;
            GetClientRect(hwnd, &rcClient);
            SetWindowPos(hwndEdit, NULL, 0, 0, rcClient.right, rcClient.bottom, SWP_NOZORDER);
        }
        break;

        case WM_COMMAND: {
            switch (LOWORD(wParam)) {
                case 1: // New
                    CheckUnsavedChanges(hwnd);
                    SetWindowTextW(hwndEdit, L"");
                    currentFileName = L"Untitled";
                    currentFilePath = L"";
                    isModified = false;
                    UpdateWindowTitle(hwnd);
                    break;
                case 2: // Open
                    CheckUnsavedChanges(hwnd);
                    OpenFile(hwnd);
                    break;
                case 3: // Save
                    SaveFile(hwnd, hwndEdit);
                    break;
                case 9: // Save As
                    SaveFileAs(hwnd, hwndEdit);
                    break;
                case 4: // Exit
                    CheckUnsavedChanges(hwnd);
                    PostQuitMessage(0);
                    break;
                case 5: // Undo
                    SendMessage(hwndEdit, WM_UNDO, 0, 0);
                    break;
                case 6: // Cut
                    SendMessage(hwndEdit, WM_CUT, 0, 0);
                    break;
                case 7: // Copy
                    SendMessage(hwndEdit, WM_COPY, 0, 0);
                    break;
                case 8: // Paste
                    SendMessage(hwndEdit, WM_PASTE, 0, 0);
                    break;
            }
        }
        break;

        case WM_CLOSE: {
            if (isModified) {
                int result = MessageBoxW(hwnd, 
                    L"You have unsaved changes. Do you want to save them before exiting?",
                    L"Unsaved Changes", MB_YESNOCANCEL | MB_ICONWARNING);
                if (result == IDCANCEL)
                    return 0;
                if (result == IDYES)
                    SaveFile(hwnd, hwndEdit);
            }
            DestroyWindow(hwnd);
            return 0;
        }
        break;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}
