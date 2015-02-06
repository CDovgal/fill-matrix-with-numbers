// WinApi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "WinApi_Graphic.h"
#include <Winspool.h>
#include <vector>
#include <CommDlg.h>

//#include <gdiplus.h>
//using namespace Gdiplus;
//#pragma comment (lib,"Gdiplus.lib")

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];
TCHAR szChild1[MAX_LOADSTRING];
TCHAR szChild2[MAX_LOADSTRING];
TCHAR szFileName[500] = L"\0";

enum DrawKind
{
  RECTANGLE,
  ELLIPSE
};

enum Color
{
  R,
  G,
  B
};

enum Shape_type
{
  Rect,
  Ell
};

struct Image_Object
{
  int x;
  int y;
  Color color;
  Shape_type type;
  //int rgb_color[3];
  Image_Object(int i_x, int i_y, const Color& i_color, const Shape_type& i_type) : x(i_x), y(i_y), color(i_color), type(i_type){}
};

static DrawKind DrawShape;
static OPENFILENAME ofn;
static std::vector<Image_Object> object_container;






// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
ATOM				MyChildRegisterClass1(HINSTANCE hInstance);
ATOM				MyChildRegisterClass2(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
BOOL OpenFileDialog(HWND hwnd, LPTSTR pFileName, LPTSTR pTitleName);
BOOL SaveFileDialog(HWND hwnd, LPTSTR pFileName, LPTSTR pTitleName);
BOOL LoadFile(/*const Image_Object& i_o*/HDC dc);
BOOL SaveFile(/*const Image_Object& i_o*/HDC dc);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	WndChildProcLeft(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	WndChildProcRight(HWND, UINT, WPARAM, LPARAM);
//VOID Save_File(HDC hdc);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
  _In_opt_ HINSTANCE hPrevInstance,
  _In_ LPTSTR    lpCmdLine,
  _In_ int       nCmdShow)
{
  UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(lpCmdLine);

  // TODO: Place code here.
  MSG msg;

  HACCEL hAccelTable;

  // Initialize global strings
  LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
  LoadString(hInstance, IDC_WINAPI, szWindowClass, MAX_LOADSTRING);
  MyRegisterClass(hInstance);
  MyChildRegisterClass1(hInstance);
  MyChildRegisterClass2(hInstance);

  // Perform application initialization:
  if (!InitInstance(hInstance, nCmdShow))
  {
    return FALSE;
  }

  hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI));

  // Main message loop:
  while (GetMessage(&msg, NULL, 0, 0))
  {
    if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }

  return (int)msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
  WNDCLASSEX wcex;

  wcex.cbSize = sizeof(WNDCLASSEX);

  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = WndProc;
  wcex.cbClsExtra = 0; // YOU SHALL NOT WATCH!!!!!!
  wcex.cbWndExtra = 0;
  wcex.hInstance = hInstance;
  wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI));
  wcex.hCursor = LoadCursor(NULL, IDC_CROSS);
  wcex.hbrBackground = CreateSolidBrush(RGB(54, 143, 234));//(HBRUSH)(COLOR_WINDOW + 1);
  wcex.lpszMenuName = MAKEINTRESOURCE(IDC_WINAPI);
  wcex.lpszClassName = szWindowClass;
  wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

  return RegisterClassEx(&wcex);
}

ATOM MyChildRegisterClass1(HINSTANCE hInstance)
{
  WNDCLASSEX wcex = { 0 };

  wcex.cbSize = sizeof(WNDCLASSEX);

  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = WndChildProcLeft;
  wcex.cbClsExtra = 0; // YOU SHALL NOT WATCH!!!!!!
  wcex.cbWndExtra = 0;
  wcex.hInstance = hInstance;
  wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
  wcex.hbrBackground = CreateSolidBrush(RGB(248, 248, 255));//(HBRUSH)(COLOR_WINDOW + 1);
  wcex.lpszClassName = L"Child1";

  return RegisterClassEx(&wcex);
}


ATOM MyChildRegisterClass2(HINSTANCE hInstance)
{
  WNDCLASSEX wcex = { 0 };

  wcex.cbSize = sizeof(WNDCLASSEX);

  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = WndChildProcRight;
  wcex.cbClsExtra = 0; // YOU SHALL NOT WATCH!!!!!!
  wcex.cbWndExtra = 0;
  wcex.hInstance = hInstance;
  wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
  wcex.hbrBackground = CreateSolidBrush(RGB(248, 248, 255));//(HBRUSH)(COLOR_WINDOW + 1);
  wcex.lpszClassName = L"Child2";

  return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
  HWND hWnd;
  hInst = hInstance; // Store instance handle in our global variable

  hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

  if (!hWnd)
  {
    return FALSE;
  }

  ShowWindow(hWnd, nCmdShow);
  UpdateWindow(hWnd);

  return TRUE;
}

BOOL SaveFile(/*const Image_Object& i_o*/HDC dc)
{
  HANDLE hFile;
  DWORD dwBytesWritten;
  hFile = CreateFile(L"Image.png", FILE_APPEND_DATA, 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
  if (hFile == INVALID_HANDLE_VALUE)
  {
    return false;
  }
  WriteFile(hFile, LPCVOID(dc), sizeof(dc), &dwBytesWritten, NULL);
  CloseHandle(hFile);
  return 0;
}

BOOL LoadFile(/*const Image_Object& i_o*/HDC dc)
{
  HANDLE hFile;
  DWORD dwBytesWritten;
  hFile = CreateFile(L"Image.png", GENERIC_READ, 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
  if (hFile == INVALID_HANDLE_VALUE)
  {
    return false;
  }
  ReadFile(hFile, LPVOID(dc), sizeof(dc), &dwBytesWritten, NULL);
  CloseHandle(hFile);
  return 0;
}

BOOL OpenFileDialog(HWND hwnd, LPTSTR pFileName, LPTSTR pTitleName)
{
  ofn.lStructSize = sizeof(OPENFILENAME);
  ofn.hInstance = GetModuleHandle(NULL);
  ofn.lpstrCustomFilter = NULL;
  ofn.nMaxCustFilter = 0;
  ofn.nFilterIndex = 0;
  ofn.hwndOwner = hwnd;
  ofn.lpstrFile = pFileName;
  ofn.lpstrFileTitle = NULL;
  ofn.lpstrTitle = pTitleName;
  ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
  ofn.lpstrFilter = TEXT("Bitmap Files (*.bmp)\0*.bmp\0\0");

  return GetOpenFileName(&ofn);
}

BOOL SaveFileDialog(HWND hwnd, LPTSTR pFileName, LPTSTR pTitleName)
{
  ofn.lStructSize = sizeof(OPENFILENAME);
  ofn.hInstance = GetModuleHandle(NULL);
  ofn.lpstrCustomFilter = NULL;
  ofn.nMaxCustFilter = 0;
  ofn.nFilterIndex = 0;
  ofn.hwndOwner = hwnd;
  ofn.lpstrFile = pFileName;
  ofn.lpstrFileTitle = NULL;
  ofn.lpstrTitle = pTitleName;
  ofn.Flags = OFN_EXPLORER | OFN_OVERWRITEPROMPT;
  ofn.lpstrFilter = TEXT("Bitmap Files (*.bmp)\0*.bmp\0\0");

  return GetSaveFileName(&ofn);
}
static HDC hdc;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  int wmId, wmEvent;
  static PAINTSTRUCT ps;
  //static HDC hdc;
  //DWORD id;
  static BOOL result;
  int nShift = 80;
  int x, y;

  switch (message)
  {
  case WM_CREATE:
    RECT rc;
    GetClientRect(hWnd, &rc);
    CreateWindow(L"Child1", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 10, rc.right / 2, rc.bottom - 10, hWnd, (HMENU)IDC_PANEL, hInst, NULL);
    CreateWindow(L"Child2", L"", WS_CHILDWINDOW | WS_VISIBLE | WS_BORDER, rc.right / 2 + 10, 10, rc.right / 2 - 10, rc.bottom - 10, hWnd, (HMENU)IDC_PANEL2, hInst, NULL);
    break;
  case WM_COMMAND:
    wmId = LOWORD(wParam);
    wmEvent = HIWORD(wParam);
    // Parse the menu selections:
    switch (wmId)
    {
    case IDM_ABOUT:
      DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
      break;
    case IDM_SAVEFILE:
      result = SaveFileDialog(hWnd, L"Image.png", L"Save an Image.");
      SaveFile(hdc);
      break;
    case IDM_OPENFILE:
      result = OpenFileDialog(hWnd, szFileName, L"Open an image.");
      LoadFile(hdc);
      break;
    case IDM_EXIT:
      DestroyWindow(hWnd);
      break;
    case IDM_RECTANGLE:
      DrawShape = RECTANGLE;
      break;
    case IDM_ELLIPSE:
      DrawShape = ELLIPSE;
      break;
    case IDM_REGION:
      DestroyWindow(hWnd);
      break;
      /*case IDC_GOBTN:
      MessageBox(NULL, L"GOBTN PRESSED", L"MSGBOX", MB_OK);
      break;*/
    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
    }
    break;
  case WM_LBUTTONDOWN:
    /*id = MessageBox(NULL, L"L_BUTTON PRESSED", L"PRESS OK", MB_ABORTRETRYIGNORE);
    if (id == IDRETRY)
    MessageBox(hWnd, L"RETRY", L"PRESS OK", MB_OK);*/
    hdc = GetDC(hWnd);
    x = LOWORD(lParam);
    y = HIWORD(lParam);
    //Rectangle(hdc, x - nShift, y - nShift, x + nShift, y + nShift);
    // ololo woorking...
    ReleaseDC(hWnd, hdc);
    break;

  case WM_PAINT:
    hdc = BeginPaint(hWnd, &ps);
    //Rectangle(hdc, 20, 20, 120, 120);
    // TODO: Add any drawing code here...
    EndPaint(hWnd, &ps);
    break;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  default:
    return DefWindowProc(hWnd, message, wParam, lParam);
  }
  return 0;
}


LRESULT CALLBACK WndChildProcLeft(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  int wmId, wmEvent;
  PAINTSTRUCT ps;
  //HDC hdc;
  int nShift = 80;
  RECT rc;
  GetClientRect(hWnd, &rc);

  switch (message)
  {
  case WM_MOUSEMOVE:
    if (wParam & MK_LBUTTON){
      hdc = GetDC(hWnd);
      int x, y;
      //int left, top, right, bottom;
      //int r = rand() % 255, g = rand() % 255, b = rand() % 255;
      x = LOWORD(lParam);
      y = HIWORD(lParam);
      
      HPEN hPen = CreatePen(PS_SOLID, 1, RGB(rand() % 255, rand() % 255, rand() % 255));
      HBRUSH hOldBrush, hBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
      HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
      hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
      switch (DrawShape)
      {
      case RECTANGLE:
        //left = x - rand() % 250, top = x - rand() % 250, right = x - rand() % 250, bottom = x - rand() % 250;
        Rectangle(hdc, x - rand() % 250, y - rand() % 250, x - rand() % 250, y - rand() % 250);
        break;
      case ELLIPSE:
        Ellipse(hdc, x - rand() % 250, y - rand() % 250, x - rand() % 250, y - rand() % 250);
        break;
      }
      SelectObject(hdc, hOldPen);
      SelectObject(hdc, hOldBrush);
      DeleteObject(hPen);
      ReleaseDC(hWnd, hdc);
    }
    break;
  case WM_PAINT:
    hdc = BeginPaint(hWnd, &ps);
    EndPaint(hWnd, &ps);
    break;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  default:
    return DefWindowProc(hWnd, message, wParam, lParam);
  }
  return 0;
}

LRESULT CALLBACK WndChildProcRight(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  int wmId, wmEvent;
  PAINTSTRUCT ps;
  HDC hdc;
  int nShift = 80;
  RECT rc;
  GetClientRect(hWnd, &rc);

  switch (message)
  {
  case WM_MOUSEMOVE:
    if (wParam & MK_LBUTTON){
      hdc = GetDC(hWnd);
      int x, y;
      x = LOWORD(lParam);
      y = HIWORD(lParam);
      HPEN hPen = CreatePen(PS_SOLID, 1, RGB(rand() % 255, rand() % 255, rand() % 255));
      HBRUSH hOldBrush, hBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
      HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
      hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
      switch (DrawShape)
      {
      case RECTANGLE:
        Ellipse(hdc, x - rand() % 250, y - rand() % 250, x - rand() % 250, y - rand() % 250);
        break;
      case ELLIPSE:
        Rectangle(hdc, x - rand() % 250, y - rand() % 250, x - rand() % 250, y - rand() % 250);
        break;
      }
      SelectObject(hdc, hOldPen);
      SelectObject(hdc, hOldBrush);
      DeleteObject(hPen);
      ReleaseDC(hWnd, hdc);
    }
    break;
  case WM_PAINT:
    hdc = BeginPaint(hWnd, &ps);
    EndPaint(hWnd, &ps);
    break;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  default:
    return DefWindowProc(hWnd, message, wParam, lParam);
  }
  return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
  UNREFERENCED_PARAMETER(lParam);
  switch (message)
  {
  case WM_INITDIALOG:
    return (INT_PTR)TRUE;

  case WM_COMMAND:
    if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
    {
      EndDialog(hDlg, LOWORD(wParam));
      return (INT_PTR)TRUE;
    }
    break;
  }
  return (INT_PTR)FALSE;
}
