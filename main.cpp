// v1.6.1
// Stage 3 of the LFV plan, I should probably work on it more soon
#include <windows.h>
#include <windowsx.h>
#include <commdlg.h>
#include <richedit.h>
#include <dwmapi.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <shlwapi.h>

static int IMax(long long a, long long b) {
    return (int)((a > b) ? a : b);
}

static int IMin(long long a, long long b) {
    return (int)((a < b) ? a : b);
}
#include "resource.h"

#ifdef _MSC_VER
#pragma comment(lib, "Dwmapi.lib")
#pragma comment(lib, "Shlwapi.lib")
#endif

// Set to 1 in local debug builds when UTF-8 diagnostics are needed.
#ifndef DEBUG_UTF8
#define DEBUG_UTF8 0
#endif

#ifndef EM_SETTEXTEX
#define EM_SETTEXTEX (WM_USER + 97)
typedef struct _settextex {
    DWORD flags;
    UINT  codepage;
} SETTEXTEX;
#endif

#ifndef ST_DEFAULT
#define ST_DEFAULT 0x0000
#endif

#ifndef ST_UNICODE
#define ST_UNICODE 0x0001
#endif

#ifndef DWMWA_USE_IMMERSIVE_DARK_MODE
#define DWMWA_USE_IMMERSIVE_DARK_MODE 20
#endif

#ifndef DWMWA_BORDER_COLOR
#define DWMWA_BORDER_COLOR 34
#endif

#ifndef DWMWA_CAPTION_COLOR
#define DWMWA_CAPTION_COLOR 35
#endif

#ifndef DWMWA_TEXT_COLOR
#define DWMWA_TEXT_COLOR 36
#endif

#ifndef DWMWA_COLOR_DEFAULT
#define DWMWA_COLOR_DEFAULT 0xFFFFFFFF
#endif

const wchar_t* CLASS_NAME = L"Notepad";
const wchar_t* MENU_BAR_CLASS_NAME = L"DarkAwareMenuBar";
const wchar_t* POPUP_MENU_CLASS_NAME = L"DarkAwarePopupMenu";
const wchar_t* FONT_DIALOG_CLASS_NAME = L"DarkAwareFontDialog";
const wchar_t* LARGE_VIEW_CLASS_NAME = L"VirtualLargeTextView";

HINSTANCE g_hInstance = NULL;
HWND g_hwndMain = NULL;
HWND hwndEdit = NULL;
HWND hwndMenuBar = NULL;
HWND hwndPopupMenu = NULL;
HWND hwndLargeView = NULL;
HFONT hFontPrimary = NULL;
HFONT hUiFont = NULL;

std::wstring currentFileName = L"Untitled";
std::wstring currentFilePath = L"";

bool isModified = false;
bool suppressDirtyTracking = false;
bool darkModeEnabled = false;
bool g_largeFileMode = false;

constexpr int IDC_MAIN_EDIT = 101;
constexpr int IDC_LARGE_VIEW = 102;
constexpr int MENU_BAR_HEIGHT = 23;
constexpr int MENU_CORNER_RADIUS = 6;
constexpr int POPUP_CORNER_RADIUS = 10;
constexpr int BUTTON_CORNER_RADIUS = 7;
constexpr int POPUP_ROW_HEIGHT = 22;
constexpr int POPUP_SEPARATOR_HEIGHT = 7;
constexpr int POPUP_MIN_WIDTH = 160;
constexpr int FONT_DIALOG_WIDTH = 680;
constexpr int FONT_DIALOG_HEIGHT = 470;
constexpr int FONT_LIST_ROW_HEIGHT = 24;
constexpr ULONGLONG LARGE_FILE_THRESHOLD_BYTES = 128ull * 1024ull * 1024ull;
constexpr int LARGE_FILE_SCROLL_RANGE = 1000000;
constexpr DWORD LARGE_FILE_READ_CHUNK_BYTES = 64u * 1024u;
constexpr DWORD LARGE_FILE_MAX_PAINT_LINE_BYTES = 64u * 1024u;
constexpr DWORD LARGE_FILE_BLOCK_CACHE_BYTES = 1024u * 1024u;
constexpr int LARGE_FILE_LINE_CACHE_LIMIT = 1024;
constexpr int LARGE_FILE_PREFETCH_EXTRA_LINES = 80;
constexpr int LARGE_FILE_STATUS_HEIGHT = 22;
constexpr DWORD LARGE_FILE_SAVE_CHUNK_BYTES = 1024u * 1024u;

constexpr COLORREF LIGHT_EDITOR_BG = RGB(255, 255, 255);
constexpr COLORREF LIGHT_EDITOR_TEXT = RGB(0, 0, 0);
constexpr COLORREF LIGHT_MENU_BG = RGB(255, 255, 255);
constexpr COLORREF LIGHT_MENU_HOVER = RGB(229, 243, 255);
constexpr COLORREF LIGHT_MENU_ACTIVE = RGB(204, 232, 255);
constexpr COLORREF LIGHT_MENU_BORDER = RGB(180, 180, 180);
constexpr COLORREF LIGHT_TEXT = RGB(0, 0, 0);
constexpr COLORREF LIGHT_MUTED_TEXT = RGB(90, 90, 90);
constexpr COLORREF LIGHT_PANEL_BG = RGB(255, 255, 255);
constexpr COLORREF LIGHT_PANEL_BORDER = RGB(185, 185, 185);
constexpr COLORREF LIGHT_BUTTON_BG = RGB(240, 240, 240);
constexpr COLORREF LIGHT_BUTTON_HOVER = RGB(225, 240, 252);

constexpr COLORREF DARK_EDITOR_BG = RGB(30, 30, 30);
constexpr COLORREF DARK_EDITOR_TEXT = RGB(230, 230, 230);
constexpr COLORREF DARK_MENU_BG = RGB(32, 32, 32);
constexpr COLORREF DARK_MENU_HOVER = RGB(56, 56, 56);
constexpr COLORREF DARK_MENU_ACTIVE = RGB(70, 70, 70);
constexpr COLORREF DARK_MENU_BORDER = RGB(78, 78, 78);
constexpr COLORREF DARK_TEXT = RGB(236, 236, 236);
constexpr COLORREF DARK_MUTED_TEXT = RGB(165, 165, 165);
constexpr COLORREF DARK_PANEL_BG = RGB(25, 25, 25);
constexpr COLORREF DARK_PANEL_BORDER = RGB(85, 85, 85);
constexpr COLORREF DARK_BUTTON_BG = RGB(45, 45, 45);
constexpr COLORREF DARK_BUTTON_HOVER = RGB(64, 64, 64);
constexpr COLORREF DARK_FRAME_BG = RGB(30, 30, 30);
constexpr COLORREF DARK_FRAME_TEXT = RGB(240, 240, 240);
constexpr COLORREF DARK_FRAME_BORDER = RGB(45, 45, 45);

COLORREF EditorBg() { return darkModeEnabled ? DARK_EDITOR_BG : LIGHT_EDITOR_BG; }
COLORREF EditorText() { return darkModeEnabled ? DARK_EDITOR_TEXT : LIGHT_EDITOR_TEXT; }
COLORREF MenuBg() { return darkModeEnabled ? DARK_MENU_BG : LIGHT_MENU_BG; }
COLORREF MenuHover() { return darkModeEnabled ? DARK_MENU_HOVER : LIGHT_MENU_HOVER; }
COLORREF MenuActive() { return darkModeEnabled ? DARK_MENU_ACTIVE : LIGHT_MENU_ACTIVE; }
COLORREF MenuBorder() { return darkModeEnabled ? DARK_MENU_BORDER : LIGHT_MENU_BORDER; }
COLORREF UiText() { return darkModeEnabled ? DARK_TEXT : LIGHT_TEXT; }
COLORREF UiMutedText() { return darkModeEnabled ? DARK_MUTED_TEXT : LIGHT_MUTED_TEXT; }
COLORREF PanelBg() { return darkModeEnabled ? DARK_PANEL_BG : LIGHT_PANEL_BG; }
COLORREF PanelBorder() { return darkModeEnabled ? DARK_PANEL_BORDER : LIGHT_PANEL_BORDER; }
COLORREF ButtonBg() { return darkModeEnabled ? DARK_BUTTON_BG : LIGHT_BUTTON_BG; }
COLORREF ButtonHover() { return darkModeEnabled ? DARK_BUTTON_HOVER : LIGHT_BUTTON_HOVER; }

enum CommandId : UINT {
    IDM_FILE_NEW = 1,
    IDM_FILE_OPEN = 2,
    IDM_FILE_SAVE = 3,
    IDM_FILE_SAVE_AS = 4,
    IDM_FILE_EXIT = 5,
    IDM_EDIT_UNDO = 6,
    IDM_EDIT_CUT = 7,
    IDM_EDIT_COPY = 8,
    IDM_EDIT_PASTE = 9,
    IDM_EDIT_REDO = 10,
    IDM_FORMAT_FONT = 11,
    IDM_FORMAT_DARK_MODE = 12
};

enum class FileEncoding {
    Utf8Bom,
    Utf8NoBom,
    Utf16LeBom,
    Utf16BeBom,
    Ansi
};

enum class EolStyle {
    CRLF,
    LF
};

FileEncoding currentFileEncoding = FileEncoding::Utf8Bom;
EolStyle currentEolStyle = EolStyle::CRLF;
LOGFONTW editorLogFont = {};

struct DarkMenuItem {
    UINT commandId;
    const wchar_t* label;
    const wchar_t* shortcut;
    bool separator;
    bool checkable;
};

const DarkMenuItem FILE_MENU_ITEMS[] = {
    { IDM_FILE_NEW,     L"New",     L"Ctrl+N",       false, false },
    { IDM_FILE_OPEN,    L"Open",    L"Ctrl+O",       false, false },
    { IDM_FILE_SAVE,    L"Save",    L"Ctrl+S",       false, false },
    { IDM_FILE_SAVE_AS, L"Save As", L"Ctrl+Shift+S", false, false },
    { 0,                NULL,        NULL,             true,  false },
    { IDM_FILE_EXIT,    L"Exit",    L"Ctrl+Q",       false, false }
};

const DarkMenuItem EDIT_MENU_ITEMS[] = {
    { IDM_EDIT_UNDO,  L"Undo",  L"Ctrl+Z", false, false },
    { IDM_EDIT_REDO,  L"Redo",  L"Ctrl+Y", false, false },
    { 0,              NULL,      NULL,      true,  false },
    { IDM_EDIT_CUT,   L"Cut",   L"Ctrl+X", false, false },
    { IDM_EDIT_COPY,  L"Copy",  L"Ctrl+C", false, false },
    { IDM_EDIT_PASTE, L"Paste", L"Ctrl+V", false, false }
};

const DarkMenuItem FORMAT_MENU_ITEMS[] = {
    { IDM_FORMAT_FONT,      L"Font...",   NULL, false, false },
    { IDM_FORMAT_DARK_MODE, L"Dark Mode", NULL, false, true  }
};

struct TopMenuDefinition {
    const wchar_t* title;
    const DarkMenuItem* items;
    int itemCount;
    RECT rect;
};

TopMenuDefinition g_topMenus[] = {
    { L"File",   FILE_MENU_ITEMS,   _countof(FILE_MENU_ITEMS),   {0, 0, 0, 0} },
    { L"Edit",   EDIT_MENU_ITEMS,   _countof(EDIT_MENU_ITEMS),   {0, 0, 0, 0} },
    { L"Format", FORMAT_MENU_ITEMS, _countof(FORMAT_MENU_ITEMS), {0, 0, 0, 0} }
};

constexpr int TOP_MENU_COUNT = _countof(g_topMenus);
int g_hoverTopMenu = -1;
int g_activeTopMenu = -1;
int g_hoverPopupItem = -1;

void UpdateWindowTitle(HWND hwnd);
void ApplyEditorTheme(HWND hwnd);
void ClosePopupMenu();
void ShowPopupMenuForTopIndex(HWND owner, int menuIndex);
bool ShowDarkFontDialog(HWND owner, LOGFONTW& selectedLogFont);
LRESULT CALLBACK LargeFileViewProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
bool OpenLargeFileDocument(HWND owner, const std::wstring& path);
void CloseLargeFileDocument();
void ShowRichEditSurface();
void ShowLargeFileSurface();
void LargeFileUpdateCaret(HWND hwnd);

void FillSolid(HDC hdc, const RECT& rc, COLORREF color) {
    HBRUSH brush = CreateSolidBrush(color);
    FillRect(hdc, &rc, brush);
    DeleteObject(brush);
}

void FrameRectSolid(HDC hdc, const RECT& rc, COLORREF color) {
    HBRUSH brush = CreateSolidBrush(color);
    FrameRect(hdc, &rc, brush);
    DeleteObject(brush);
}

void FillRoundRectSolid(HDC hdc, const RECT& rc, COLORREF color, int radius) {
    HBRUSH brush = CreateSolidBrush(color);
    HPEN pen = CreatePen(PS_SOLID, 1, color);

    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
    HPEN oldPen = (HPEN)SelectObject(hdc, pen);

    RoundRect(hdc, rc.left, rc.top, rc.right, rc.bottom, radius, radius);

    SelectObject(hdc, oldPen);
    SelectObject(hdc, oldBrush);
    DeleteObject(pen);
    DeleteObject(brush);
}

void FrameRoundRectSolid(HDC hdc, const RECT& rc, COLORREF color, int radius) {
    HPEN pen = CreatePen(PS_SOLID, 1, color);
    HPEN oldPen = (HPEN)SelectObject(hdc, pen);
    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));

    RoundRect(hdc, rc.left, rc.top, rc.right, rc.bottom, radius, radius);

    SelectObject(hdc, oldBrush);
    SelectObject(hdc, oldPen);
    DeleteObject(pen);
}

void ApplyRoundedWindowRegion(HWND hwnd, int radius) {
    if (!hwnd) return;

    RECT rc;
    GetClientRect(hwnd, &rc);

    HRGN region = CreateRoundRectRgn(
        0,
        0,
        rc.right + 1,
        rc.bottom + 1,
        radius,
        radius
    );

    SetWindowRgn(hwnd, region, TRUE);
}

void SelectUiFont(HDC hdc) {
    if (hUiFont) {
        SelectObject(hdc, hUiFont);
    } else {
        SelectObject(hdc, GetStockObject(DEFAULT_GUI_FONT));
    }
}

int GetSystemDpiY() {
    HDC screenDc = GetDC(NULL);
    if (!screenDc) return 96;

    int dpiY = GetDeviceCaps(screenDc, LOGPIXELSY);
    ReleaseDC(NULL, screenDc);

    return (dpiY > 0) ? dpiY : 96;
}

int PointSizeFromLogFont(const LOGFONTW& lf) {
    int dpiY = GetSystemDpiY();
    int height = lf.lfHeight;

    if (height == 0) {
        return 11;
    }

    if (height < 0) {
        height = -height;
    }

    int points = MulDiv(height, 72, dpiY);
    return points > 0 ? points : 11;
}

void InitializeDefaultEditorLogFont(LOGFONTW& lf) {
    ZeroMemory(&lf, sizeof(lf));

    lf.lfHeight = -MulDiv(11, GetSystemDpiY(), 72);
    lf.lfWeight = FW_NORMAL;
    lf.lfCharSet = DEFAULT_CHARSET;
    lf.lfOutPrecision = OUT_DEFAULT_PRECIS;
    lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;
    lf.lfQuality = DEFAULT_QUALITY;
    lf.lfPitchAndFamily = FF_MODERN | FIXED_PITCH;

    lstrcpynW(lf.lfFaceName, L"Consolas", LF_FACESIZE);
}

HFONT CreateUiFont() {
    LOGFONTW lf = {};
    lf.lfHeight = -MulDiv(9, GetSystemDpiY(), 72);
    lf.lfWeight = FW_NORMAL;
    lf.lfCharSet = DEFAULT_CHARSET;
    lf.lfQuality = CLEARTYPE_QUALITY;
    lf.lfPitchAndFamily = FF_SWISS;
    lstrcpynW(lf.lfFaceName, L"Segoe UI", LF_FACESIZE);
    return CreateFontIndirectW(&lf);
}

bool GetEditorModifiedFlag() {
    if (g_largeFileMode) return false;
    if (!hwndEdit) return isModified;
    return SendMessage(hwndEdit, EM_GETMODIFY, 0, 0) != 0;
}

void SetEditorModifiedFlag(bool modified) {
    isModified = modified;
    if (hwndEdit && !g_largeFileMode) {
        SendMessage(hwndEdit, EM_SETMODIFY, modified ? TRUE : FALSE, 0);
    }
}

void SyncModifiedStateFromControl(HWND hwnd) {
    bool previous = isModified;
    isModified = GetEditorModifiedFlag();
    if (isModified != previous) {
        UpdateWindowTitle(hwnd);
    }
}

bool ApplyEditorFont(HWND hwndOwner, const LOGFONTW& lf) {
    HFONT newFont = CreateFontIndirectW(&lf);
    if (!newFont) {
        MessageBoxW(
            hwndOwner,
            L"Failed to apply the selected font.",
            L"Error",
            MB_OK | MB_ICONERROR
        );
        return false;
    }

    HFONT oldFont = hFontPrimary;
    hFontPrimary = newFont;
    editorLogFont = lf;

    if (hwndEdit) {
        SendMessage(hwndEdit, WM_SETFONT, (WPARAM)hFontPrimary, TRUE);
    }

    if (hwndLargeView) {
        SendMessage(hwndLargeView, WM_SETFONT, (WPARAM)hFontPrimary, TRUE);
    }

    if (oldFont) {
        DeleteObject(oldFont);
    }

    return true;
}

void ChooseEditorFont(HWND hwnd) {
    LOGFONTW selected = editorLogFont;
    if (ShowDarkFontDialog(hwnd, selected)) {
        ApplyEditorFont(hwnd, selected);
        ApplyEditorTheme(hwnd);
    }
}

std::wstring GetWin32ErrorMessage(DWORD errorCode) {
    LPWSTR buffer = nullptr;

    DWORD size = FormatMessageW(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        errorCode,
        0,
        (LPWSTR)&buffer,
        0,
        NULL
    );

    if (size == 0 || buffer == nullptr) {
        return L"Unknown error.";
    }

    std::wstring message(buffer, size);
    LocalFree(buffer);

    while (!message.empty() &&
           (message.back() == L'\r' || message.back() == L'\n')) {
        message.pop_back();
    }

    return message;
}

void ShowEncodingError(
    HWND hwnd,
    const wchar_t* operation,
    DWORD errorCode,
    const wchar_t* nextStep
) {
    std::wstringstream ss;

    ss << L"Unable to " << operation << L".\n\n"
       << L"Windows error " << errorCode << L": "
       << GetWin32ErrorMessage(errorCode) << L"\n\n"
       << nextStep;

    MessageBoxW(
        hwnd,
        ss.str().c_str(),
        L"Encoding Error",
        MB_OK | MB_ICONERROR
    );
}

bool Utf8ToWstring(
    const std::string& str,
    std::wstring& out,
    HWND hwnd,
    bool showErrors = true
) {
    out.clear();

    if (str.empty()) return true;

    int sizeNeeded = MultiByteToWideChar(
        CP_UTF8,
        MB_ERR_INVALID_CHARS,
        str.data(),
        (int)str.size(),
        NULL,
        0
    );

    if (sizeNeeded <= 0) {
        if (showErrors) {
            ShowEncodingError(
                hwnd,
                L"decode file text as UTF-8",
                GetLastError(),
                L"The file may use a different encoding or contain invalid UTF-8 bytes."
            );
        }
        return false;
    }

    std::wstring wstr(sizeNeeded, 0);

    int converted = MultiByteToWideChar(
        CP_UTF8,
        MB_ERR_INVALID_CHARS,
        str.data(),
        (int)str.size(),
        &wstr[0],
        sizeNeeded
    );

    if (converted <= 0) {
        if (showErrors) {
            ShowEncodingError(
                hwnd,
                L"decode file text as UTF-8",
                GetLastError(),
                L"Try reopening the file after converting it to UTF-8."
            );
        }
        return false;
    }

    out.swap(wstr);
    return true;
}

bool WstringToUtf8(const std::wstring& wstr, std::string& out, HWND hwnd) {
    out.clear();

    if (wstr.empty()) return true;

    int sizeNeeded = WideCharToMultiByte(
        CP_UTF8,
        0,
        wstr.data(),
        (int)wstr.size(),
        NULL,
        0,
        NULL,
        NULL
    );

    if (sizeNeeded <= 0) {
        ShowEncodingError(
            hwnd,
            L"encode text as UTF-8",
            GetLastError(),
            L"Try removing unsupported characters and save again."
        );
        return false;
    }

    std::string utf8(sizeNeeded, 0);

    int converted = WideCharToMultiByte(
        CP_UTF8,
        0,
        wstr.data(),
        (int)wstr.size(),
        &utf8[0],
        sizeNeeded,
        NULL,
        NULL
    );

    if (converted <= 0) {
        ShowEncodingError(
            hwnd,
            L"encode text as UTF-8",
            GetLastError(),
            L"Try removing unsupported characters and save again."
        );
        return false;
    }

    out.swap(utf8);
    return true;
}

bool AnsiToWstring(const std::string& str, std::wstring& out, HWND hwnd) {
    out.clear();

    if (str.empty()) return true;

    int sizeNeeded = MultiByteToWideChar(
        CP_ACP,
        0,
        str.data(),
        (int)str.size(),
        NULL,
        0
    );

    if (sizeNeeded <= 0) {
        ShowEncodingError(
            hwnd,
            L"decode file text using the system ANSI code page",
            GetLastError(),
            L"Try reopening the file after converting it to UTF-8."
        );
        return false;
    }

    std::wstring wstr(sizeNeeded, 0);

    int converted = MultiByteToWideChar(
        CP_ACP,
        0,
        str.data(),
        (int)str.size(),
        &wstr[0],
        sizeNeeded
    );

    if (converted <= 0) {
        ShowEncodingError(
            hwnd,
            L"decode file text using the system ANSI code page",
            GetLastError(),
            L"Try reopening the file after converting it to UTF-8."
        );
        return false;
    }

    out.swap(wstr);
    return true;
}

bool WstringToAnsi(const std::wstring& wstr, std::string& out, HWND hwnd) {
    out.clear();

    if (wstr.empty()) return true;

    int sizeNeeded = WideCharToMultiByte(
        CP_ACP,
        WC_NO_BEST_FIT_CHARS,
        wstr.data(),
        (int)wstr.size(),
        NULL,
        0,
        NULL,
        NULL
    );

    if (sizeNeeded <= 0) {
        ShowEncodingError(
            hwnd,
            L"encode text using the system ANSI code page",
            GetLastError(),
            L"Try saving as UTF-8 to preserve all characters."
        );
        return false;
    }

    std::string ansi(sizeNeeded, 0);
    BOOL usedDefaultChar = FALSE;

    int converted = WideCharToMultiByte(
        CP_ACP,
        WC_NO_BEST_FIT_CHARS,
        wstr.data(),
        (int)wstr.size(),
        &ansi[0],
        sizeNeeded,
        NULL,
        &usedDefaultChar
    );

    if (converted <= 0) {
        ShowEncodingError(
            hwnd,
            L"encode text using the system ANSI code page",
            GetLastError(),
            L"Try saving as UTF-8 to preserve all characters."
        );
        return false;
    }

    if (usedDefaultChar) {
        MessageBoxW(
            hwnd,
            L"Unable to encode one or more characters in the current ANSI code page.\n\n"
            L"Try saving this file as UTF-8.",
            L"Encoding Error",
            MB_OK | MB_ICONERROR
        );
        return false;
    }

    out.swap(ansi);
    return true;
}

bool Utf16BytesToWstring(
    const std::string& bytes,
    bool littleEndian,
    std::wstring& out,
    HWND hwnd
) {
    out.clear();

    if (bytes.empty()) return true;

    if ((bytes.size() % 2) != 0) {
        MessageBoxW(
            hwnd,
            L"Unable to decode UTF-16 text because the file has an odd number of bytes.",
            L"Encoding Error",
            MB_OK | MB_ICONERROR
        );
        return false;
    }

    std::wstring wstr(bytes.size() / 2, 0);

    for (size_t i = 0, j = 0; i < bytes.size(); i += 2, ++j) {
        unsigned char b0 = static_cast<unsigned char>(bytes[i]);
        unsigned char b1 = static_cast<unsigned char>(bytes[i + 1]);

        unsigned short value = littleEndian
            ? static_cast<unsigned short>(b0 | (b1 << 8))
            : static_cast<unsigned short>((b0 << 8) | b1);

        wstr[j] = static_cast<wchar_t>(value);
    }

    out.swap(wstr);
    return true;
}

void WstringToUtf16Bytes(
    const std::wstring& wstr,
    bool littleEndian,
    std::string& out
) {
    out.clear();

    if (wstr.empty()) return;

    out.reserve(wstr.size() * 2);

    for (wchar_t ch : wstr) {
        unsigned short value = static_cast<unsigned short>(ch);

        char low = static_cast<char>(value & 0xFF);
        char high = static_cast<char>((value >> 8) & 0xFF);

        if (littleEndian) {
            out.push_back(low);
            out.push_back(high);
        } else {
            out.push_back(high);
            out.push_back(low);
        }
    }
}

EolStyle DetectEolStyle(const std::wstring& text) {
    size_t crlfCount = 0;
    size_t lfCount = 0;

    for (size_t i = 0; i < text.size(); ++i) {
        if (text[i] == L'\n') {
            if (i > 0 && text[i - 1] == L'\r') {
                ++crlfCount;
            } else {
                ++lfCount;
            }
        }
    }

    if (lfCount > 0 && crlfCount == 0) {
        return EolStyle::LF;
    }

    return EolStyle::CRLF;
}

std::wstring NormalizeEolForSave(const std::wstring& text, EolStyle style) {
    std::wstring lfNormalized;
    lfNormalized.reserve(text.size());

    for (size_t i = 0; i < text.size(); ++i) {
        wchar_t ch = text[i];

        if (ch == L'\r') {
            if (i + 1 < text.size() && text[i + 1] == L'\n') {
                ++i;
            }
            lfNormalized.push_back(L'\n');
        } else {
            lfNormalized.push_back(ch);
        }
    }

    if (style == EolStyle::LF) {
        return lfNormalized;
    }

    std::wstring out;
    out.reserve(lfNormalized.size() + 8);

    for (wchar_t ch : lfNormalized) {
        if (ch == L'\n') {
            out.push_back(L'\r');
            out.push_back(L'\n');
        } else {
            out.push_back(ch);
        }
    }

    return out;
}

bool DecodeFileContent(
    const std::string& bytes,
    std::wstring& out,
    FileEncoding& outEncoding,
    HWND hwnd
) {
    out.clear();

    if (bytes.size() >= 3 &&
        static_cast<unsigned char>(bytes[0]) == 0xEF &&
        static_cast<unsigned char>(bytes[1]) == 0xBB &&
        static_cast<unsigned char>(bytes[2]) == 0xBF) {
        outEncoding = FileEncoding::Utf8Bom;
        return Utf8ToWstring(bytes.substr(3), out, hwnd, true);
    }

    if (bytes.size() >= 2 &&
        static_cast<unsigned char>(bytes[0]) == 0xFF &&
        static_cast<unsigned char>(bytes[1]) == 0xFE) {
        outEncoding = FileEncoding::Utf16LeBom;
        return Utf16BytesToWstring(bytes.substr(2), true, out, hwnd);
    }

    if (bytes.size() >= 2 &&
        static_cast<unsigned char>(bytes[0]) == 0xFE &&
        static_cast<unsigned char>(bytes[1]) == 0xFF) {
        outEncoding = FileEncoding::Utf16BeBom;
        return Utf16BytesToWstring(bytes.substr(2), false, out, hwnd);
    }

    std::wstring utf8Text;

    if (Utf8ToWstring(bytes, utf8Text, hwnd, false)) {
        outEncoding = FileEncoding::Utf8NoBom;
        out.swap(utf8Text);
        return true;
    }

    outEncoding = FileEncoding::Ansi;
    return AnsiToWstring(bytes, out, hwnd);
}

bool EncodeDocumentText(
    const std::wstring& text,
    FileEncoding encoding,
    std::string& out,
    HWND hwnd
) {
    out.clear();

    std::string payload;

    switch (encoding) {
    case FileEncoding::Utf8Bom:
        if (!WstringToUtf8(text, payload, hwnd)) return false;
        out.assign("\xEF\xBB\xBF", 3);
        out += payload;
        return true;

    case FileEncoding::Utf8NoBom:
        return WstringToUtf8(text, out, hwnd);

    case FileEncoding::Utf16LeBom:
        out.assign("\xFF\xFE", 2);
        WstringToUtf16Bytes(text, true, payload);
        out += payload;
        return true;

    case FileEncoding::Utf16BeBom:
        out.assign("\xFE\xFF", 2);
        WstringToUtf16Bytes(text, false, payload);
        out += payload;
        return true;

    case FileEncoding::Ansi:
        return WstringToAnsi(text, out, hwnd);
    }

    return false;
}

void UpdateWindowTitle(HWND hwnd) {
    std::wstring title = (isModified ? L"*" : L"")
        + currentFileName
        + (g_largeFileMode ? L" [Large File View]" : L"")
        + L" - Notepad";

    SetWindowTextW(hwnd, title.c_str());
}

void ApplyWindowFrameTheme(HWND hwnd) {
    if (!hwnd) return;

    BOOL dark = darkModeEnabled ? TRUE : FALSE;

    HRESULT hr = DwmSetWindowAttribute(
        hwnd,
        DWMWA_USE_IMMERSIVE_DARK_MODE,
        &dark,
        sizeof(dark)
    );
    if (FAILED(hr)) {
        const DWORD DWMWA_USE_IMMERSIVE_DARK_MODE_OLD = 19;

        DwmSetWindowAttribute(
            hwnd,
            DWMWA_USE_IMMERSIVE_DARK_MODE_OLD,
            &dark,
            sizeof(dark)
        );
    }

    COLORREF captionColor = darkModeEnabled
        ? DARK_FRAME_BG
        : (COLORREF)DWMWA_COLOR_DEFAULT;

    COLORREF textColor = darkModeEnabled
        ? DARK_FRAME_TEXT
        : (COLORREF)DWMWA_COLOR_DEFAULT;

    COLORREF borderColor = darkModeEnabled
        ? DARK_FRAME_BORDER
        : (COLORREF)DWMWA_COLOR_DEFAULT;

    DwmSetWindowAttribute(
        hwnd,
        DWMWA_CAPTION_COLOR,
        &captionColor,
        sizeof(captionColor)
    );

    DwmSetWindowAttribute(
        hwnd,
        DWMWA_TEXT_COLOR,
        &textColor,
        sizeof(textColor)
    );

    DwmSetWindowAttribute(
        hwnd,
        DWMWA_BORDER_COLOR,
        &borderColor,
        sizeof(borderColor)
    );
}

void ApplyEditorTheme(HWND hwnd) {
    ApplyWindowFrameTheme(hwnd);

    if (hwndMenuBar) {
        InvalidateRect(hwndMenuBar, NULL, TRUE);
    }

    if (hwndPopupMenu) {
        InvalidateRect(hwndPopupMenu, NULL, TRUE);
    }

    if (hwndLargeView) {
        SendMessage(hwndLargeView, WM_SETFONT, (WPARAM)hFontPrimary, TRUE);
        InvalidateRect(hwndLargeView, NULL, TRUE);
    }

    if (g_largeFileMode || !hwndEdit) {
        return;
    }

    COLORREF bg = EditorBg();
    COLORREF text = EditorText();

    BOOL wasModified = (BOOL)SendMessage(hwndEdit, EM_GETMODIFY, 0, 0);

    CHARRANGE selection = {};
    SendMessage(hwndEdit, EM_EXGETSEL, 0, (LPARAM)&selection);

    bool previousSuppress = suppressDirtyTracking;
    suppressDirtyTracking = true;

    SendMessage(hwndEdit, EM_SETBKGNDCOLOR, 0, (LPARAM)bg);

    CHARFORMAT2W cf = {};
    cf.cbSize = sizeof(cf);
    cf.dwMask = CFM_COLOR;
    cf.crTextColor = text;

    SendMessage(hwndEdit, EM_SETCHARFORMAT, SCF_ALL, (LPARAM)&cf);
    SendMessage(hwndEdit, EM_SETCHARFORMAT, SCF_DEFAULT, (LPARAM)&cf);

    SendMessage(hwndEdit, EM_EXSETSEL, 0, (LPARAM)&selection);
    SendMessage(hwndEdit, EM_SETMODIFY, wasModified, 0);

    suppressDirtyTracking = previousSuppress;
    isModified = wasModified != FALSE;

    InvalidateRect(hwndEdit, NULL, TRUE);
}

void LayoutMenuBar(HWND hwnd) {
    HDC hdc = GetDC(hwnd);
    if (!hdc) return;

    SelectUiFont(hdc);

    int x = 0;
    for (int i = 0; i < TOP_MENU_COUNT; ++i) {
        SIZE size = {};
        GetTextExtentPoint32W(
            hdc,
            g_topMenus[i].title,
            lstrlenW(g_topMenus[i].title),
            &size
        );

        int width = IMax(size.cx + 20, 36);
        g_topMenus[i].rect = { x, 0, x + width, MENU_BAR_HEIGHT };
        x += width;
    }

    ReleaseDC(hwnd, hdc);
}

int HitTestTopMenu(POINT pt) {
    for (int i = 0; i < TOP_MENU_COUNT; ++i) {
        if (PtInRect(&g_topMenus[i].rect, pt)) {
            return i;
        }
    }
    return -1;
}

void PaintMenuBar(HWND hwnd, HDC hdc) {
    RECT rc;
    GetClientRect(hwnd, &rc);

    FillSolid(hdc, rc, MenuBg());

    SelectUiFont(hdc);
    SetBkMode(hdc, TRANSPARENT);

    for (int i = 0; i < TOP_MENU_COUNT; ++i) {
        RECT itemRect = g_topMenus[i].rect;
        RECT fillRect = itemRect;
        if (!darkModeEnabled) {
            InflateRect(&fillRect, -1, -2);
        }

        if (i == g_activeTopMenu) {
            FillRoundRectSolid(hdc, fillRect, MenuActive(), MENU_CORNER_RADIUS);
        } else if (i == g_hoverTopMenu) {
            FillRoundRectSolid(hdc, fillRect, MenuHover(), MENU_CORNER_RADIUS);
        }

        SetTextColor(hdc, UiText());
        RECT textRect = itemRect;
        if (!darkModeEnabled) {
            textRect.top -= 1;
        }
        DrawTextW(
            hdc,
            g_topMenus[i].title,
            -1,
            &textRect,
            DT_CENTER | DT_VCENTER | DT_SINGLELINE
        );
    }

    RECT bottom = rc;
    bottom.top = rc.bottom - 1;
    FillSolid(hdc, bottom, MenuBorder());
}

int CalculatePopupHeight(int menuIndex) {
    int height = 0;
    const TopMenuDefinition& menu = g_topMenus[menuIndex];

    for (int i = 0; i < menu.itemCount; ++i) {
        height += menu.items[i].separator ? POPUP_SEPARATOR_HEIGHT : POPUP_ROW_HEIGHT;
    }

    return height + 4;
}

int CalculatePopupWidth(HWND owner, int menuIndex) {
    HDC hdc = GetDC(owner);
    if (!hdc) return POPUP_MIN_WIDTH;

    SelectUiFont(hdc);

    int width = POPUP_MIN_WIDTH;
    const TopMenuDefinition& menu = g_topMenus[menuIndex];

    for (int i = 0; i < menu.itemCount; ++i) {
        if (menu.items[i].separator) continue;

        SIZE labelSize = {};
        SIZE shortcutSize = {};

        if (menu.items[i].label) {
            GetTextExtentPoint32W(
                hdc,
                menu.items[i].label,
                lstrlenW(menu.items[i].label),
                &labelSize
            );
        }

        if (menu.items[i].shortcut) {
            GetTextExtentPoint32W(
                hdc,
                menu.items[i].shortcut,
                lstrlenW(menu.items[i].shortcut),
                &shortcutSize
            );
        }

        width = IMax(width, labelSize.cx + shortcutSize.cx + 76);
    }

    ReleaseDC(owner, hdc);
    return width;
}

int HitTestPopupItem(int menuIndex, int y) {
    const TopMenuDefinition& menu = g_topMenus[menuIndex];
    int cursorY = 2;

    for (int i = 0; i < menu.itemCount; ++i) {
        int rowHeight = menu.items[i].separator ? POPUP_SEPARATOR_HEIGHT : POPUP_ROW_HEIGHT;
        RECT row = { 3, cursorY, 32767, cursorY + rowHeight };

        if (y >= row.top && y < row.bottom) {
            return menu.items[i].separator ? -1 : i;
        }

        cursorY += rowHeight;
    }

    return -1;
}

bool IsMenuItemChecked(UINT commandId) {
    if (commandId == IDM_FORMAT_DARK_MODE) {
        return darkModeEnabled;
    }
    return false;
}

void DrawCheckmark(HDC hdc, const RECT& rc) {
    HPEN pen = CreatePen(PS_SOLID, 2, UiText());
    HPEN oldPen = (HPEN)SelectObject(hdc, pen);

    int midY = rc.top + ((rc.bottom - rc.top) / 2);
    int x1 = rc.left + 7;
    int y1 = midY;
    int x2 = rc.left + 12;
    int y2 = midY + 5;
    int x3 = rc.right - 6;
    int y3 = rc.top + 7;

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);

    SelectObject(hdc, oldPen);
    DeleteObject(pen);
}

void PaintPopupMenu(HWND hwnd, HDC hdc, int menuIndex) {
    RECT rc;
    GetClientRect(hwnd, &rc);

    FillRoundRectSolid(hdc, rc, MenuBg(), POPUP_CORNER_RADIUS);
    RECT frameRect = rc;
    frameRect.right -= 1;
    frameRect.bottom -= 1;
    FrameRoundRectSolid(hdc, frameRect, MenuBorder(), POPUP_CORNER_RADIUS);

    SelectUiFont(hdc);
    SetBkMode(hdc, TRANSPARENT);

    const TopMenuDefinition& menu = g_topMenus[menuIndex];
    int y = 2;

    for (int i = 0; i < menu.itemCount; ++i) {
        const DarkMenuItem& item = menu.items[i];

        if (item.separator) {
            RECT sep = { 8, y + 3, rc.right - 8, y + 4 };
            FillSolid(hdc, sep, MenuBorder());
            y += POPUP_SEPARATOR_HEIGHT;
            continue;
        }

        RECT row = { 3, y, rc.right - 3, y + POPUP_ROW_HEIGHT };

        if (i == g_hoverPopupItem) {
            FillRoundRectSolid(hdc, row, MenuHover(), MENU_CORNER_RADIUS);
        }

        RECT checkRect = { row.left + 5, row.top + 3, row.left + 23, row.bottom - 3 };
        if (item.checkable && IsMenuItemChecked(item.commandId)) {
            DrawCheckmark(hdc, checkRect);
        }

        SetTextColor(hdc, UiText());
        RECT textRect = row;
        textRect.left += 29;
        textRect.right -= 68;
        DrawTextW(
            hdc,
            item.label ? item.label : L"",
            -1,
            &textRect,
            DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS
        );

        if (item.shortcut) {
            SetTextColor(hdc, UiMutedText());
            RECT shortcutRect = row;
            shortcutRect.left = IMax(row.left + 82, row.right - 118);
            shortcutRect.right -= 10;
            DrawTextW(
                hdc,
                item.shortcut,
                -1,
                &shortcutRect,
                DT_RIGHT | DT_VCENTER | DT_SINGLELINE
            );
        }

        y += POPUP_ROW_HEIGHT;
    }
}

void ClosePopupMenu() {
    HWND popup = hwndPopupMenu;
    hwndPopupMenu = NULL;
    g_hoverPopupItem = -1;
    g_activeTopMenu = -1;

    if (popup && IsWindow(popup)) {
        DestroyWindow(popup);
    }

    if (hwndMenuBar) {
        InvalidateRect(hwndMenuBar, NULL, TRUE);
    }
}

void ExecuteMenuCommand(UINT commandId) {
    ClosePopupMenu();
    if (g_hwndMain && commandId != 0) {
        PostMessageW(g_hwndMain, WM_COMMAND, MAKEWPARAM(commandId, 0), 0);
    }
}

void ShowPopupMenuForTopIndex(HWND owner, int menuIndex) {
    if (menuIndex < 0 || menuIndex >= TOP_MENU_COUNT) return;

    if (hwndPopupMenu) {
        HWND oldPopup = hwndPopupMenu;
        hwndPopupMenu = NULL;
        DestroyWindow(oldPopup);
    }

    g_activeTopMenu = menuIndex;
    g_hoverPopupItem = -1;

    if (hwndMenuBar) {
        InvalidateRect(hwndMenuBar, NULL, TRUE);
    }

    RECT menuRect = g_topMenus[menuIndex].rect;
    POINT pt = { menuRect.left, menuRect.bottom };
    ClientToScreen(hwndMenuBar, &pt);

    int width = CalculatePopupWidth(owner, menuIndex);
    int height = CalculatePopupHeight(menuIndex);

    hwndPopupMenu = CreateWindowExW(
        WS_EX_TOOLWINDOW | WS_EX_TOPMOST,
        POPUP_MENU_CLASS_NAME,
        L"",
        WS_POPUP,
        pt.x,
        pt.y,
        width,
        height,
        owner,
        NULL,
        g_hInstance,
        (LPVOID)(INT_PTR)menuIndex
    );

    if (!hwndPopupMenu) {
        g_activeTopMenu = -1;
        return;
    }

    ApplyWindowFrameTheme(hwndPopupMenu);
    ShowWindow(hwndPopupMenu, SW_SHOWNOACTIVATE);
    SetWindowPos(hwndPopupMenu, HWND_TOPMOST, pt.x, pt.y, width, height, SWP_SHOWWINDOW);
    SetFocus(hwndPopupMenu);
}

LRESULT CALLBACK MenuBarProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE:
        LayoutMenuBar(hwnd);
        return 0;

    case WM_SIZE:
        LayoutMenuBar(hwnd);
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;

    case WM_MOUSEMOVE: {
        POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
        int hit = HitTestTopMenu(pt);

        if (hit != g_hoverTopMenu) {
            g_hoverTopMenu = hit;
            InvalidateRect(hwnd, NULL, TRUE);
        }

        TRACKMOUSEEVENT tme = {};
        tme.cbSize = sizeof(tme);
        tme.dwFlags = TME_LEAVE;
        tme.hwndTrack = hwnd;
        TrackMouseEvent(&tme);

        if (hwndPopupMenu && hit >= 0 && hit != g_activeTopMenu) {
            ShowPopupMenuForTopIndex(g_hwndMain, hit);
        }
    } return 0;

    case WM_MOUSELEAVE:
        g_hoverTopMenu = -1;
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;

    case WM_LBUTTONDOWN: {
        POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
        int hit = HitTestTopMenu(pt);

        if (hit >= 0) {
            if (hwndPopupMenu && g_activeTopMenu == hit) {
                ClosePopupMenu();
            } else {
                ShowPopupMenuForTopIndex(g_hwndMain, hit);
            }
        } else {
            ClosePopupMenu();
        }
    } return 0;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        LayoutMenuBar(hwnd);
        PaintMenuBar(hwnd, hdc);
        EndPaint(hwnd, &ps);
    } return 0;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

LRESULT CALLBACK PopupMenuProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    int menuIndex = (int)(INT_PTR)GetWindowLongPtrW(hwnd, GWLP_USERDATA);

    switch (msg) {
    case WM_NCCREATE: {
        CREATESTRUCTW* cs = reinterpret_cast<CREATESTRUCTW*>(lParam);
        SetWindowLongPtrW(hwnd, GWLP_USERDATA, (LONG_PTR)cs->lpCreateParams);
    } return TRUE;

    case WM_CREATE:
        ApplyRoundedWindowRegion(hwnd, POPUP_CORNER_RADIUS);
        return 0;

    case WM_SIZE:
        ApplyRoundedWindowRegion(hwnd, POPUP_CORNER_RADIUS);
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;

    case WM_MOUSEMOVE: {
        int y = GET_Y_LPARAM(lParam);
        int hit = HitTestPopupItem(menuIndex, y);

        if (hit != g_hoverPopupItem) {
            g_hoverPopupItem = hit;
            InvalidateRect(hwnd, NULL, TRUE);
        }
    } return 0;

    case WM_LBUTTONUP: {
        int y = GET_Y_LPARAM(lParam);
        int hit = HitTestPopupItem(menuIndex, y);

        if (hit >= 0) {
            ExecuteMenuCommand(g_topMenus[menuIndex].items[hit].commandId);
        }
    } return 0;

    case WM_KEYDOWN:
        if (wParam == VK_ESCAPE) {
            ClosePopupMenu();
            return 0;
        }

        if (wParam == VK_DOWN || wParam == VK_UP) {
            const TopMenuDefinition& menu = g_topMenus[menuIndex];
            int direction = (wParam == VK_DOWN) ? 1 : -1;
            int start = g_hoverPopupItem;

            for (int step = 0; step < menu.itemCount; ++step) {
                int candidate;
                if (start < 0) {
                    candidate = (direction > 0) ? 0 : menu.itemCount - 1;
                } else {
                    candidate = (start + direction + menu.itemCount) % menu.itemCount;
                }

                if (!menu.items[candidate].separator) {
                    g_hoverPopupItem = candidate;
                    InvalidateRect(hwnd, NULL, TRUE);
                    return 0;
                }

                start = candidate;
            }
            return 0;
        }

        if (wParam == VK_RETURN && g_hoverPopupItem >= 0) {
            ExecuteMenuCommand(g_topMenus[menuIndex].items[g_hoverPopupItem].commandId);
            return 0;
        }
        break;

    case WM_ACTIVATE:
        if (LOWORD(wParam) == WA_INACTIVE) {
            ClosePopupMenu();
            return 0;
        }
        break;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        PaintPopupMenu(hwnd, hdc, menuIndex);
        EndPaint(hwnd, &ps);
    } return 0;

    case WM_DESTROY:
        if (hwndPopupMenu == hwnd) {
            hwndPopupMenu = NULL;
            g_hoverPopupItem = -1;
            g_activeTopMenu = -1;
            if (hwndMenuBar) {
                InvalidateRect(hwndMenuBar, NULL, TRUE);
            }
        }
        return 0;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

struct FontDialogState {
    HWND owner;
    bool accepted;
    std::vector<std::wstring> allFaces;
    std::vector<std::wstring> faces;
    std::vector<int> sizes;
    int selectedFace;
    int selectedSize;
    int fontScroll;
    int sizeScroll;
    int activeList;
    bool searchActive;
    int hoverButton;
    std::wstring fontSearch;
    LOGFONTW selectedLogFont;
    HFONT sampleFont;
    RECT searchRect;
    RECT fontListRect;
    RECT sizeListRect;
    RECT sampleRect;
    RECT okRect;
    RECT cancelRect;
};

int CALLBACK EnumFontFamiliesProc(
    const LOGFONTW* lpelfe,
    const TEXTMETRICW*,
    DWORD,
    LPARAM lParam
) {
    std::set<std::wstring>* faces = reinterpret_cast<std::set<std::wstring>*>(lParam);
    if (!lpelfe || !faces) return 1;

    const wchar_t* name = lpelfe->lfFaceName;
    if (!name || !name[0]) return 1;

    if (name[0] == L'@') return 1;

    faces->insert(name);
    return 1;
}

std::vector<std::wstring> EnumerateFontFaces() {
    std::set<std::wstring> faceSet;

    HDC hdc = GetDC(NULL);
    if (hdc) {
        LOGFONTW lf = {};
        lf.lfCharSet = DEFAULT_CHARSET;
        EnumFontFamiliesExW(hdc, &lf, EnumFontFamiliesProc, (LPARAM)&faceSet, 0);
        ReleaseDC(NULL, hdc);
    }

    if (faceSet.empty()) {
        faceSet.insert(L"Consolas");
        faceSet.insert(L"Cascadia Mono");
        faceSet.insert(L"Segoe UI");
    }

    std::vector<std::wstring> faces(faceSet.begin(), faceSet.end());
    return faces;
}

int ClampInt(int value, int minValue, int maxValue) {
    if (value < minValue) return minValue;
    if (value > maxValue) return maxValue;
    return value;
}

std::wstring LowercaseCopy(const std::wstring& value) {
    std::wstring lowered = value;
    if (!lowered.empty()) {
        CharLowerBuffW(&lowered[0], (DWORD)lowered.size());
    }
    return lowered;
}

bool ContainsCaseInsensitive(const std::wstring& text, const std::wstring& query) {
    if (query.empty()) return true;
    return LowercaseCopy(text).find(LowercaseCopy(query)) != std::wstring::npos;
}

int VisibleRowsForRect(const RECT& rc) {
    return IMax(1, (rc.bottom - rc.top) / FONT_LIST_ROW_HEIGHT);
}

void ClampFontDialogScroll(FontDialogState* state) {
    if (!state) return;

    int fontVisible = VisibleRowsForRect(state->fontListRect);
    int sizeVisible = VisibleRowsForRect(state->sizeListRect);

    state->fontScroll = ClampInt(
        state->fontScroll,
        0,
        IMax(0, (int)state->faces.size() - fontVisible)
    );

    state->sizeScroll = ClampInt(
        state->sizeScroll,
        0,
        IMax(0, (int)state->sizes.size() - sizeVisible)
    );
}

void RebuildFilteredFontFaces(FontDialogState* state, const std::wstring& preferredFace = L"") {
    if (!state) return;

    std::wstring keepFace = preferredFace;
    if (keepFace.empty() &&
        state->selectedFace >= 0 &&
        state->selectedFace < (int)state->faces.size()) {
        keepFace = state->faces[state->selectedFace];
    }

    state->faces.clear();
    for (const std::wstring& face : state->allFaces) {
        if (ContainsCaseInsensitive(face, state->fontSearch)) {
            state->faces.push_back(face);
        }
    }

    if (state->faces.empty()) {
        state->selectedFace = 0;
        state->fontScroll = 0;
        return;
    }

    auto it = std::find(state->faces.begin(), state->faces.end(), keepFace);
    state->selectedFace = (it != state->faces.end())
        ? (int)std::distance(state->faces.begin(), it)
        : 0;

    ClampFontDialogScroll(state);
}

void EnsureSelectedVisible(FontDialogState* state, int listIndex) {
    if (!state) return;

    if (listIndex == 0) {
        int visible = VisibleRowsForRect(state->fontListRect);
        if (state->selectedFace < state->fontScroll) {
            state->fontScroll = state->selectedFace;
        } else if (state->selectedFace >= state->fontScroll + visible) {
            state->fontScroll = state->selectedFace - visible + 1;
        }
    } else {
        int visible = VisibleRowsForRect(state->sizeListRect);
        if (state->selectedSize < state->sizeScroll) {
            state->sizeScroll = state->selectedSize;
        } else if (state->selectedSize >= state->sizeScroll + visible) {
            state->sizeScroll = state->selectedSize - visible + 1;
        }
    }

    ClampFontDialogScroll(state);
}

void UpdateSampleFont(FontDialogState* state) {
    if (!state) return;

    if (state->sampleFont) {
        DeleteObject(state->sampleFont);
        state->sampleFont = NULL;
    }

    LOGFONTW lf = state->selectedLogFont;

    if (state->selectedFace >= 0 && state->selectedFace < (int)state->faces.size()) {
        lstrcpynW(lf.lfFaceName, state->faces[state->selectedFace].c_str(), LF_FACESIZE);
    }

    if (state->selectedSize >= 0 && state->selectedSize < (int)state->sizes.size()) {
        lf.lfHeight = -MulDiv(state->sizes[state->selectedSize], GetSystemDpiY(), 72);
    }

    state->sampleFont = CreateFontIndirectW(&lf);
}

void LayoutFontDialog(HWND hwnd, FontDialogState* state) {
    if (!state) return;

    RECT rc;
    GetClientRect(hwnd, &rc);

    int margin = 16;
    int gap = 14;
    int buttonWidth = 92;
    int buttonHeight = 32;
    int bottomButtonsTop = rc.bottom - margin - buttonHeight;
    int sampleHeight = 58;
    int sampleTop = bottomButtonsTop - gap - sampleHeight;
    int searchTop = 42;
    int searchHeight = 24;
    int listTop = 100;
    int listBottom = sampleTop - gap;
    int sizeWidth = 118;

    state->searchRect = {
        margin,
        searchTop,
        rc.right - margin - gap - sizeWidth,
        searchTop + searchHeight
    };

    state->fontListRect = {
        margin,
        listTop,
        rc.right - margin - gap - sizeWidth,
        listBottom
    };

    state->sizeListRect = {
        rc.right - margin - sizeWidth,
        listTop,
        rc.right - margin,
        listBottom
    };

    state->sampleRect = {
        margin,
        sampleTop,
        rc.right - margin,
        sampleTop + sampleHeight
    };

    state->cancelRect = {
        rc.right - margin - buttonWidth,
        bottomButtonsTop,
        rc.right - margin,
        bottomButtonsTop + buttonHeight
    };

    state->okRect = {
        state->cancelRect.left - gap - buttonWidth,
        bottomButtonsTop,
        state->cancelRect.left - gap,
        bottomButtonsTop + buttonHeight
    };

    ClampFontDialogScroll(state);
}

void DrawCustomButton(HDC hdc, const RECT& rc, const wchar_t* text, bool hover, bool primary) {
    COLORREF bg = hover ? ButtonHover() : ButtonBg();
    COLORREF border = primary ? (darkModeEnabled ? RGB(105, 105, 105) : RGB(0, 120, 215)) : PanelBorder();

    FillRoundRectSolid(hdc, rc, bg, BUTTON_CORNER_RADIUS);
    RECT frameRect = rc;
    frameRect.right -= 1;
    frameRect.bottom -= 1;
    FrameRoundRectSolid(hdc, frameRect, border, BUTTON_CORNER_RADIUS);

    SelectUiFont(hdc);
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, UiText());

    RECT textRect = rc;
    DrawTextW(hdc, text, -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void DrawCustomScrollbar(HDC hdc, const RECT& listRect, int total, int visible, int scroll) {
    if (total <= visible) return;

    RECT track = {
        listRect.right - 9,
        listRect.top + 2,
        listRect.right - 3,
        listRect.bottom - 2
    };

    FillSolid(hdc, track, darkModeEnabled ? RGB(42, 42, 42) : RGB(235, 235, 235));

    int trackHeight = IMax(1, track.bottom - track.top);
    int thumbHeight = IMax(22, MulDiv(trackHeight, visible, total));
    int maxScroll = IMax(1, total - visible);
    int thumbTravel = IMax(1, trackHeight - thumbHeight);
    int thumbTop = track.top + MulDiv(thumbTravel, scroll, maxScroll);

    RECT thumb = {
        track.left,
        thumbTop,
        track.right,
        IMin(track.bottom, thumbTop + thumbHeight)
    };

    FillSolid(hdc, thumb, darkModeEnabled ? RGB(100, 100, 100) : RGB(160, 160, 160));
}

void DrawFontList(
    HDC hdc,
    const RECT& listRect,
    const std::vector<std::wstring>& values,
    int selectedIndex,
    int scroll,
    int activeList,
    int thisList
) {
    FillSolid(hdc, listRect, PanelBg());
    FrameRectSolid(hdc, listRect, activeList == thisList ? MenuActive() : PanelBorder());

    SelectUiFont(hdc);
    SetBkMode(hdc, TRANSPARENT);

    if (values.empty()) {
        SetTextColor(hdc, UiMutedText());
        RECT emptyText = listRect;
        emptyText.left += 10;
        emptyText.right -= 10;
        DrawTextW(
            hdc,
            L"No fonts found",
            -1,
            &emptyText,
            DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS
        );
        return;
    }

    RECT clip = listRect;
    clip.left += 1;
    clip.top += 1;
    clip.right -= 10;
    clip.bottom -= 1;

    HRGN oldClip = CreateRectRgn(0, 0, 0, 0);
    int hadClip = GetClipRgn(hdc, oldClip);
    HRGN clipRgn = CreateRectRgn(clip.left, clip.top, clip.right, clip.bottom);
    SelectClipRgn(hdc, clipRgn);

    int visible = VisibleRowsForRect(listRect);
    int y = listRect.top + 1;

    for (int row = 0; row < visible; ++row) {
        int index = scroll + row;
        if (index >= (int)values.size()) break;

        RECT rowRect = {
            listRect.left + 2,
            y,
            listRect.right - 10,
            y + FONT_LIST_ROW_HEIGHT
        };

        if (index == selectedIndex) {
            FillSolid(hdc, rowRect, MenuActive());
        }

        SetTextColor(hdc, UiText());
        RECT textRect = rowRect;
        textRect.left += 8;
        textRect.right -= 6;

        HFONT rowFont = NULL;
        HFONT oldRowFont = NULL;

        if (thisList == 0) {
            LOGFONTW rowLogFont = {};
            rowLogFont.lfHeight = -MulDiv(9, GetSystemDpiY(), 72);
            rowLogFont.lfWeight = FW_NORMAL;
            rowLogFont.lfCharSet = DEFAULT_CHARSET;
            rowLogFont.lfQuality = CLEARTYPE_QUALITY;
            rowLogFont.lfPitchAndFamily = DEFAULT_PITCH;
            lstrcpynW(rowLogFont.lfFaceName, values[index].c_str(), LF_FACESIZE);

            rowFont = CreateFontIndirectW(&rowLogFont);
            if (rowFont) {
                oldRowFont = (HFONT)SelectObject(hdc, rowFont);
            }
        } else {
            SelectUiFont(hdc);
        }

        DrawTextW(
            hdc,
            values[index].c_str(),
            -1,
            &textRect,
            DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS
        );

        if (rowFont) {
            if (oldRowFont) {
                SelectObject(hdc, oldRowFont);
            }
            DeleteObject(rowFont);
        }

        y += FONT_LIST_ROW_HEIGHT;
    }

    if (hadClip == 1) {
        SelectClipRgn(hdc, oldClip);
    } else {
        SelectClipRgn(hdc, NULL);
    }

    DeleteObject(clipRgn);
    DeleteObject(oldClip);

    DrawCustomScrollbar(hdc, listRect, (int)values.size(), visible, scroll);
}

void DrawSizeList(HDC hdc, FontDialogState* state) {
    std::vector<std::wstring> sizeStrings;
    sizeStrings.reserve(state->sizes.size());

    for (int size : state->sizes) {
        wchar_t buffer[16];
        wsprintfW(buffer, L"%d", size);
        sizeStrings.push_back(buffer);
    }

    DrawFontList(
        hdc,
        state->sizeListRect,
        sizeStrings,
        state->selectedSize,
        state->sizeScroll,
        state->activeList,
        1
    );
}

void PaintFontDialog(HWND hwnd, HDC hdc, FontDialogState* state) {
    RECT rc;
    GetClientRect(hwnd, &rc);

    FillSolid(hdc, rc, MenuBg());

    SelectUiFont(hdc);
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, UiText());

    RECT title = { 16, 14, rc.right - 16, 40 };
    DrawTextW(
        hdc,
        L"Choose the editor font",
        -1,
        &title,
        DT_LEFT | DT_VCENTER | DT_SINGLELINE
    );

    RECT searchLabel = {
        state->searchRect.left,
        state->searchRect.top - 20,
        state->searchRect.right,
        state->searchRect.top - 3
    };

    RECT fontLabel = {
        state->fontListRect.left,
        state->fontListRect.top - 24,
        state->fontListRect.right,
        state->fontListRect.top - 4
    };

    RECT sizeLabel = {
        state->sizeListRect.left,
        state->sizeListRect.top - 24,
        state->sizeListRect.right,
        state->sizeListRect.top - 4
    };

    SetTextColor(hdc, UiMutedText());
    DrawTextW(hdc, L"Search", -1, &searchLabel, DT_LEFT | DT_VCENTER | DT_SINGLELINE);

    FillSolid(hdc, state->searchRect, PanelBg());
    FrameRectSolid(hdc, state->searchRect, state->searchActive ? MenuActive() : PanelBorder());

    RECT searchText = state->searchRect;
    searchText.left += 8;
    searchText.right -= 8;

    if (state->fontSearch.empty()) {
        SetTextColor(hdc, UiMutedText());
        DrawTextW(
            hdc,
            L"Type to filter fonts...",
            -1,
            &searchText,
            DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS
        );
    } else {
        SetTextColor(hdc, UiText());
        DrawTextW(
            hdc,
            state->fontSearch.c_str(),
            -1,
            &searchText,
            DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS
        );
    }

    SetTextColor(hdc, UiMutedText());
    DrawTextW(hdc, L"Font family", -1, &fontLabel, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
    DrawTextW(hdc, L"Size", -1, &sizeLabel, DT_LEFT | DT_VCENTER | DT_SINGLELINE);

    DrawFontList(
        hdc,
        state->fontListRect,
        state->faces,
        state->selectedFace,
        state->fontScroll,
        state->activeList,
        0
    );

    DrawSizeList(hdc, state);

    FillSolid(hdc, state->sampleRect, PanelBg());
    FrameRectSolid(hdc, state->sampleRect, PanelBorder());

    SetTextColor(hdc, UiText());
    SetBkMode(hdc, TRANSPARENT);

    HFONT oldFont = NULL;
    if (state->sampleFont) {
        oldFont = (HFONT)SelectObject(hdc, state->sampleFont);
    }

    RECT sampleText = state->sampleRect;
    sampleText.left += 14;
    sampleText.right -= 14;

    DrawTextW(
        hdc,
        L"The quick brown fox jumps over 1234567890",
        -1,
        &sampleText,
        DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS
    );

    if (oldFont) {
        SelectObject(hdc, oldFont);
    }

    DrawCustomButton(hdc, state->okRect, L"OK", state->hoverButton == 1, true);
    DrawCustomButton(hdc, state->cancelRect, L"Cancel", state->hoverButton == 2, false);
}

int FontDialogListHitTest(FontDialogState* state, POINT pt) {
    if (PtInRect(&state->fontListRect, pt)) return 0;
    if (PtInRect(&state->sizeListRect, pt)) return 1;
    return -1;
}

void ApplyFontSearchText(HWND hwnd, FontDialogState* state, const std::wstring& newSearchText) {
    if (!state) return;

    std::wstring currentFace;
    if (state->selectedFace >= 0 && state->selectedFace < (int)state->faces.size()) {
        currentFace = state->faces[state->selectedFace];
    }

    state->fontSearch = newSearchText;
    RebuildFilteredFontFaces(state, currentFace);
    EnsureSelectedVisible(state, 0);
    UpdateSampleFont(state);
    InvalidateRect(hwnd, NULL, TRUE);
}

void SelectFontDialogRow(HWND hwnd, FontDialogState* state, int listIndex, int y) {
    if (!state) return;

    if (listIndex == 0) {
        int row = (y - state->fontListRect.top) / FONT_LIST_ROW_HEIGHT;
        int index = state->fontScroll + row;
        if (index >= 0 && index < (int)state->faces.size()) {
            state->selectedFace = index;
            state->activeList = 0;
            EnsureSelectedVisible(state, 0);
            UpdateSampleFont(state);
            InvalidateRect(hwnd, NULL, TRUE);
        }
    } else if (listIndex == 1) {
        int row = (y - state->sizeListRect.top) / FONT_LIST_ROW_HEIGHT;
        int index = state->sizeScroll + row;
        if (index >= 0 && index < (int)state->sizes.size()) {
            state->selectedSize = index;
            state->activeList = 1;
            EnsureSelectedVisible(state, 1);
            UpdateSampleFont(state);
            InvalidateRect(hwnd, NULL, TRUE);
        }
    }
}

void AcceptFontDialog(HWND hwnd, FontDialogState* state) {
    if (!state) return;

    LOGFONTW lf = state->selectedLogFont;

    if (state->selectedFace >= 0 && state->selectedFace < (int)state->faces.size()) {
        lstrcpynW(lf.lfFaceName, state->faces[state->selectedFace].c_str(), LF_FACESIZE);
    }

    if (state->selectedSize >= 0 && state->selectedSize < (int)state->sizes.size()) {
        lf.lfHeight = -MulDiv(state->sizes[state->selectedSize], GetSystemDpiY(), 72);
    }

    state->selectedLogFont = lf;
    state->accepted = true;
    DestroyWindow(hwnd);
}

void MoveFontDialogSelection(HWND hwnd, FontDialogState* state, int delta) {
    if (!state) return;

    if (state->activeList == 0) {
        int maxIndex = IMax(0, (int)state->faces.size() - 1);
        state->selectedFace = ClampInt(state->selectedFace + delta, 0, maxIndex);
        EnsureSelectedVisible(state, 0);
    } else {
        int maxIndex = IMax(0, (int)state->sizes.size() - 1);
        state->selectedSize = ClampInt(state->selectedSize + delta, 0, maxIndex);
        EnsureSelectedVisible(state, 1);
    }

    UpdateSampleFont(state);
    InvalidateRect(hwnd, NULL, TRUE);
}

LRESULT CALLBACK FontDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    FontDialogState* state = reinterpret_cast<FontDialogState*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));

    switch (msg) {
    case WM_NCCREATE: {
        CREATESTRUCTW* cs = reinterpret_cast<CREATESTRUCTW*>(lParam);
        state = reinterpret_cast<FontDialogState*>(cs->lpCreateParams);
        SetWindowLongPtrW(hwnd, GWLP_USERDATA, (LONG_PTR)state);
    } return TRUE;

    case WM_CREATE:
        ApplyWindowFrameTheme(hwnd);
        LayoutFontDialog(hwnd, state);
        EnsureSelectedVisible(state, 0);
        EnsureSelectedVisible(state, 1);
        UpdateSampleFont(state);
        return 0;

    case WM_SIZE:
        LayoutFontDialog(hwnd, state);
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;

    case WM_MOUSEMOVE: {
        POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
        int hover = 0;
        if (PtInRect(&state->okRect, pt)) hover = 1;
        else if (PtInRect(&state->cancelRect, pt)) hover = 2;

        if (hover != state->hoverButton) {
            state->hoverButton = hover;
            InvalidateRect(hwnd, NULL, TRUE);
        }
    } return 0;

    case WM_LBUTTONDOWN: {
        POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };

        if (PtInRect(&state->okRect, pt)) {
            AcceptFontDialog(hwnd, state);
            return 0;
        }

        if (PtInRect(&state->cancelRect, pt)) {
            DestroyWindow(hwnd);
            return 0;
        }

        if (PtInRect(&state->searchRect, pt)) {
            state->searchActive = true;
            InvalidateRect(hwnd, NULL, TRUE);
            return 0;
        }

        int listIndex = FontDialogListHitTest(state, pt);
        state->searchActive = false;
        if (listIndex >= 0) {
            SelectFontDialogRow(hwnd, state, listIndex, pt.y);
        }
    } return 0;

    case WM_CHAR:
        if (state->searchActive) {
            if (wParam == VK_BACK) {
                if (!state->fontSearch.empty()) {
                    std::wstring updated = state->fontSearch;
                    updated.pop_back();
                    ApplyFontSearchText(hwnd, state, updated);
                }
                return 0;
            }

            if (wParam >= 32) {
                std::wstring updated = state->fontSearch;
                updated.push_back((wchar_t)wParam);
                ApplyFontSearchText(hwnd, state, updated);
                return 0;
            }
        }
        break;

    case WM_MOUSEWHEEL: {
        POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
        ScreenToClient(hwnd, &pt);

        int listIndex = FontDialogListHitTest(state, pt);
        if (listIndex < 0) {
            listIndex = state->activeList;
        }

        int delta = GET_WHEEL_DELTA_WPARAM(wParam);
        int notches = delta / WHEEL_DELTA;
        if (notches == 0) {
            notches = delta > 0 ? 1 : -1;
        }

        if (listIndex == 0) {
            state->fontScroll -= notches * 3;
            state->activeList = 0;
        } else {
            state->sizeScroll -= notches * 3;
            state->activeList = 1;
        }

        ClampFontDialogScroll(state);
        InvalidateRect(hwnd, NULL, TRUE);
    } return 0;

    case WM_KEYDOWN:
        if ((GetKeyState(VK_CONTROL) & 0x8000) && wParam == 'F') {
            state->searchActive = true;
            InvalidateRect(hwnd, NULL, TRUE);
            return 0;
        }

        if (wParam == VK_ESCAPE) {
            if (state->searchActive && !state->fontSearch.empty()) {
                ApplyFontSearchText(hwnd, state, L"");
                return 0;
            }
            DestroyWindow(hwnd);
            return 0;
        }

        if (wParam == VK_DELETE && state->searchActive && !state->fontSearch.empty()) {
            ApplyFontSearchText(hwnd, state, L"");
            return 0;
        }

        if (wParam == VK_RETURN) {
            AcceptFontDialog(hwnd, state);
            return 0;
        }

        if (wParam == VK_TAB) {
            if (state->searchActive) {
                state->searchActive = false;
                state->activeList = 0;
            } else if (state->activeList == 0) {
                state->activeList = 1;
            } else {
                state->activeList = 0;
                state->searchActive = true;
            }
            InvalidateRect(hwnd, NULL, TRUE);
            return 0;
        }

        if (wParam == VK_DOWN) {
            MoveFontDialogSelection(hwnd, state, 1);
            return 0;
        }

        if (wParam == VK_UP) {
            MoveFontDialogSelection(hwnd, state, -1);
            return 0;
        }

        if (wParam == VK_NEXT) {
            MoveFontDialogSelection(hwnd, state, 8);
            return 0;
        }

        if (wParam == VK_PRIOR) {
            MoveFontDialogSelection(hwnd, state, -8);
            return 0;
        }

        if (wParam == VK_HOME) {
            if (state->activeList == 0) state->selectedFace = 0;
            else state->selectedSize = 0;
            EnsureSelectedVisible(state, state->activeList);
            UpdateSampleFont(state);
            InvalidateRect(hwnd, NULL, TRUE);
            return 0;
        }

        if (wParam == VK_END) {
            if (state->activeList == 0) {
                state->selectedFace = IMax(0, (int)state->faces.size() - 1);
            } else {
                state->selectedSize = IMax(0, (int)state->sizes.size() - 1);
            }
            EnsureSelectedVisible(state, state->activeList);
            UpdateSampleFont(state);
            InvalidateRect(hwnd, NULL, TRUE);
            return 0;
        }
        break;

    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        PaintFontDialog(hwnd, hdc, state);
        EndPaint(hwnd, &ps);
    } return 0;

    case WM_DESTROY:
        if (state && state->sampleFont) {
            DeleteObject(state->sampleFont);
            state->sampleFont = NULL;
        }
        return 0;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

bool ShowDarkFontDialog(HWND owner, LOGFONTW& selectedLogFont) {
    FontDialogState* state = new FontDialogState();

    state->owner = owner;
    state->accepted = false;
    state->allFaces = EnumerateFontFaces();
    state->faces = state->allFaces;
    state->sizes = { 8, 9, 10, 11, 12, 14, 16, 18, 20, 22, 24, 28, 32, 36, 48, 72 };
    state->selectedLogFont = selectedLogFont;
    state->selectedFace = 0;
    state->selectedSize = 0;
    state->fontScroll = 0;
    state->sizeScroll = 0;
    state->activeList = 0;
    state->searchActive = true;
    state->hoverButton = 0;
    state->fontSearch = L"";
    state->sampleFont = NULL;

    std::wstring currentFace = selectedLogFont.lfFaceName;
    if (currentFace.empty()) {
        currentFace = L"Cascadia Mono";
    }

    auto faceIt = std::find(state->allFaces.begin(), state->allFaces.end(), currentFace);
    if (faceIt == state->allFaces.end()) {
        state->allFaces.push_back(currentFace);
        std::sort(state->allFaces.begin(), state->allFaces.end());
    }

    state->faces = state->allFaces;
    faceIt = std::find(state->faces.begin(), state->faces.end(), currentFace);

    if (faceIt != state->faces.end()) {
        state->selectedFace = (int)std::distance(state->faces.begin(), faceIt);
    }

    int currentSize = PointSizeFromLogFont(selectedLogFont);
    auto sizeIt = std::find(state->sizes.begin(), state->sizes.end(), currentSize);
    if (sizeIt == state->sizes.end()) {
        state->sizes.push_back(currentSize);
        std::sort(state->sizes.begin(), state->sizes.end());
        sizeIt = std::find(state->sizes.begin(), state->sizes.end(), currentSize);
    }

    if (sizeIt != state->sizes.end()) {
        state->selectedSize = (int)std::distance(state->sizes.begin(), sizeIt);
    }

    RECT ownerRect = {};
    GetWindowRect(owner, &ownerRect);

    int width = FONT_DIALOG_WIDTH;
    int height = FONT_DIALOG_HEIGHT;
    int x = ownerRect.left + ((ownerRect.right - ownerRect.left) - width) / 2;
    int y = ownerRect.top + ((ownerRect.bottom - ownerRect.top) - height) / 2;

    RECT workArea = {};
    SystemParametersInfo(SPI_GETWORKAREA, 0, &workArea, 0);
    x = ClampInt(x, workArea.left, IMax(workArea.left, workArea.right - width));
    y = ClampInt(y, workArea.top, IMax(workArea.top, workArea.bottom - height));

    HWND dialog = CreateWindowExW(
        WS_EX_DLGMODALFRAME,
        FONT_DIALOG_CLASS_NAME,
        L"Font",
        WS_POPUP | WS_CAPTION | WS_SYSMENU,
        x,
        y,
        width,
        height,
        owner,
        NULL,
        g_hInstance,
        state
    );

    if (!dialog) {
        delete state;
        return false;
    }

    EnableWindow(owner, FALSE);
    ShowWindow(dialog, SW_SHOW);
    UpdateWindow(dialog);
    SetFocus(dialog);

    MSG msg;
    BOOL gotMessage;
    while (IsWindow(dialog) && (gotMessage = GetMessageW(&msg, NULL, 0, 0)) != 0) {
        if (gotMessage == -1) {
            break;
        }

        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    if (gotMessage == 0) {
        PostQuitMessage((int)msg.wParam);
    }

    EnableWindow(owner, TRUE);
    SetForegroundWindow(owner);

    bool accepted = state->accepted;
    if (accepted) {
        selectedLogFont = state->selectedLogFont;
    }

    delete state;
    return accepted;
}


struct LargeFilePaintLine {
    ULONGLONG startOffset;
    ULONGLONG textEndOffset;
    ULONGLONG nextOffset;
    std::wstring text;
    bool softWrapped;

    LargeFilePaintLine()
        : startOffset(0), textEndOffset(0), nextOffset(0), softWrapped(false) {}
};

struct LargeFileLineEdit {
    ULONGLONG startOffset;
    ULONGLONG textEndOffset;
    std::wstring text;

    LargeFileLineEdit()
        : startOffset(0), textEndOffset(0) {}

    LargeFileLineEdit(ULONGLONG start, ULONGLONG end, const std::wstring& replacement)
        : startOffset(start), textEndOffset(end), text(replacement) {}
};

struct LargeFileTextPosition {
    ULONGLONG lineOffset;
    int column;

    LargeFileTextPosition()
        : lineOffset(0), column(0) {}

    LargeFileTextPosition(ULONGLONG offset, int col)
        : lineOffset(offset), column(col) {}
};

struct LargeFileViewState {
    HANDLE fileHandle;
    std::wstring path;
    ULONGLONG fileSize;
    ULONGLONG contentStartOffset;
    ULONGLONG topOffset;
    FileEncoding encoding;
    int lineHeight;
    int averageCharWidth;
    int wheelRemainder;
    std::vector<char> blockCache;
    ULONGLONG blockCacheOffset;
    DWORD blockCacheBytes;
    bool blockCacheValid;
    std::vector<LargeFilePaintLine> lineCache;
    std::vector<LargeFilePaintLine> lastPaintedLines;
    std::vector<LargeFileLineEdit> edits;
    bool selecting;
    bool hasSelection;
    bool caretShown;
    LargeFileTextPosition selectionAnchor;
    LargeFileTextPosition selectionActive;
    LargeFileTextPosition caretPosition;

    LargeFileViewState()
        : fileHandle(INVALID_HANDLE_VALUE),
          fileSize(0),
          contentStartOffset(0),
          topOffset(0),
          encoding(FileEncoding::Utf8NoBom),
          lineHeight(18),
          averageCharWidth(8),
          wheelRemainder(0),
          blockCacheOffset(0),
          blockCacheBytes(0),
          blockCacheValid(false),
          selecting(false),
          hasSelection(false),
          caretShown(false) {}
};

LargeFileViewState g_largeFile;

bool LargeFileIsOpen() {
    return g_largeFile.fileHandle != INVALID_HANDLE_VALUE;
}

bool LargeFileIsUtf16Encoding(FileEncoding encoding) {
    return encoding == FileEncoding::Utf16LeBom ||
           encoding == FileEncoding::Utf16BeBom;
}

int LargeFileCodeUnitBytes() {
    return LargeFileIsUtf16Encoding(g_largeFile.encoding) ? 2 : 1;
}

ULONGLONG LargeFileClampOffset(ULONGLONG offset) {
    if (offset < g_largeFile.contentStartOffset) {
        offset = g_largeFile.contentStartOffset;
    }

    if (offset > g_largeFile.fileSize) {
        offset = g_largeFile.fileSize;
    }

    if (LargeFileIsUtf16Encoding(g_largeFile.encoding)) {
        ULONGLONG delta = offset - g_largeFile.contentStartOffset;
        if ((delta % 2) != 0) {
            --offset;
        }
    }

    return offset;
}

void LargeFileInvalidateCaches() {
    g_largeFile.blockCache.clear();
    g_largeFile.blockCacheOffset = 0;
    g_largeFile.blockCacheBytes = 0;
    g_largeFile.blockCacheValid = false;
    g_largeFile.lineCache.clear();
    g_largeFile.lastPaintedLines.clear();
}

int LargeFileFindCachedLineIndex(ULONGLONG offset) {
    for (int i = (int)g_largeFile.lineCache.size() - 1; i >= 0; --i) {
        if (g_largeFile.lineCache[i].startOffset == offset) {
            return i;
        }
    }
    return -1;
}

bool LargeFileGetCachedLine(ULONGLONG offset, LargeFilePaintLine& line) {
    int index = LargeFileFindCachedLineIndex(offset);
    if (index < 0) {
        return false;
    }

    line = g_largeFile.lineCache[index];
    return true;
}

void LargeFileRememberLine(const LargeFilePaintLine& line) {
    if (line.nextOffset <= line.startOffset) {
        return;
    }

    int existing = LargeFileFindCachedLineIndex(line.startOffset);
    if (existing >= 0) {
        g_largeFile.lineCache[existing] = line;
        return;
    }

    g_largeFile.lineCache.push_back(line);

    if ((int)g_largeFile.lineCache.size() > LARGE_FILE_LINE_CACHE_LIMIT) {
        g_largeFile.lineCache.erase(g_largeFile.lineCache.begin());
    }
}

int LargeFileFindEditIndex(ULONGLONG startOffset) {
    for (int i = 0; i < (int)g_largeFile.edits.size(); ++i) {
        if (g_largeFile.edits[i].startOffset == startOffset) {
            return i;
        }
    }
    return -1;
}

void LargeFileApplyEditOverlay(LargeFilePaintLine& line) {
    int editIndex = LargeFileFindEditIndex(line.startOffset);
    if (editIndex >= 0) {
        line.text = g_largeFile.edits[editIndex].text;
        line.textEndOffset = g_largeFile.edits[editIndex].textEndOffset;
    }
}

void LargeFileSetLineEdit(const LargeFilePaintLine& line, const std::wstring& replacementText) {
    LargeFileLineEdit edit(line.startOffset, line.textEndOffset, replacementText);
    int existing = LargeFileFindEditIndex(line.startOffset);

    if (existing >= 0) {
        g_largeFile.edits[existing] = edit;
    } else {
        auto it = g_largeFile.edits.begin();
        while (it != g_largeFile.edits.end() && it->startOffset < edit.startOffset) {
            ++it;
        }
        g_largeFile.edits.insert(it, edit);
    }

    LargeFileInvalidateCaches();
    SetEditorModifiedFlag(true);
    UpdateWindowTitle(g_hwndMain);
}

bool LargeFileHasPendingEdits() {
    return !g_largeFile.edits.empty();
}

bool LargeFileReadAt(ULONGLONG offset, void* buffer, DWORD bytesToRead, DWORD& bytesRead) {
    bytesRead = 0;

    if (!LargeFileIsOpen() || bytesToRead == 0) {
        return true;
    }

    offset = LargeFileClampOffset(offset);
    if (offset >= g_largeFile.fileSize) {
        return true;
    }

    ULONGLONG remaining = g_largeFile.fileSize - offset;
    if (remaining < bytesToRead) {
        bytesToRead = static_cast<DWORD>(remaining);
    }

    if (bytesToRead == 0) {
        return true;
    }

    if (bytesToRead <= LARGE_FILE_BLOCK_CACHE_BYTES) {
        ULONGLONG requestEnd = offset + bytesToRead;
        ULONGLONG cacheEnd = g_largeFile.blockCacheOffset + g_largeFile.blockCacheBytes;

        if (g_largeFile.blockCacheValid &&
            offset >= g_largeFile.blockCacheOffset &&
            requestEnd <= cacheEnd) {
            size_t cacheIndex = static_cast<size_t>(offset - g_largeFile.blockCacheOffset);
            std::memcpy(buffer, g_largeFile.blockCache.data() + cacheIndex, bytesToRead);
            bytesRead = bytesToRead;
            return true;
        }

        DWORD blockBytesToRead = static_cast<DWORD>(IMin(
            static_cast<long long>(g_largeFile.fileSize - offset),
            static_cast<long long>(LARGE_FILE_BLOCK_CACHE_BYTES)
        ));

        if (blockBytesToRead < bytesToRead) {
            blockBytesToRead = bytesToRead;
        }

        g_largeFile.blockCache.assign(blockBytesToRead, 0);

        LARGE_INTEGER position = {};
        position.QuadPart = static_cast<LONGLONG>(offset);

        if (!SetFilePointerEx(g_largeFile.fileHandle, position, NULL, FILE_BEGIN)) {
            g_largeFile.blockCache.clear();
            g_largeFile.blockCacheValid = false;
            return false;
        }

        DWORD actualBlockBytes = 0;
        if (!ReadFile(
                g_largeFile.fileHandle,
                g_largeFile.blockCache.data(),
                blockBytesToRead,
                &actualBlockBytes,
                NULL
            )) {
            g_largeFile.blockCache.clear();
            g_largeFile.blockCacheValid = false;
            return false;
        }

        g_largeFile.blockCache.resize(actualBlockBytes);
        g_largeFile.blockCacheOffset = offset;
        g_largeFile.blockCacheBytes = actualBlockBytes;
        g_largeFile.blockCacheValid = actualBlockBytes > 0;

        if (actualBlockBytes == 0) {
            return true;
        }

        DWORD copyBytes = IMin(static_cast<long long>(bytesToRead), static_cast<long long>(actualBlockBytes));
        std::memcpy(buffer, g_largeFile.blockCache.data(), copyBytes);
        bytesRead = copyBytes;
        return true;
    }

    LARGE_INTEGER position = {};
    position.QuadPart = static_cast<LONGLONG>(offset);

    if (!SetFilePointerEx(g_largeFile.fileHandle, position, NULL, FILE_BEGIN)) {
        return false;
    }

    return ReadFile(
        g_largeFile.fileHandle,
        buffer,
        bytesToRead,
        &bytesRead,
        NULL
    ) != FALSE;
}

bool LargeFileDetectEncoding(HANDLE fileHandle, ULONGLONG fileSize, FileEncoding& encoding, ULONGLONG& contentStartOffset) {
    encoding = FileEncoding::Utf8NoBom;
    contentStartOffset = 0;

    BYTE header[4] = {};
    DWORD bytesRead = 0;

    LARGE_INTEGER zero = {};
    SetFilePointerEx(fileHandle, zero, NULL, FILE_BEGIN);

    if (!ReadFile(fileHandle, header, sizeof(header), &bytesRead, NULL)) {
        return false;
    }

    if (bytesRead >= 3 && header[0] == 0xEF && header[1] == 0xBB && header[2] == 0xBF) {
        encoding = FileEncoding::Utf8Bom;
        contentStartOffset = 3;
    } else if (bytesRead >= 2 && header[0] == 0xFF && header[1] == 0xFE) {
        encoding = FileEncoding::Utf16LeBom;
        contentStartOffset = 2;
    } else if (bytesRead >= 2 && header[0] == 0xFE && header[1] == 0xFF) {
        encoding = FileEncoding::Utf16BeBom;
        contentStartOffset = 2;
    } else {
        encoding = FileEncoding::Utf8NoBom;
        contentStartOffset = 0;
    }

    if (contentStartOffset > fileSize) {
        contentStartOffset = fileSize;
    }

    return true;
}

bool LargeFileIsNewlineAt(const std::vector<char>& bytes, size_t index) {
    if (g_largeFile.encoding == FileEncoding::Utf16LeBom) {
        return index + 1 < bytes.size() &&
               static_cast<unsigned char>(bytes[index]) == 0x0A &&
               static_cast<unsigned char>(bytes[index + 1]) == 0x00;
    }

    if (g_largeFile.encoding == FileEncoding::Utf16BeBom) {
        return index + 1 < bytes.size() &&
               static_cast<unsigned char>(bytes[index]) == 0x00 &&
               static_cast<unsigned char>(bytes[index + 1]) == 0x0A;
    }

    return static_cast<unsigned char>(bytes[index]) == 0x0A;
}

size_t LargeFileTrimmedLineByteCount(const std::vector<char>& bytes) {
    size_t count = bytes.size();

    if (LargeFileIsUtf16Encoding(g_largeFile.encoding)) {
        while (count >= 2) {
            size_t index = count - 2;
            wchar_t ch;

            if (g_largeFile.encoding == FileEncoding::Utf16LeBom) {
                ch = static_cast<wchar_t>(
                    static_cast<unsigned char>(bytes[index]) |
                    (static_cast<unsigned char>(bytes[index + 1]) << 8)
                );
            } else {
                ch = static_cast<wchar_t>(
                    (static_cast<unsigned char>(bytes[index]) << 8) |
                    static_cast<unsigned char>(bytes[index + 1])
                );
            }

            if (ch != L'\r' && ch != L'\n') {
                break;
            }

            count -= 2;
        }
        return count;
    }

    while (count > 0 && (bytes[count - 1] == '\n' || bytes[count - 1] == '\r')) {
        --count;
    }

    return count;
}

void LargeFileTrimLineEnding(std::vector<char>& bytes) {
    if (bytes.empty()) return;

    if (LargeFileIsUtf16Encoding(g_largeFile.encoding)) {
        while (bytes.size() >= 2) {
            size_t index = bytes.size() - 2;
            wchar_t ch;

            if (g_largeFile.encoding == FileEncoding::Utf16LeBom) {
                ch = static_cast<wchar_t>(
                    static_cast<unsigned char>(bytes[index]) |
                    (static_cast<unsigned char>(bytes[index + 1]) << 8)
                );
            } else {
                ch = static_cast<wchar_t>(
                    (static_cast<unsigned char>(bytes[index]) << 8) |
                    static_cast<unsigned char>(bytes[index + 1])
                );
            }

            if (ch != L'\r' && ch != L'\n') {
                break;
            }

            bytes.resize(bytes.size() - 2);
        }
        return;
    }

    while (!bytes.empty() && (bytes.back() == '\n' || bytes.back() == '\r')) {
        bytes.pop_back();
    }
}

std::wstring LargeFileDecodeBytes(const std::vector<char>& bytes) {
    if (bytes.empty()) return L"";

    if (g_largeFile.encoding == FileEncoding::Utf16LeBom ||
        g_largeFile.encoding == FileEncoding::Utf16BeBom) {
        std::wstring out;
        out.reserve(bytes.size() / 2);

        for (size_t i = 0; i + 1 < bytes.size(); i += 2) {
            unsigned char b0 = static_cast<unsigned char>(bytes[i]);
            unsigned char b1 = static_cast<unsigned char>(bytes[i + 1]);
            unsigned short value = (g_largeFile.encoding == FileEncoding::Utf16LeBom)
                ? static_cast<unsigned short>(b0 | (b1 << 8))
                : static_cast<unsigned short>((b0 << 8) | b1);
            out.push_back(static_cast<wchar_t>(value));
        }

        return out;
    }

    UINT codePage = (g_largeFile.encoding == FileEncoding::Ansi) ? CP_ACP : CP_UTF8;
    DWORD flags = (codePage == CP_UTF8) ? MB_ERR_INVALID_CHARS : 0;

    int needed = MultiByteToWideChar(
        codePage,
        flags,
        bytes.data(),
        static_cast<int>(bytes.size()),
        NULL,
        0
    );

    if (needed <= 0 && codePage == CP_UTF8) {
        codePage = CP_ACP;
        flags = 0;
        needed = MultiByteToWideChar(
            codePage,
            flags,
            bytes.data(),
            static_cast<int>(bytes.size()),
            NULL,
            0
        );
    }

    if (needed <= 0) {
        return L"";
    }

    std::wstring out(needed, 0);
    MultiByteToWideChar(
        codePage,
        flags,
        bytes.data(),
        static_cast<int>(bytes.size()),
        &out[0],
        needed
    );

    return out;
}

bool LargeFileReadVisualLine(ULONGLONG offset, LargeFilePaintLine& line) {
    offset = LargeFileClampOffset(offset);

    if (LargeFileGetCachedLine(offset, line)) {
        return true;
    }

    line.startOffset = offset;
    line.textEndOffset = line.startOffset;
    line.nextOffset = line.startOffset;
    line.text.clear();
    line.softWrapped = false;

    if (!LargeFileIsOpen() || line.startOffset >= g_largeFile.fileSize) {
        return false;
    }

    const int unitBytes = LargeFileCodeUnitBytes();
    std::vector<char> bytes;
    bytes.reserve(4096);

    ULONGLONG cursor = line.startOffset;
    bool foundNewline = false;

    while (cursor < g_largeFile.fileSize && bytes.size() < LARGE_FILE_MAX_PAINT_LINE_BYTES) {
        ULONGLONG remaining = g_largeFile.fileSize - cursor;
        DWORD toRead = static_cast<DWORD>(IMin(
            IMin(static_cast<long long>(remaining), static_cast<long long>(LARGE_FILE_READ_CHUNK_BYTES)),
            static_cast<long long>(LARGE_FILE_MAX_PAINT_LINE_BYTES - bytes.size())
        ));

        if (unitBytes == 2 && toRead > 1 && (toRead % 2) != 0) {
            --toRead;
        }

        if (toRead == 0) break;

        std::vector<char> chunk(toRead);
        DWORD bytesRead = 0;
        if (!LargeFileReadAt(cursor, chunk.data(), toRead, bytesRead) || bytesRead == 0) {
            break;
        }

        chunk.resize(bytesRead);

        size_t newlineIndex = chunk.size();
        for (size_t i = 0; i + (unitBytes - 1) < chunk.size(); i += unitBytes) {
            if (LargeFileIsNewlineAt(chunk, i)) {
                newlineIndex = i;
                foundNewline = true;
                break;
            }
        }

        size_t bytesToAppend = foundNewline ? newlineIndex + unitBytes : chunk.size();
        bytes.insert(bytes.end(), chunk.begin(), chunk.begin() + bytesToAppend);
        cursor += bytesToAppend;

        if (foundNewline) {
            break;
        }
    }

    if (!foundNewline && cursor < g_largeFile.fileSize) {
        line.softWrapped = true;
    }

    line.nextOffset = LargeFileClampOffset(cursor);
    if (line.nextOffset <= line.startOffset && line.startOffset < g_largeFile.fileSize) {
        line.nextOffset = LargeFileClampOffset(line.startOffset + unitBytes);
    }

    size_t textByteCount = LargeFileTrimmedLineByteCount(bytes);
    line.textEndOffset = LargeFileClampOffset(line.startOffset + static_cast<ULONGLONG>(textByteCount));

    LargeFileTrimLineEnding(bytes);
    line.text = LargeFileDecodeBytes(bytes);
    LargeFileApplyEditOverlay(line);
    LargeFileRememberLine(line);

    return true;
}

ULONGLONG LargeFileMoveForwardVisualLines(ULONGLONG offset, int lineCount) {
    ULONGLONG cursor = LargeFileClampOffset(offset);

    for (int i = 0; i < lineCount && cursor < g_largeFile.fileSize; ++i) {
        LargeFilePaintLine line;
        if (!LargeFileReadVisualLine(cursor, line)) {
            break;
        }
        cursor = line.nextOffset;
    }

    return LargeFileClampOffset(cursor);
}

ULONGLONG LargeFileFindPreviousVisualLine(ULONGLONG offset) {
    offset = LargeFileClampOffset(offset);

    if (offset <= g_largeFile.contentStartOffset) {
        return g_largeFile.contentStartOffset;
    }

    const int unitBytes = LargeFileCodeUnitBytes();
    ULONGLONG minSearchStart = g_largeFile.contentStartOffset;

    if (offset > g_largeFile.contentStartOffset + LARGE_FILE_MAX_PAINT_LINE_BYTES) {
        minSearchStart = offset - LARGE_FILE_MAX_PAINT_LINE_BYTES;
    }

    ULONGLONG searchEnd = offset;
    if (unitBytes == 1) {
        if (searchEnd >= 2) searchEnd -= 2;
        else return g_largeFile.contentStartOffset;
    } else {
        if (searchEnd >= g_largeFile.contentStartOffset + 4) searchEnd -= 4;
        else return g_largeFile.contentStartOffset;
    }

    ULONGLONG cursor = searchEnd;
    const DWORD searchChunkBytes = 32u * 1024u;

    while (cursor > minSearchStart) {
        ULONGLONG chunkStart = (cursor > searchChunkBytes)
            ? cursor - searchChunkBytes
            : minSearchStart;

        chunkStart = LargeFileClampOffset(chunkStart);
        if (chunkStart < minSearchStart) {
            chunkStart = LargeFileClampOffset(minSearchStart);
        }

        DWORD toRead = static_cast<DWORD>(cursor - chunkStart + unitBytes);
        if (unitBytes == 2 && (toRead % 2) != 0) {
            ++toRead;
        }

        std::vector<char> chunk(toRead);
        DWORD bytesRead = 0;
        if (!LargeFileReadAt(chunkStart, chunk.data(), toRead, bytesRead) || bytesRead == 0) {
            break;
        }
        chunk.resize(bytesRead);

        for (int i = (int)chunk.size() - unitBytes; i >= 0; i -= unitBytes) {
            if (LargeFileIsNewlineAt(chunk, static_cast<size_t>(i))) {
                return LargeFileClampOffset(chunkStart + static_cast<ULONGLONG>(i) + unitBytes);
            }
        }

        if (chunkStart <= minSearchStart) {
            break;
        }

        cursor = chunkStart;
    }

    return LargeFileClampOffset(minSearchStart);
}

ULONGLONG LargeFileMoveBackwardVisualLines(ULONGLONG offset, int lineCount) {
    ULONGLONG cursor = LargeFileClampOffset(offset);

    for (int i = 0; i < lineCount && cursor > g_largeFile.contentStartOffset; ++i) {
        ULONGLONG previous = LargeFileFindPreviousVisualLine(cursor);
        if (previous == cursor) break;
        cursor = previous;
    }

    return LargeFileClampOffset(cursor);
}

int LargeFileVisibleLineCount(HWND hwnd) {
    RECT rc;
    GetClientRect(hwnd, &rc);
    int usableHeight = IMax(0, (rc.bottom - rc.top) - LARGE_FILE_STATUS_HEIGHT - 4);
    return IMax(1, usableHeight / IMax(1, g_largeFile.lineHeight));
}

void LargeFileUpdateMetrics(HWND hwnd) {
    HDC hdc = GetDC(hwnd);
    if (!hdc) return;

    HFONT oldFont = NULL;
    if (hFontPrimary) {
        oldFont = (HFONT)SelectObject(hdc, hFontPrimary);
    }

    TEXTMETRICW tm = {};
    if (GetTextMetricsW(hdc, &tm)) {
        g_largeFile.lineHeight = IMax(1, tm.tmHeight + tm.tmExternalLeading);
        g_largeFile.averageCharWidth = IMax(1, tm.tmAveCharWidth);
    }

    if (oldFont) {
        SelectObject(hdc, oldFont);
    }

    ReleaseDC(hwnd, hdc);
}

void LargeFileUpdateScrollbar(HWND hwnd) {
    if (!hwnd) return;

    SCROLLINFO si = {};
    si.cbSize = sizeof(si);
    si.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
    si.nMin = 0;
    si.nMax = LARGE_FILE_SCROLL_RANGE;
    si.nPage = IMax(1, LargeFileVisibleLineCount(hwnd));

    ULONGLONG scrollableBytes = (g_largeFile.fileSize > g_largeFile.contentStartOffset)
        ? (g_largeFile.fileSize - g_largeFile.contentStartOffset)
        : 1;

    ULONGLONG currentBytes = (g_largeFile.topOffset > g_largeFile.contentStartOffset)
        ? (g_largeFile.topOffset - g_largeFile.contentStartOffset)
        : 0;

    si.nPos = static_cast<int>((currentBytes * LARGE_FILE_SCROLL_RANGE) / scrollableBytes);

    SetScrollInfo(hwnd, SB_VERT, &si, TRUE);
}

void LargeFilePrimeCacheAround(HWND hwnd, ULONGLONG offset) {
    if (!LargeFileIsOpen()) {
        return;
    }

    int forwardLines = LargeFileVisibleLineCount(hwnd) + LARGE_FILE_PREFETCH_EXTRA_LINES;
    ULONGLONG cursor = LargeFileClampOffset(offset);

    for (int i = 0; i < forwardLines && cursor < g_largeFile.fileSize; ++i) {
        LargeFilePaintLine line;
        if (!LargeFileReadVisualLine(cursor, line)) {
            break;
        }

        if (line.nextOffset <= cursor) {
            break;
        }

        cursor = line.nextOffset;
    }

    ULONGLONG back = LargeFileClampOffset(offset);
    for (int i = 0; i < 12 && back > g_largeFile.contentStartOffset; ++i) {
        ULONGLONG previous = LargeFileFindPreviousVisualLine(back);
        if (previous == back) {
            break;
        }

        LargeFilePaintLine line;
        LargeFileReadVisualLine(previous, line);
        back = previous;
    }
}

void LargeFileSetTopOffset(HWND hwnd, ULONGLONG offset) {
    if (offset >= g_largeFile.fileSize && g_largeFile.fileSize > g_largeFile.contentStartOffset) {
        offset = LargeFileMoveBackwardVisualLines(
            g_largeFile.fileSize,
            IMax(1, LargeFileVisibleLineCount(hwnd) - 1)
        );
    }

    ULONGLONG clamped = LargeFileClampOffset(offset);

    if (clamped != g_largeFile.topOffset) {
        g_largeFile.topOffset = clamped;
        LargeFilePrimeCacheAround(hwnd, g_largeFile.topOffset);
        InvalidateRect(hwnd, NULL, FALSE);
    }

    LargeFileUpdateScrollbar(hwnd);
}

bool LargeFilePositionLess(const LargeFileTextPosition& a, const LargeFileTextPosition& b) {
    if (a.lineOffset < b.lineOffset) return true;
    if (a.lineOffset > b.lineOffset) return false;
    return a.column < b.column;
}

bool LargeFilePositionEqual(const LargeFileTextPosition& a, const LargeFileTextPosition& b) {
    return a.lineOffset == b.lineOffset && a.column == b.column;
}

bool LargeFileGetSelectionBounds(LargeFileTextPosition& start, LargeFileTextPosition& end) {
    if (!g_largeFile.hasSelection || LargeFilePositionEqual(g_largeFile.selectionAnchor, g_largeFile.selectionActive)) {
        return false;
    }

    if (LargeFilePositionLess(g_largeFile.selectionActive, g_largeFile.selectionAnchor)) {
        start = g_largeFile.selectionActive;
        end = g_largeFile.selectionAnchor;
    } else {
        start = g_largeFile.selectionAnchor;
        end = g_largeFile.selectionActive;
    }

    return true;
}

bool LargeFileLineIntersectsSelection(const LargeFilePaintLine& line, int& startColumn, int& endColumn) {
    LargeFileTextPosition selectionStart;
    LargeFileTextPosition selectionEnd;
    if (!LargeFileGetSelectionBounds(selectionStart, selectionEnd)) {
        return false;
    }

    if (line.startOffset < selectionStart.lineOffset || line.startOffset > selectionEnd.lineOffset) {
        return false;
    }

    startColumn = (line.startOffset == selectionStart.lineOffset) ? selectionStart.column : 0;
    endColumn = (line.startOffset == selectionEnd.lineOffset) ? selectionEnd.column : (int)line.text.size();

    startColumn = ClampInt(startColumn, 0, (int)line.text.size());
    endColumn = ClampInt(endColumn, 0, (int)line.text.size());

    return endColumn > startColumn;
}

LargeFileTextPosition LargeFileClientPointToPosition(HWND hwnd, POINT pt) {
    if (g_largeFile.lastPaintedLines.empty()) {
        LargeFilePrimeCacheAround(hwnd, g_largeFile.topOffset);
    }

    if (g_largeFile.lastPaintedLines.empty()) {
        return LargeFileTextPosition(g_largeFile.topOffset, 0);
    }

    int row = (pt.y - 2) / IMax(1, g_largeFile.lineHeight);
    row = ClampInt(row, 0, (int)g_largeFile.lastPaintedLines.size() - 1);

    const LargeFilePaintLine& line = g_largeFile.lastPaintedLines[row];
    int column = (pt.x - 6 + (g_largeFile.averageCharWidth / 2)) / IMax(1, g_largeFile.averageCharWidth);
    column = ClampInt(column, 0, (int)line.text.size());

    return LargeFileTextPosition(line.startOffset, column);
}

const wchar_t* LargeFileEncodingName() {
    switch (g_largeFile.encoding) {
    case FileEncoding::Utf8Bom: return L"UTF-8 BOM";
    case FileEncoding::Utf8NoBom: return L"UTF-8";
    case FileEncoding::Utf16LeBom: return L"UTF-16 LE";
    case FileEncoding::Utf16BeBom: return L"UTF-16 BE";
    case FileEncoding::Ansi: return L"ANSI";
    }
    return L"Unknown";
}

std::wstring LargeFileFormatByteCount(ULONGLONG bytes) {
    const wchar_t* suffixes[] = { L"B", L"KB", L"MB", L"GB", L"TB" };
    ULONGLONG scale = 1;
    int suffix = 0;

    while (suffix < 4 && bytes >= scale * 1024ull) {
        scale *= 1024ull;
        ++suffix;
    }

    wchar_t buffer[64] = {};
    if (suffix == 0) {
        swprintf_s(buffer, _countof(buffer), L"%I64u %s", bytes, suffixes[suffix]);
    } else {
        ULONGLONG tenths = (bytes * 10ull) / scale;
        swprintf_s(
            buffer,
            _countof(buffer),
            L"%I64u.%I64u %s",
            tenths / 10ull,
            tenths % 10ull,
            suffixes[suffix]
        );
    }

    return buffer;
}

std::wstring LargeFileStatusText() {
    ULONGLONG scrollableBytes = (g_largeFile.fileSize > g_largeFile.contentStartOffset)
        ? (g_largeFile.fileSize - g_largeFile.contentStartOffset)
        : 1;

    ULONGLONG currentBytes = (g_largeFile.topOffset > g_largeFile.contentStartOffset)
        ? (g_largeFile.topOffset - g_largeFile.contentStartOffset)
        : 0;

    ULONGLONG percentTenths = (currentBytes * 1000ull) / scrollableBytes;

    wchar_t percentText[64] = {};
    swprintf_s(
        percentText,
        _countof(percentText),
        L"%I64u.%I64u%%",
        percentTenths / 10ull,
        percentTenths % 10ull
    );

    std::wstring status = L"Large File View | ";
    status += LargeFileFormatByteCount(g_largeFile.fileSize);
    status += L" | ";
    status += LargeFileEncodingName();
    status += L" | Offset ";
    status += percentText;
    status += L" | Editable";

    if (LargeFileHasPendingEdits()) {
        status += L" | Unsaved edits";
    }

    if (g_largeFile.hasSelection) {
        status += L" | Selection: Ctrl+C copy, Ctrl+X cut";
    }

    return status;
}

void LargeFileDrawStatusBar(HWND hwnd, HDC hdc, const RECT& clientRect) {
    RECT statusRect = clientRect;
    statusRect.top = IMax(clientRect.top, clientRect.bottom - LARGE_FILE_STATUS_HEIGHT);

    FillSolid(hdc, statusRect, MenuBg());

    RECT line = statusRect;
    line.bottom = line.top + 1;
    FillSolid(hdc, line, MenuBorder());

    SelectUiFont(hdc);
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, UiMutedText());

    RECT textRect = statusRect;
    textRect.left += 8;
    textRect.right -= 8;

    std::wstring status = LargeFileStatusText();
    DrawTextW(
        hdc,
        status.c_str(),
        -1,
        &textRect,
        DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS
    );
}

void LargeFilePaintContent(HWND hwnd, HDC hdc) {
    RECT rc;
    GetClientRect(hwnd, &rc);

    FillSolid(hdc, rc, EditorBg());

    RECT textArea = rc;
    textArea.bottom = IMax(textArea.top, textArea.bottom - LARGE_FILE_STATUS_HEIGHT);

    HFONT oldFont = NULL;
    if (hFontPrimary) {
        oldFont = (HFONT)SelectObject(hdc, hFontPrimary);
    }

    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, EditorText());

    g_largeFile.lastPaintedLines.clear();

    if (!LargeFileIsOpen()) {
        RECT textRect = textArea;
        textRect.left += 12;
        DrawTextW(
            hdc,
            L"No large file loaded.",
            -1,
            &textRect,
            DT_LEFT | DT_TOP | DT_SINGLELINE | DT_END_ELLIPSIS
        );
    } else if (g_largeFile.fileSize <= g_largeFile.contentStartOffset) {
        RECT textRect = textArea;
        textRect.left += 12;
        DrawTextW(
            hdc,
            L"The file is empty.",
            -1,
            &textRect,
            DT_LEFT | DT_TOP | DT_SINGLELINE | DT_END_ELLIPSIS
        );
    } else {
        int y = 2;
        int visibleLines = LargeFileVisibleLineCount(hwnd) + 1;
        ULONGLONG cursor = LargeFileClampOffset(g_largeFile.topOffset);

        for (int row = 0; row < visibleLines && y < textArea.bottom && cursor < g_largeFile.fileSize; ++row) {
            LargeFilePaintLine line;
            if (!LargeFileReadVisualLine(cursor, line)) {
                break;
            }

            g_largeFile.lastPaintedLines.push_back(line);

            int selectionStart = 0;
            int selectionEnd = 0;
            if (LargeFileLineIntersectsSelection(line, selectionStart, selectionEnd)) {
                RECT selectionRect = {
                    6 + (selectionStart * g_largeFile.averageCharWidth),
                    y,
                    6 + (selectionEnd * g_largeFile.averageCharWidth),
                    y + g_largeFile.lineHeight
                };
                FillSolid(hdc, selectionRect, MenuActive());
            }

            SetTextColor(hdc, EditorText());
            TextOutW(
                hdc,
                6,
                y,
                line.text.c_str(),
                static_cast<int>(line.text.size())
            );

            if (line.softWrapped) {
                SetTextColor(hdc, UiMutedText());
                TextOutW(
                    hdc,
                    6 + ((int)line.text.size() * g_largeFile.averageCharWidth),
                    y,
                    L"  ↪",
                    3
                );
                SetTextColor(hdc, EditorText());
            }

            if (line.nextOffset <= cursor) {
                break;
            }

            cursor = line.nextOffset;
            y += g_largeFile.lineHeight;
        }
    }

    if (oldFont) {
        SelectObject(hdc, oldFont);
    }

    LargeFileDrawStatusBar(hwnd, hdc, rc);
}

void LargeFilePaint(HWND hwnd, HDC hdc) {
    RECT rc;
    GetClientRect(hwnd, &rc);

    int width = IMax(1, rc.right - rc.left);
    int height = IMax(1, rc.bottom - rc.top);

    HDC memoryDc = CreateCompatibleDC(hdc);
    HBITMAP bitmap = CreateCompatibleBitmap(hdc, width, height);

    if (!memoryDc || !bitmap) {
        if (bitmap) DeleteObject(bitmap);
        if (memoryDc) DeleteDC(memoryDc);
        LargeFilePaintContent(hwnd, hdc);
        return;
    }

    HBITMAP oldBitmap = (HBITMAP)SelectObject(memoryDc, bitmap);
    LargeFilePaintContent(hwnd, memoryDc);

    BitBlt(hdc, 0, 0, width, height, memoryDc, 0, 0, SRCCOPY);

    SelectObject(memoryDc, oldBitmap);
    DeleteObject(bitmap);
    DeleteDC(memoryDc);
}

bool LargeFileBuildSelectedText(std::wstring& out) {
    out.clear();

    LargeFileTextPosition selectionStart;
    LargeFileTextPosition selectionEnd;
    if (!LargeFileGetSelectionBounds(selectionStart, selectionEnd)) {
        return false;
    }

    ULONGLONG cursor = selectionStart.lineOffset;

    while (cursor < g_largeFile.fileSize) {
        LargeFilePaintLine line;
        if (!LargeFileReadVisualLine(cursor, line)) {
            break;
        }

        int startColumn = (line.startOffset == selectionStart.lineOffset) ? selectionStart.column : 0;
        int endColumn = (line.startOffset == selectionEnd.lineOffset) ? selectionEnd.column : (int)line.text.size();

        startColumn = ClampInt(startColumn, 0, (int)line.text.size());
        endColumn = ClampInt(endColumn, 0, (int)line.text.size());

        if (endColumn > startColumn) {
            out.append(line.text.c_str() + startColumn, static_cast<size_t>(endColumn - startColumn));
        }

        if (line.startOffset == selectionEnd.lineOffset) {
            break;
        }

        if (!line.softWrapped) {
            out += L"\r\n";
        }

        if (line.nextOffset <= cursor) {
            break;
        }

        cursor = line.nextOffset;
    }

    return !out.empty();
}

bool LargeFileCopySelection(HWND hwnd) {
    std::wstring selectedText;

    if (!LargeFileBuildSelectedText(selectedText)) {
        MessageBeep(MB_OK);
        return false;
    }

    if (selectedText.size() > (((SIZE_T)-1 / sizeof(wchar_t)) - 1)) {
        MessageBoxW(hwnd, L"The selected text is too large for this process to place on the clipboard.", L"Copy", MB_OK | MB_ICONERROR);
        return false;
    }

    SIZE_T bytes = (selectedText.size() + 1) * sizeof(wchar_t);
    HGLOBAL memory = GlobalAlloc(GMEM_MOVEABLE, bytes);
    if (!memory) {
        MessageBoxW(hwnd, L"Could not allocate clipboard memory.", L"Copy", MB_OK | MB_ICONERROR);
        return false;
    }

    void* locked = GlobalLock(memory);
    if (!locked) {
        GlobalFree(memory);
        MessageBoxW(hwnd, L"Could not lock clipboard memory.", L"Copy", MB_OK | MB_ICONERROR);
        return false;
    }

    std::memcpy(locked, selectedText.c_str(), bytes);
    GlobalUnlock(memory);

    if (!OpenClipboard(hwnd)) {
        GlobalFree(memory);
        MessageBoxW(hwnd, L"Could not open the clipboard.", L"Copy", MB_OK | MB_ICONERROR);
        return false;
    }

    EmptyClipboard();
    SetClipboardData(CF_UNICODETEXT, memory);
    CloseClipboard();

    return true;
}

bool LargeFileSelectionIsSingleLine(LargeFileTextPosition& start, LargeFileTextPosition& end) {
    if (!LargeFileGetSelectionBounds(start, end)) {
        return false;
    }

    return start.lineOffset == end.lineOffset;
}

void LargeFileClearSelection() {
    g_largeFile.hasSelection = false;
    g_largeFile.selecting = false;
}

bool LargeFileGetLineAtPosition(const LargeFileTextPosition& position, LargeFilePaintLine& line) {
    if (!LargeFileReadVisualLine(position.lineOffset, line)) {
        return false;
    }

    return line.startOffset == position.lineOffset;
}

void LargeFileMarkEditedAndRefresh(HWND hwnd) {
    SetEditorModifiedFlag(true);
    UpdateWindowTitle(g_hwndMain ? g_hwndMain : hwnd);
    LargeFileUpdateScrollbar(hwnd);
    LargeFilePrimeCacheAround(hwnd, g_largeFile.topOffset);
    InvalidateRect(hwnd, NULL, FALSE);
}

bool LargeFileDeleteSelectionEditable(HWND hwnd) {
    LargeFileTextPosition start;
    LargeFileTextPosition end;
    if (!LargeFileSelectionIsSingleLine(start, end)) {
        if (g_largeFile.hasSelection) {
            MessageBoxW(
                hwnd,
                L"Stage 3 supports editing one visual line at a time. Multi-line delete/cut will come with the full piece-table stage.",
                L"Large File Edit",
                MB_OK | MB_ICONINFORMATION
            );
        }
        return false;
    }

    LargeFilePaintLine line;
    if (!LargeFileGetLineAtPosition(start, line)) {
        return false;
    }

    int startColumn = ClampInt(start.column, 0, (int)line.text.size());
    int endColumn = ClampInt(end.column, 0, (int)line.text.size());
    if (endColumn < startColumn) {
        std::swap(startColumn, endColumn);
    }

    std::wstring replacement = line.text;
    if (endColumn > startColumn) {
        replacement.erase(static_cast<size_t>(startColumn), static_cast<size_t>(endColumn - startColumn));
    }

    LargeFileSetLineEdit(line, replacement);
    g_largeFile.caretPosition = LargeFileTextPosition(line.startOffset, startColumn);
    LargeFileClearSelection();
    LargeFileMarkEditedAndRefresh(hwnd);
    return true;
}

std::wstring LargeFileSanitizeInsertedText(HWND hwnd, const std::wstring& text) {
    std::wstring out;
    out.reserve(text.size());
    bool sawLineBreak = false;

    for (wchar_t ch : text) {
        if (ch == L'\r' || ch == L'\n') {
            sawLineBreak = true;
            continue;
        }
        out.push_back(ch);
    }

    if (sawLineBreak) {
        MessageBoxW(
            hwnd,
            L"Stage 3 keeps edits line-local, so line breaks in pasted/typed text were omitted. Full inserted/deleted lines are the next piece-table step.",
            L"Large File Edit",
            MB_OK | MB_ICONINFORMATION
        );
    }

    return out;
}

bool LargeFileInsertTextAtCaret(HWND hwnd, const std::wstring& rawText) {
    std::wstring text = LargeFileSanitizeInsertedText(hwnd, rawText);
    if (text.empty()) {
        return false;
    }

    if (g_largeFile.hasSelection) {
        LargeFileTextPosition start;
        LargeFileTextPosition end;
        if (!LargeFileSelectionIsSingleLine(start, end)) {
            MessageBoxW(
                hwnd,
                L"Stage 3 supports replacing selections on a single visual line. Multi-line replace comes with the full piece-table stage.",
                L"Large File Edit",
                MB_OK | MB_ICONINFORMATION
            );
            return false;
        }
        LargeFileDeleteSelectionEditable(hwnd);
    }

    LargeFilePaintLine line;
    if (!LargeFileGetLineAtPosition(g_largeFile.caretPosition, line)) {
        return false;
    }

    int column = ClampInt(g_largeFile.caretPosition.column, 0, (int)line.text.size());
    std::wstring replacement = line.text;
    replacement.insert(static_cast<size_t>(column), text);

    LargeFileSetLineEdit(line, replacement);
    g_largeFile.caretPosition = LargeFileTextPosition(line.startOffset, column + (int)text.size());
    LargeFileMarkEditedAndRefresh(hwnd);
    return true;
}

bool LargeFileBackspace(HWND hwnd) {
    if (g_largeFile.hasSelection) {
        return LargeFileDeleteSelectionEditable(hwnd);
    }

    LargeFilePaintLine line;
    if (!LargeFileGetLineAtPosition(g_largeFile.caretPosition, line)) {
        return false;
    }

    int column = ClampInt(g_largeFile.caretPosition.column, 0, (int)line.text.size());
    if (column <= 0) {
        MessageBeep(MB_OK);
        return false;
    }

    std::wstring replacement = line.text;
    replacement.erase(static_cast<size_t>(column - 1), 1);
    LargeFileSetLineEdit(line, replacement);
    g_largeFile.caretPosition = LargeFileTextPosition(line.startOffset, column - 1);
    LargeFileMarkEditedAndRefresh(hwnd);
    return true;
}

bool LargeFileDeleteForward(HWND hwnd) {
    if (g_largeFile.hasSelection) {
        return LargeFileDeleteSelectionEditable(hwnd);
    }

    LargeFilePaintLine line;
    if (!LargeFileGetLineAtPosition(g_largeFile.caretPosition, line)) {
        return false;
    }

    int column = ClampInt(g_largeFile.caretPosition.column, 0, (int)line.text.size());
    if (column >= (int)line.text.size()) {
        MessageBeep(MB_OK);
        return false;
    }

    std::wstring replacement = line.text;
    replacement.erase(static_cast<size_t>(column), 1);
    LargeFileSetLineEdit(line, replacement);
    g_largeFile.caretPosition = LargeFileTextPosition(line.startOffset, column);
    LargeFileMarkEditedAndRefresh(hwnd);
    return true;
}

bool LargeFilePasteClipboard(HWND hwnd) {
    if (!OpenClipboard(hwnd)) {
        MessageBoxW(hwnd, L"Could not open the clipboard.", L"Paste", MB_OK | MB_ICONERROR);
        return false;
    }

    HANDLE handle = GetClipboardData(CF_UNICODETEXT);
    if (!handle) {
        CloseClipboard();
        MessageBeep(MB_OK);
        return false;
    }

    LPCWSTR text = static_cast<LPCWSTR>(GlobalLock(handle));
    if (!text) {
        CloseClipboard();
        MessageBoxW(hwnd, L"Could not read text from the clipboard.", L"Paste", MB_OK | MB_ICONERROR);
        return false;
    }

    std::wstring clipboardText(text);
    GlobalUnlock(handle);
    CloseClipboard();

    return LargeFileInsertTextAtCaret(hwnd, clipboardText);
}

bool LargeFileCutSelection(HWND hwnd) {
    LargeFileTextPosition start;
    LargeFileTextPosition end;
    if (!LargeFileSelectionIsSingleLine(start, end)) {
        MessageBoxW(
            hwnd,
            L"Stage 3 can copy multi-line selections, but cut/delete is currently one visual line at a time.",
            L"Large File Edit",
            MB_OK | MB_ICONINFORMATION
        );
        return false;
    }

    if (!LargeFileCopySelection(hwnd)) {
        return false;
    }

    return LargeFileDeleteSelectionEditable(hwnd);
}

bool LargeFileMoveCaretHorizontal(HWND hwnd, int delta) {
    LargeFilePaintLine line;
    if (!LargeFileGetLineAtPosition(g_largeFile.caretPosition, line)) {
        return false;
    }

    int column = ClampInt(g_largeFile.caretPosition.column + delta, 0, (int)line.text.size());
    g_largeFile.caretPosition = LargeFileTextPosition(line.startOffset, column);
    LargeFileClearSelection();
    InvalidateRect(hwnd, NULL, FALSE);
    LargeFileUpdateCaret(hwnd);
    return true;
}

bool LargeFileMoveCaretToLineBoundary(HWND hwnd, bool lineEnd) {
    LargeFilePaintLine line;
    if (!LargeFileGetLineAtPosition(g_largeFile.caretPosition, line)) {
        return false;
    }

    g_largeFile.caretPosition = LargeFileTextPosition(line.startOffset, lineEnd ? (int)line.text.size() : 0);
    LargeFileClearSelection();
    InvalidateRect(hwnd, NULL, FALSE);
    LargeFileUpdateCaret(hwnd);
    return true;
}

void LargeFileSelectAll(HWND hwnd) {
    g_largeFile.selectionAnchor = LargeFileTextPosition(g_largeFile.contentStartOffset, 0);
    g_largeFile.selectionActive = LargeFileTextPosition(g_largeFile.fileSize, 0);
    g_largeFile.caretPosition = g_largeFile.selectionActive;
    g_largeFile.hasSelection = true;
    InvalidateRect(hwnd, NULL, FALSE);
}

void LargeFileUpdateCaret(HWND hwnd) {
    if (!g_largeFile.caretShown) {
        return;
    }

    for (int i = 0; i < (int)g_largeFile.lastPaintedLines.size(); ++i) {
        const LargeFilePaintLine& line = g_largeFile.lastPaintedLines[i];
        if (line.startOffset == g_largeFile.caretPosition.lineOffset) {
            int column = ClampInt(g_largeFile.caretPosition.column, 0, (int)line.text.size());
            SetCaretPos(6 + (column * g_largeFile.averageCharWidth), 2 + (i * g_largeFile.lineHeight));
            return;
        }
    }

    SetCaretPos(-100, -100);
}

bool LargeFileEncodeReplacementText(HWND hwnd, const std::wstring& text, std::string& out) {
    out.clear();

    switch (g_largeFile.encoding) {
    case FileEncoding::Utf8Bom:
    case FileEncoding::Utf8NoBom:
        return WstringToUtf8(text, out, hwnd);

    case FileEncoding::Utf16LeBom:
        WstringToUtf16Bytes(text, true, out);
        return true;

    case FileEncoding::Utf16BeBom:
        WstringToUtf16Bytes(text, false, out);
        return true;

    case FileEncoding::Ansi:
        return WstringToAnsi(text, out, hwnd);
    }

    return false;
}

bool LargeFileWriteBytes(HANDLE outFile, const void* data, DWORD bytesToWrite) {
    const char* cursor = static_cast<const char*>(data);
    DWORD remaining = bytesToWrite;

    while (remaining > 0) {
        DWORD written = 0;
        if (!WriteFile(outFile, cursor, remaining, &written, NULL) || written == 0) {
            return false;
        }
        cursor += written;
        remaining -= written;
    }

    return true;
}

bool LargeFileReadOriginalAt(ULONGLONG offset, void* buffer, DWORD bytesToRead, DWORD& bytesRead) {
    bytesRead = 0;

    if (!LargeFileIsOpen() || bytesToRead == 0) {
        return true;
    }

    if (offset >= g_largeFile.fileSize) {
        return true;
    }

    ULONGLONG remaining = g_largeFile.fileSize - offset;
    if (remaining < bytesToRead) {
        bytesToRead = static_cast<DWORD>(remaining);
    }

    LARGE_INTEGER position = {};
    position.QuadPart = static_cast<LONGLONG>(offset);

    if (!SetFilePointerEx(g_largeFile.fileHandle, position, NULL, FILE_BEGIN)) {
        return false;
    }

    return ReadFile(g_largeFile.fileHandle, buffer, bytesToRead, &bytesRead, NULL) != FALSE;
}

bool LargeFileWriteOriginalRange(HANDLE outFile, ULONGLONG startOffset, ULONGLONG endOffset) {
    if (endOffset <= startOffset) {
        return true;
    }

    ULONGLONG cursor = startOffset;
    std::vector<char> buffer(LARGE_FILE_SAVE_CHUNK_BYTES);

    while (cursor < endOffset) {
        ULONGLONG remaining = endOffset - cursor;
        DWORD toRead = static_cast<DWORD>(IMin(
            static_cast<long long>(remaining),
            static_cast<long long>(LARGE_FILE_SAVE_CHUNK_BYTES)
        ));

        DWORD bytesRead = 0;
        if (!LargeFileReadOriginalAt(cursor, buffer.data(), toRead, bytesRead)) {
            return false;
        }

        if (bytesRead == 0) {
            return false;
        }

        if (!LargeFileWriteBytes(outFile, buffer.data(), bytesRead)) {
            return false;
        }

        cursor += bytesRead;
    }

    return true;
}

bool LargeFileWriteMaterializedDocument(HWND hwnd, HANDLE outFile) {
    ULONGLONG cursor = 0;

    for (const LargeFileLineEdit& edit : g_largeFile.edits) {
        if (edit.startOffset < cursor) {
            continue;
        }

        if (!LargeFileWriteOriginalRange(outFile, cursor, edit.startOffset)) {
            return false;
        }

        std::string encoded;
        if (!LargeFileEncodeReplacementText(hwnd, edit.text, encoded)) {
            return false;
        }

        if (!encoded.empty() && !LargeFileWriteBytes(outFile, encoded.data(), static_cast<DWORD>(encoded.size()))) {
            return false;
        }

        cursor = edit.textEndOffset;
    }

    return LargeFileWriteOriginalRange(outFile, cursor, g_largeFile.fileSize);
}

bool SaveLargeFileDocumentToPath(HWND hwnd, const std::wstring& destinationPath) {
    if (!LargeFileIsOpen()) {
        return false;
    }

    std::wstring tempPath = destinationPath + L".tmp";
    DeleteFileW(tempPath.c_str());

    HANDLE outFile = CreateFileW(
        tempPath.c_str(),
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (outFile == INVALID_HANDLE_VALUE) {
        MessageBoxW(hwnd, L"Failed to create the temporary save file.", L"Save", MB_OK | MB_ICONERROR);
        return false;
    }

    bool wrote = LargeFileWriteMaterializedDocument(hwnd, outFile);
    DWORD flushError = ERROR_SUCCESS;
    if (!FlushFileBuffers(outFile)) {
        flushError = GetLastError();
        wrote = false;
    }
    CloseHandle(outFile);

    if (!wrote) {
        DeleteFileW(tempPath.c_str());
        std::wstring message = L"Failed to write the large file.";
        if (flushError != ERROR_SUCCESS) {
            message += L"\n\nWindows error: ";
            message += GetWin32ErrorMessage(flushError);
        }
        MessageBoxW(hwnd, message.c_str(), L"Save", MB_OK | MB_ICONERROR);
        return false;
    }

    if (g_largeFile.fileHandle != INVALID_HANDLE_VALUE) {
        CloseHandle(g_largeFile.fileHandle);
        g_largeFile.fileHandle = INVALID_HANDLE_VALUE;
    }

    if (!MoveFileExW(
            tempPath.c_str(),
            destinationPath.c_str(),
            MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH
        )) {
        DWORD moveError = GetLastError();
        DeleteFileW(tempPath.c_str());

        std::wstring message = L"Failed to replace the destination file.\n\nWindows error: ";
        message += GetWin32ErrorMessage(moveError);
        MessageBoxW(
            hwnd,
            message.c_str(),
            L"Save",
            MB_OK | MB_ICONERROR
        );

        OpenLargeFileDocument(hwnd, currentFilePath.empty() ? destinationPath : currentFilePath);
        return false;
    }

    OpenLargeFileDocument(hwnd, destinationPath);
    SetEditorModifiedFlag(false);
    UpdateWindowTitle(hwnd);
    return true;
}

void CloseLargeFileDocument() {
    if (g_largeFile.fileHandle != INVALID_HANDLE_VALUE) {
        CloseHandle(g_largeFile.fileHandle);
    }

    g_largeFile = LargeFileViewState();
}

void ShowRichEditSurface() {
    g_largeFileMode = false;

    if (hwndLargeView) {
        ShowWindow(hwndLargeView, SW_HIDE);
    }

    if (hwndEdit) {
        ShowWindow(hwndEdit, SW_SHOW);
        SetFocus(hwndEdit);
    }

    if (g_hwndMain) {
        UpdateWindowTitle(g_hwndMain);
    }
}

void ShowLargeFileSurface() {
    g_largeFileMode = true;

    if (hwndEdit) {
        ShowWindow(hwndEdit, SW_HIDE);
    }

    if (hwndLargeView) {
        ShowWindow(hwndLargeView, SW_SHOW);
        SetFocus(hwndLargeView);
        LargeFileUpdateMetrics(hwndLargeView);
        LargeFileUpdateScrollbar(hwndLargeView);
        LargeFilePrimeCacheAround(hwndLargeView, g_largeFile.topOffset);
        InvalidateRect(hwndLargeView, NULL, FALSE);
    }

    if (g_hwndMain) {
        UpdateWindowTitle(g_hwndMain);
    }
}

bool OpenLargeFileDocument(HWND owner, const std::wstring& path) {
    HANDLE fileHandle = CreateFileW(
        path.c_str(),
        GENERIC_READ,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS,
        NULL
    );

    if (fileHandle == INVALID_HANDLE_VALUE) {
        MessageBoxW(
            owner,
            L"Failed to open the file for large-file viewing.",
            L"Error",
            MB_OK | MB_ICONERROR
        );
        return false;
    }

    LARGE_INTEGER size = {};
    if (!GetFileSizeEx(fileHandle, &size) || size.QuadPart < 0) {
        CloseHandle(fileHandle);
        MessageBoxW(
            owner,
            L"Failed to determine the file size.",
            L"Error",
            MB_OK | MB_ICONERROR
        );
        return false;
    }

    FileEncoding detectedEncoding = FileEncoding::Utf8NoBom;
    ULONGLONG contentStart = 0;
    if (!LargeFileDetectEncoding(fileHandle, static_cast<ULONGLONG>(size.QuadPart), detectedEncoding, contentStart)) {
        CloseHandle(fileHandle);
        MessageBoxW(
            owner,
            L"Failed to inspect the file encoding.",
            L"Error",
            MB_OK | MB_ICONERROR
        );
        return false;
    }

    CloseLargeFileDocument();

    g_largeFile.fileHandle = fileHandle;
    g_largeFile.path = path;
    g_largeFile.fileSize = static_cast<ULONGLONG>(size.QuadPart);
    g_largeFile.contentStartOffset = contentStart;
    g_largeFile.topOffset = contentStart;
    g_largeFile.encoding = detectedEncoding;
    g_largeFile.selectionAnchor = LargeFileTextPosition(contentStart, 0);
    g_largeFile.selectionActive = LargeFileTextPosition(contentStart, 0);
    g_largeFile.caretPosition = LargeFileTextPosition(contentStart, 0);

    currentFilePath = path;
    currentFileName = PathFindFileNameW(path.c_str());
    currentFileEncoding = detectedEncoding;
    currentEolStyle = EolStyle::CRLF;

    SetEditorModifiedFlag(false);
    ShowLargeFileSurface();
    UpdateWindowTitle(owner);

    return true;
}

LRESULT CALLBACK LargeFileViewProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE:
        LargeFileUpdateMetrics(hwnd);
        LargeFileUpdateScrollbar(hwnd);
        return 0;

    case WM_SETFOCUS:
        CreateCaret(hwnd, NULL, 2, IMax(1, g_largeFile.lineHeight));
        g_largeFile.caretShown = true;
        ShowCaret(hwnd);
        LargeFileUpdateCaret(hwnd);
        return 0;

    case WM_KILLFOCUS:
        g_largeFile.caretShown = false;
        HideCaret(hwnd);
        DestroyCaret();
        return 0;

    case WM_SETFONT:
        LargeFileUpdateMetrics(hwnd);
        LargeFileUpdateScrollbar(hwnd);
        LargeFileInvalidateCaches();
        InvalidateRect(hwnd, NULL, FALSE);
        return 0;

    case WM_SIZE:
        LargeFileUpdateMetrics(hwnd);
        LargeFileUpdateScrollbar(hwnd);
        LargeFilePrimeCacheAround(hwnd, g_largeFile.topOffset);
        InvalidateRect(hwnd, NULL, FALSE);
        return 0;

    case WM_ERASEBKGND:
        return 1;

    case WM_LBUTTONDOWN: {
        SetFocus(hwnd);
        POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
        g_largeFile.selectionAnchor = LargeFileClientPointToPosition(hwnd, pt);
        g_largeFile.selectionActive = g_largeFile.selectionAnchor;
        g_largeFile.caretPosition = g_largeFile.selectionAnchor;
        g_largeFile.hasSelection = true;
        g_largeFile.selecting = true;
        SetCapture(hwnd);
        InvalidateRect(hwnd, NULL, FALSE);
        LargeFileUpdateCaret(hwnd);
    } return 0;

    case WM_MOUSEMOVE:
        if (g_largeFile.selecting) {
            POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
            g_largeFile.selectionActive = LargeFileClientPointToPosition(hwnd, pt);
            g_largeFile.caretPosition = g_largeFile.selectionActive;
            InvalidateRect(hwnd, NULL, FALSE);
            LargeFileUpdateCaret(hwnd);
            return 0;
        }
        break;

    case WM_LBUTTONUP:
        if (g_largeFile.selecting) {
            POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
            g_largeFile.selectionActive = LargeFileClientPointToPosition(hwnd, pt);
            g_largeFile.caretPosition = g_largeFile.selectionActive;
            g_largeFile.selecting = false;
            if (GetCapture() == hwnd) {
                ReleaseCapture();
            }
            if (LargeFilePositionEqual(g_largeFile.selectionAnchor, g_largeFile.selectionActive)) {
                g_largeFile.hasSelection = false;
            }
            InvalidateRect(hwnd, NULL, FALSE);
            LargeFileUpdateCaret(hwnd);
            return 0;
        }
        break;

    case WM_CAPTURECHANGED:
        g_largeFile.selecting = false;
        return 0;

    case WM_MOUSEWHEEL: {
        int delta = GET_WHEEL_DELTA_WPARAM(wParam);
        UINT scrollLines = 3;
        SystemParametersInfoW(SPI_GETWHEELSCROLLLINES, 0, &scrollLines, 0);
        if (scrollLines == WHEEL_PAGESCROLL) {
            scrollLines = LargeFileVisibleLineCount(hwnd);
        }
        if (scrollLines == 0) {
            return 0;
        }

        int notches = delta / WHEEL_DELTA;
        if (notches == 0) {
            notches = delta > 0 ? 1 : -1;
        }

        int lines = static_cast<int>(scrollLines) * notches;
        ULONGLONG newOffset = g_largeFile.topOffset;

        if (lines > 0) {
            newOffset = LargeFileMoveBackwardVisualLines(g_largeFile.topOffset, lines);
        } else if (lines < 0) {
            newOffset = LargeFileMoveForwardVisualLines(g_largeFile.topOffset, -lines);
        }

        LargeFileSetTopOffset(hwnd, newOffset);
    } return 0;

    case WM_VSCROLL: {
        int request = LOWORD(wParam);
        ULONGLONG newOffset = g_largeFile.topOffset;

        switch (request) {
        case SB_LINEUP:
            newOffset = LargeFileMoveBackwardVisualLines(g_largeFile.topOffset, 1);
            break;
        case SB_LINEDOWN:
            newOffset = LargeFileMoveForwardVisualLines(g_largeFile.topOffset, 1);
            break;
        case SB_PAGEUP:
            newOffset = LargeFileMoveBackwardVisualLines(
                g_largeFile.topOffset,
                LargeFileVisibleLineCount(hwnd)
            );
            break;
        case SB_PAGEDOWN:
            newOffset = LargeFileMoveForwardVisualLines(
                g_largeFile.topOffset,
                LargeFileVisibleLineCount(hwnd)
            );
            break;
        case SB_THUMBTRACK:
        case SB_THUMBPOSITION: {
            SCROLLINFO si = {};
            si.cbSize = sizeof(si);
            si.fMask = SIF_TRACKPOS;
            GetScrollInfo(hwnd, SB_VERT, &si);

            ULONGLONG scrollableBytes = (g_largeFile.fileSize > g_largeFile.contentStartOffset)
                ? (g_largeFile.fileSize - g_largeFile.contentStartOffset)
                : 1;

            newOffset = g_largeFile.contentStartOffset +
                ((scrollableBytes * static_cast<ULONGLONG>(si.nTrackPos)) / LARGE_FILE_SCROLL_RANGE);
            break;
        }
        case SB_TOP:
            newOffset = g_largeFile.contentStartOffset;
            break;
        case SB_BOTTOM:
            newOffset = g_largeFile.fileSize;
            break;
        default:
            break;
        }

        LargeFileSetTopOffset(hwnd, newOffset);
    } return 0;

    case WM_KEYDOWN: {
        bool ctrlDown = (GetKeyState(VK_CONTROL) & 0x8000) != 0;

        if (ctrlDown && wParam == 'A') {
            LargeFileSelectAll(hwnd);
            return 0;
        }

        if (ctrlDown && wParam == 'C') {
            LargeFileCopySelection(hwnd);
            return 0;
        }

        if (ctrlDown && wParam == 'X') {
            LargeFileCutSelection(hwnd);
            return 0;
        }

        if (ctrlDown && wParam == 'V') {
            LargeFilePasteClipboard(hwnd);
            return 0;
        }

        if (wParam == VK_BACK) {
            LargeFileBackspace(hwnd);
            return 0;
        }

        if (wParam == VK_DELETE) {
            LargeFileDeleteForward(hwnd);
            return 0;
        }

        if (wParam == VK_ESCAPE) {
            g_largeFile.hasSelection = false;
            g_largeFile.selecting = false;
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        }

        if (wParam == VK_LEFT) {
            LargeFileMoveCaretHorizontal(hwnd, -1);
            return 0;
        }

        if (wParam == VK_RIGHT) {
            LargeFileMoveCaretHorizontal(hwnd, 1);
            return 0;
        }

        if (wParam == VK_HOME && !ctrlDown) {
            LargeFileMoveCaretToLineBoundary(hwnd, false);
            return 0;
        }

        if (wParam == VK_END && !ctrlDown) {
            LargeFileMoveCaretToLineBoundary(hwnd, true);
            return 0;
        }

        ULONGLONG newOffset = g_largeFile.topOffset;
        bool didScroll = true;

        switch (wParam) {
        case VK_UP:
            newOffset = LargeFileMoveBackwardVisualLines(g_largeFile.topOffset, 1);
            break;
        case VK_DOWN:
            newOffset = LargeFileMoveForwardVisualLines(g_largeFile.topOffset, 1);
            break;
        case VK_PRIOR:
            newOffset = LargeFileMoveBackwardVisualLines(
                g_largeFile.topOffset,
                LargeFileVisibleLineCount(hwnd)
            );
            break;
        case VK_NEXT:
            newOffset = LargeFileMoveForwardVisualLines(
                g_largeFile.topOffset,
                LargeFileVisibleLineCount(hwnd)
            );
            break;
        case VK_HOME:
            newOffset = g_largeFile.contentStartOffset;
            break;
        case VK_END:
            newOffset = g_largeFile.fileSize;
            break;
        default:
            didScroll = false;
            break;
        }

        if (didScroll) {
            LargeFileSetTopOffset(hwnd, newOffset);
            LargeFileUpdateCaret(hwnd);
            return 0;
        }

        return DefWindowProcW(hwnd, msg, wParam, lParam);
    } return 0;

    case WM_CHAR:
        if (wParam == VK_RETURN) {
            MessageBoxW(
                hwnd,
                L"Stage 3 edits stay on the current visual line. Inserting new lines comes with the full piece-table stage.",
                L"Large File Edit",
                MB_OK | MB_ICONINFORMATION
            );
            return 0;
        }
        if (wParam == VK_TAB || wParam >= 32) {
            wchar_t ch = static_cast<wchar_t>(wParam);
            std::wstring text(1, ch);
            LargeFileInsertTextAtCaret(hwnd, text);
            return 0;
        }
        return 0;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        LargeFilePaint(hwnd, hdc);
        EndPaint(hwnd, &ps);
        LargeFileUpdateCaret(hwnd);
    } return 0;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void OpenFile(HWND hwnd) {
    OPENFILENAMEW ofn = {};
    wchar_t szFile[32768] = {};

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = _countof(szFile);
    ofn.lpstrFilter =
        L"Text Files (*.txt;*.md;*.csv;*.log;*.rtf;*.xml;*.json;*.py;"
        L"*.cpp;*.h;*.ini;*.bat;*.cmd;*.sh;*.css;*.js;*.html;*.php;"
        L"*.java;*.sql;*.rb;*.pl;*.yaml;*.toml;*.conf;*.cfg;*.reg;*.vbs)\0"
        L"*.txt;*.md;*.csv;*.log;*.rtf;*.xml;*.json;*.py;*.cpp;*.h;"
        L"*.ini;*.bat;*.cmd;*.sh;*.css;*.js;*.html;*.php;*.java;*.sql;"
        L"*.rb;*.pl;*.yaml;*.toml;*.conf;*.cfg;*.reg;*.vbs\0"
        L"All Files (*.*)\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (!GetOpenFileNameW(&ofn)) return;

    WIN32_FILE_ATTRIBUTE_DATA fileAttributes = {};
    if (GetFileAttributesExW(ofn.lpstrFile, GetFileExInfoStandard, &fileAttributes)) {
        ULONGLONG fileSize =
            (static_cast<ULONGLONG>(fileAttributes.nFileSizeHigh) << 32) |
            static_cast<ULONGLONG>(fileAttributes.nFileSizeLow);

        if (fileSize >= LARGE_FILE_THRESHOLD_BYTES) {
            OpenLargeFileDocument(hwnd, ofn.lpstrFile);
            return;
        }
    }

    CloseLargeFileDocument();
    ShowRichEditSurface();

    std::ifstream file(ofn.lpstrFile, std::ios::binary);
    if (!file.is_open()) {
        MessageBoxW(
            hwnd,
            L"Failed to open the file.",
            L"Error",
            MB_OK | MB_ICONERROR
        );
        return;
    }

    std::string content(
        (std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>()
    );

    file.close();

    std::wstring wContent;
    FileEncoding detectedEncoding = currentFileEncoding;

    if (!DecodeFileContent(content, wContent, detectedEncoding, hwnd)) {
        return;
    }

#if defined(_DEBUG) && DEBUG_UTF8
    OutputDebugStringW(L"[DEBUG_UTF8] Decode succeeded.\n");
#endif

    SETTEXTEX sett = { ST_DEFAULT | ST_UNICODE, CP_UTF8 };

    suppressDirtyTracking = true;
    SendMessage(hwndEdit, EM_SETTEXTEX, (WPARAM)&sett, (LPARAM)wContent.c_str());
    suppressDirtyTracking = false;

    ApplyEditorTheme(hwnd);

    currentFilePath = ofn.lpstrFile;
    currentFileName = PathFindFileNameW(ofn.lpstrFile);
    currentFileEncoding = detectedEncoding;
    currentEolStyle = DetectEolStyle(wContent);

    SetEditorModifiedFlag(false);
    UpdateWindowTitle(hwnd);

    int tabWidth = 4 * 4;
    SendMessage(hwndEdit, EM_SETTABSTOPS, 1, (LPARAM)&tabWidth);
}

bool SaveFile(HWND hwnd);
bool SaveFileAs(HWND hwnd);

bool SaveFile(HWND hwnd) {
    if (g_largeFileMode) {
        if (currentFilePath.empty()) {
            return SaveFileAs(hwnd);
        }
        return SaveLargeFileDocumentToPath(hwnd, currentFilePath);
    }

    if (currentFilePath.empty()) {
        return SaveFileAs(hwnd);
    }

    int len = GetWindowTextLengthW(hwndEdit);

    std::wstring wbuf(len + 1, 0);
    int copied = GetWindowTextW(hwndEdit, &wbuf[0], len + 1);

    wbuf.resize((copied > 0) ? copied : 0);

    std::wstring normalizedText = NormalizeEolForSave(wbuf, currentEolStyle);

    std::string serializedBytes;

    if (!EncodeDocumentText(
            normalizedText,
            currentFileEncoding,
            serializedBytes,
            hwnd
        )) {
        return false;
    }

    std::wstring tempPath = currentFilePath + L".tmp";
    DeleteFileW(tempPath.c_str());

    std::ofstream file(
        tempPath.c_str(),
        std::ios::binary | std::ios::trunc
    );

    if (!file.is_open()) {
        MessageBoxW(
            hwnd,
            L"Failed to save the file.",
            L"Error",
            MB_OK | MB_ICONERROR
        );
        return false;
    }

    if (!serializedBytes.empty()) {
        file.write(
            serializedBytes.data(),
            static_cast<std::streamsize>(serializedBytes.size())
        );
    }

    file.flush();
    file.close();

    if (!file) {
        DeleteFileW(tempPath.c_str());

        MessageBoxW(
            hwnd,
            L"Failed to save the file.",
            L"Error",
            MB_OK | MB_ICONERROR
        );

        return false;
    }

    if (!ReplaceFileW(
            currentFilePath.c_str(),
            tempPath.c_str(),
            NULL,
            REPLACEFILE_IGNORE_MERGE_ERRORS,
            NULL,
            NULL
        )) {
        if (!MoveFileExW(
                tempPath.c_str(),
                currentFilePath.c_str(),
                MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH
            )) {
            DeleteFileW(tempPath.c_str());

            MessageBoxW(
                hwnd,
                L"Failed to save the file.",
                L"Error",
                MB_OK | MB_ICONERROR
            );

            return false;
        }
    }

    SetEditorModifiedFlag(false);
    UpdateWindowTitle(hwnd);

    return true;
}

bool SaveFileAs(HWND hwnd) {
    OPENFILENAMEW ofn = {};
    wchar_t szFile[32768] = L"*.txt";

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = _countof(szFile);
    ofn.lpstrFilter = L"Text Documents (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT;

    if (!GetSaveFileNameW(&ofn)) {
        return false;
    }

    std::wstring path(ofn.lpstrFile);

    if (path.find(L'.') == std::wstring::npos) {
        path += L".txt";
    }

    if (g_largeFileMode) {
        return SaveLargeFileDocumentToPath(hwnd, path);
    }

    currentFilePath = path;
    currentFileName = PathFindFileNameW(path.c_str());

    return SaveFile(hwnd);
}

enum class UnsavedChangesDecision {
    Proceed,
    Cancel
};

UnsavedChangesDecision CheckUnsavedChanges(HWND hwnd) {
    if (!g_largeFileMode) {
        SyncModifiedStateFromControl(hwnd);
    }

    if (!isModified) {
        return UnsavedChangesDecision::Proceed;
    }

    int result = MessageBoxW(
        hwnd,
        L"You have unsaved changes. Do you want to save them?",
        L"Unsaved Changes",
        MB_YESNOCANCEL | MB_ICONWARNING
    );

    if (result == IDCANCEL) {
        return UnsavedChangesDecision::Cancel;
    }

    if (result == IDYES && !SaveFile(hwnd)) {
        return UnsavedChangesDecision::Cancel;
    }

    return UnsavedChangesDecision::Proceed;
}

void ResizeChildWindows(HWND hwnd) {
    RECT rc;
    GetClientRect(hwnd, &rc);

    if (hwndMenuBar) {
        MoveWindow(hwndMenuBar, 0, 0, rc.right, MENU_BAR_HEIGHT, TRUE);
    }

    int editTop = MENU_BAR_HEIGHT;
    int editHeight = IMax(0, rc.bottom - editTop);

    if (hwndEdit) {
        SetWindowPos(
            hwndEdit,
            NULL,
            0,
            editTop,
            rc.right,
            editHeight,
            SWP_NOZORDER
        );
    }

    if (hwndLargeView) {
        SetWindowPos(
            hwndLargeView,
            NULL,
            0,
            editTop,
            rc.right,
            editHeight,
            SWP_NOZORDER
        );
    }
}

void OpenMenuFromKeyboard(int menuIndex) {
    if (menuIndex < 0 || menuIndex >= TOP_MENU_COUNT) return;
    ShowPopupMenuForTopIndex(g_hwndMain, menuIndex);
}

LRESULT CALLBACK WindowProc(
    HWND hwnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam
) {
    switch (uMsg) {
    case WM_CREATE: {
        g_hwndMain = hwnd;
        LoadLibraryW(L"Msftedit.dll");

        hwndMenuBar = CreateWindowExW(
            0,
            MENU_BAR_CLASS_NAME,
            L"",
            WS_CHILD | WS_VISIBLE,
            0,
            0,
            0,
            MENU_BAR_HEIGHT,
            hwnd,
            NULL,
            g_hInstance,
            NULL
        );

        hwndEdit = CreateWindowExW(
            0,
            L"RICHEDIT50W",
            L"",
            WS_CHILD | WS_VISIBLE |
            WS_VSCROLL | ES_MULTILINE |
            ES_AUTOVSCROLL | ES_WANTRETURN,
            0,
            MENU_BAR_HEIGHT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            hwnd,
            (HMENU)IDC_MAIN_EDIT,
            g_hInstance,
            NULL
        );

        if (!hwndEdit) {
            MessageBoxW(
                hwnd,
                L"Failed to create the editor control.",
                L"Error",
                MB_OK | MB_ICONERROR
            );
            return -1;
        }

        if (hFontPrimary) {
            SendMessage(hwndEdit, WM_SETFONT, (WPARAM)hFontPrimary, TRUE);
        }

        DWORD eventMask = (DWORD)SendMessage(hwndEdit, EM_GETEVENTMASK, 0, 0);
        SendMessage(
            hwndEdit,
            EM_SETEVENTMASK,
            0,
            (LPARAM)(eventMask | ENM_CHANGE)
        );
        SendMessage(hwndEdit, EM_SETMODIFY, FALSE, 0);

        hwndLargeView = CreateWindowExW(
            0,
            LARGE_VIEW_CLASS_NAME,
            L"",
            WS_CHILD | WS_VSCROLL,
            0,
            MENU_BAR_HEIGHT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            hwnd,
            (HMENU)IDC_LARGE_VIEW,
            g_hInstance,
            NULL
        );

        if (!hwndLargeView) {
            MessageBoxW(
                hwnd,
                L"Failed to create the large-file view control.",
                L"Error",
                MB_OK | MB_ICONERROR
            );
            return -1;
        }

        if (hFontPrimary) {
            SendMessage(hwndLargeView, WM_SETFONT, (WPARAM)hFontPrimary, TRUE);
        }

        ShowWindow(hwndLargeView, SW_HIDE);

        ResizeChildWindows(hwnd);
        ApplyEditorTheme(hwnd);
    } return 0;

    case WM_SIZE:
        ResizeChildWindows(hwnd);
        return 0;

    case WM_ERASEBKGND: {
        HDC hdc = (HDC)wParam;
        RECT rc;
        GetClientRect(hwnd, &rc);
        FillSolid(hdc, rc, EditorBg());
        return 1;
    }

    case WM_SYSKEYDOWN:
        if (wParam == 'F') {
            OpenMenuFromKeyboard(0);
            return 0;
        }
        if (wParam == 'E') {
            OpenMenuFromKeyboard(1);
            return 0;
        }
        if (wParam == 'O') {
            OpenMenuFromKeyboard(2);
            return 0;
        }
        break;

    case WM_COMMAND: {
        if (LOWORD(wParam) == IDC_MAIN_EDIT && HIWORD(wParam) == EN_CHANGE) {
            if (!suppressDirtyTracking) {
                SyncModifiedStateFromControl(hwnd);
            }
            return 0;
        }

        switch (LOWORD(wParam)) {
        case IDM_FILE_NEW:
            if (CheckUnsavedChanges(hwnd) == UnsavedChangesDecision::Cancel) {
                break;
            }

            CloseLargeFileDocument();
            ShowRichEditSurface();

            suppressDirtyTracking = true;
            SetWindowTextW(hwndEdit, L"");
            suppressDirtyTracking = false;

            ApplyEditorTheme(hwnd);

            currentFileName = L"Untitled";
            currentFilePath.clear();
            currentFileEncoding = FileEncoding::Utf8Bom;
            currentEolStyle = EolStyle::CRLF;

            SetEditorModifiedFlag(false);
            UpdateWindowTitle(hwnd);
            break;

        case IDM_FILE_OPEN:
            if (CheckUnsavedChanges(hwnd) == UnsavedChangesDecision::Cancel) {
                break;
            }

            OpenFile(hwnd);
            break;

        case IDM_FILE_SAVE:
            SaveFile(hwnd);
            break;

        case IDM_FILE_SAVE_AS:
            SaveFileAs(hwnd);
            break;

        case IDM_FILE_EXIT:
            if (CheckUnsavedChanges(hwnd) == UnsavedChangesDecision::Cancel) {
                break;
            }

            PostQuitMessage(0);
            break;

        case IDM_EDIT_UNDO:
            if (g_largeFileMode) MessageBeep(MB_OK);
            else SendMessage(hwndEdit, EM_UNDO, 0, 0);
            break;

        case IDM_EDIT_REDO:
            if (g_largeFileMode) MessageBeep(MB_OK);
            else SendMessage(hwndEdit, EM_REDO, 0, 0);
            break;

        case IDM_EDIT_CUT:
            if (g_largeFileMode) LargeFileCutSelection(hwndLargeView);
            else SendMessage(hwndEdit, WM_CUT, 0, 0);
            break;

        case IDM_EDIT_COPY:
            if (g_largeFileMode) LargeFileCopySelection(hwndLargeView);
            else SendMessage(hwndEdit, WM_COPY, 0, 0);
            break;

        case IDM_EDIT_PASTE:
            if (g_largeFileMode) LargeFilePasteClipboard(hwndLargeView);
            else SendMessage(hwndEdit, WM_PASTE, 0, 0);
            break;

        case IDM_FORMAT_FONT:
            ChooseEditorFont(hwnd);
            break;

        case IDM_FORMAT_DARK_MODE:
            darkModeEnabled = !darkModeEnabled;
            ApplyEditorTheme(hwnd);
            InvalidateRect(hwnd, NULL, TRUE);
            break;
        }
    } return 0;

    case WM_NOTIFY: {
        const NMHDR* hdr = reinterpret_cast<const NMHDR*>(lParam);

        if (hdr && hdr->hwndFrom == hwndEdit && hdr->code == EN_CHANGE) {
            if (!suppressDirtyTracking) {
                SyncModifiedStateFromControl(hwnd);
            }
            return 0;
        }
    } break;

    case WM_CLOSE:
        if (CheckUnsavedChanges(hwnd) == UnsavedChangesDecision::Cancel) {
            return 0;
        }

        DestroyWindow(hwnd);
        return 0;

    case WM_DESTROY:
        ClosePopupMenu();
        CloseLargeFileDocument();

        if (hFontPrimary) {
            DeleteObject(hFontPrimary);
            hFontPrimary = NULL;
        }

        if (hUiFont) {
            DeleteObject(hUiFont);
            hUiFont = NULL;
        }

        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

bool RegisterAppClasses(HINSTANCE hInstance) {
    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP_ICON));
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = NULL;

    if (!RegisterClassW(&wc)) {
        return false;
    }

    WNDCLASSW menuBarClass = {};
    menuBarClass.lpfnWndProc = MenuBarProc;
    menuBarClass.hInstance = hInstance;
    menuBarClass.lpszClassName = MENU_BAR_CLASS_NAME;
    menuBarClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    menuBarClass.hbrBackground = NULL;

    if (!RegisterClassW(&menuBarClass)) {
        return false;
    }

    WNDCLASSW popupClass = {};
    popupClass.lpfnWndProc = PopupMenuProc;
    popupClass.hInstance = hInstance;
    popupClass.lpszClassName = POPUP_MENU_CLASS_NAME;
    popupClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    popupClass.hbrBackground = NULL;

    if (!RegisterClassW(&popupClass)) {
        return false;
    }

    WNDCLASSW largeViewClass = {};
    largeViewClass.lpfnWndProc = LargeFileViewProc;
    largeViewClass.hInstance = hInstance;
    largeViewClass.lpszClassName = LARGE_VIEW_CLASS_NAME;
    largeViewClass.hCursor = LoadCursor(NULL, IDC_IBEAM);
    largeViewClass.hbrBackground = NULL;

    if (!RegisterClassW(&largeViewClass)) {
        return false;
    }

    WNDCLASSW fontDialogClass = {};
    fontDialogClass.lpfnWndProc = FontDialogProc;
    fontDialogClass.hInstance = hInstance;
    fontDialogClass.lpszClassName = FONT_DIALOG_CLASS_NAME;
    fontDialogClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    fontDialogClass.hbrBackground = NULL;
    fontDialogClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP_ICON));

    if (!RegisterClassW(&fontDialogClass)) {
        return false;
    }

    return true;
}

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE,
    LPSTR,
    int nCmdShow
) {
    g_hInstance = hInstance;

    InitializeDefaultEditorLogFont(editorLogFont);
    hFontPrimary = CreateFontIndirectW(&editorLogFont);
    hUiFont = CreateUiFont();

    if (!RegisterAppClasses(hInstance)) {
        if (hFontPrimary) {
            DeleteObject(hFontPrimary);
            hFontPrimary = NULL;
        }
        if (hUiFont) {
            DeleteObject(hUiFont);
            hUiFont = NULL;
        }
        return 0;
    }

    RECT screen;
    SystemParametersInfo(SPI_GETWORKAREA, 0, &screen, 0);

    int screenWidth = screen.right - screen.left;
    int screenHeight = screen.bottom - screen.top;

    int clientHeight = screenHeight / 2;
    int clientWidth = screenWidth / 2;

    RECT desired = { 0, 0, clientWidth, clientHeight };
    AdjustWindowRectEx(&desired, WS_OVERLAPPEDWINDOW, FALSE, 0);

    int windowWidth = desired.right - desired.left;
    int windowHeight = desired.bottom - desired.top;

    int posX = screen.left + (screenWidth - windowWidth) / 2;
    int posY = screen.top + (screenHeight - windowHeight) / 2;

    HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"Notepad",
        WS_OVERLAPPEDWINDOW,
        posX,
        posY,
        windowWidth,
        windowHeight,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hwnd) {
        if (hFontPrimary) {
            DeleteObject(hFontPrimary);
            hFontPrimary = NULL;
        }
        if (hUiFont) {
            DeleteObject(hUiFont);
            hUiFont = NULL;
        }
        return 0;
    }

    ACCEL accel[] = {
        { FVIRTKEY | FCONTROL, 'N', IDM_FILE_NEW },
        { FVIRTKEY | FCONTROL, 'O', IDM_FILE_OPEN },
        { FVIRTKEY | FCONTROL, 'S', IDM_FILE_SAVE },
        { FVIRTKEY | FCONTROL | FSHIFT, 'S', IDM_FILE_SAVE_AS },
        { FVIRTKEY | FCONTROL, 'Q', IDM_FILE_EXIT },
        { FVIRTKEY | FCONTROL, 'Z', IDM_EDIT_UNDO },
        { FVIRTKEY | FCONTROL, 'Y', IDM_EDIT_REDO },
        { FVIRTKEY | FCONTROL, 'X', IDM_EDIT_CUT },
        { FVIRTKEY | FCONTROL, 'C', IDM_EDIT_COPY },
        { FVIRTKEY | FCONTROL, 'V', IDM_EDIT_PASTE }
    };

    HACCEL hAccel = CreateAcceleratorTable(accel, _countof(accel));

    ShowWindow(hwnd, nCmdShow);
    UpdateWindowTitle(hwnd);
    ApplyEditorTheme(hwnd);

    MSG msg = {};

    while (GetMessageW(&msg, NULL, 0, 0)) {
        if (!TranslateAccelerator(hwnd, hAccel, &msg)) {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }

    DestroyAcceleratorTable(hAccel);

    return 0;
}
