// WinApi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "WinApi_Graphic.h"
#include <Winspool.h>
#include <vector>
#include <CommDlg.h>
#include <iostream>
#include <fstream>


#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];
TCHAR szChild1[MAX_LOADSTRING];
TCHAR szChild2[MAX_LOADSTRING];
TCHAR szFileName[500] = L"default";
BOOL resized = FALSE;
void RedrawWindow(HWND hWND, HDC hDc);

enum DrawKind
{
  RECTANGLE,
  ELLIPSE
};

enum Shape_type
{
  Rect,
  Ell
};

struct Color
{
  COLORREF m_pen_color,
  m_brush_color;
  Color(COLORREF pen_color, COLORREF brush_color) :
    m_pen_color(pen_color),
    m_brush_color(brush_color){}
};

struct Shape_size
{
  int left,
  top,
  right,
  bottom;
  Shape_size(int i_left, int i_top, int i_right, int i_bottom): 
    left(i_left), 
    top(i_top), 
    right(i_right), 
    bottom(i_bottom){}
};

struct Shape_coords
{
  int x, y;
  Shape_coords(int i_x, int i_y) :
    x(i_x),
    y(i_y){}
};

struct Image_Object
{
  Shape_size size;
  Shape_coords coords;
  Color color;
  Shape_type type;
  Image_Object(const Shape_size& i_size, const Shape_coords& i_coords, const Color& i_color, const Shape_type& i_type) : 
    size(i_size),
    coords(i_coords),
    color(i_color), 
    type(i_type){}
};

static DrawKind DrawShape;
static std::vector<Image_Object> object_container;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
ATOM				MyChildRegisterClass1(HINSTANCE hInstance);
//ATOM				MyChildRegisterClass2(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
BOOL OpenFileDialog(HWND hwnd, LPTSTR pFileName, LPTSTR pTitleName);
BOOL SaveFileDialog(HWND hwnd, LPTSTR pFileName, LPTSTR pTitleName);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	WndChildProcLeft(HWND, UINT, WPARAM, LPARAM);
//LRESULT CALLBACK	WndChildProcRight(HWND, UINT, WPARAM, LPARAM);
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
  //MyChildRegisterClass2(hInstance);

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


//ATOM MyChildRegisterClass2(HINSTANCE hInstance)
//{
//  WNDCLASSEX wcex = { 0 };
//
//  wcex.cbSize = sizeof(WNDCLASSEX);
//
//  wcex.style = CS_HREDRAW | CS_VREDRAW;
//  wcex.lpfnWndProc = WndChildProcRight;
//  wcex.cbClsExtra = 0; // YOU SHALL NOT WATCH!!!!!!
//  wcex.cbWndExtra = 0;
//  wcex.hInstance = hInstance;
//  wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
//  wcex.hbrBackground = CreateSolidBrush(RGB(248, 248, 255));//(HBRUSH)(COLOR_WINDOW + 1);
//  wcex.lpszClassName = L"Child2";
//
//  return RegisterClassEx(&wcex);
//}

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

BOOL OpenFileDialog(HWND hwnd, LPTSTR pFileName, LPTSTR pTitleName)
{
  OPENFILENAME ofn = { 0 };
  ofn.lStructSize = sizeof(OPENFILENAME);
  ofn.hInstance = GetModuleHandle(NULL);
  ofn.lpstrCustomFilter = NULL;
  ofn.nMaxCustFilter = 0;
  ofn.nFilterIndex = 0;
  ofn.hwndOwner = hwnd;
  ofn.lpstrFile = pFileName;
  ofn.lpstrFileTitle = NULL;
  ofn.lpstrTitle = pTitleName;
  ofn.nMaxFile = MAX_PATH;
  ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
  ofn.lpstrInitialDir = L"D:\\Projects\\WinApi_Graphic\\bin\\WinApi_Graphic\\WinApi_Graphic";
  ofn.lpstrFilter = L"Image data files v1(*.idf1)\0*.idf1\0" L"Image data files v2(*.idf2)\0*.idf2\0" L"Image data files v3(*.idf3)\0*.idf3\0\0";

  return GetOpenFileName(&ofn);
}

BOOL SaveFileDialog(HWND hwnd, LPTSTR pFileName, LPTSTR pTitleName)
{
  OPENFILENAME ofn = { 0 };
  ofn.lStructSize = sizeof(OPENFILENAME);
  ofn.hInstance = GetModuleHandle(NULL);
  ofn.lpstrCustomFilter = NULL;
  ofn.nMaxCustFilter = 0;
  ofn.nFilterIndex = 0;
  ofn.hwndOwner = hwnd;
  ofn.lpstrFile = pFileName;
  ofn.lpstrFileTitle = NULL;
  ofn.lpstrTitle = pTitleName;
  ofn.nMaxFile = MAX_PATH;
  ofn.Flags = OFN_EXPLORER | OFN_OVERWRITEPROMPT;
  ofn.lpstrInitialDir = L"D:\\Projects\\WinApi_Graphic\\bin\\WinApi_Graphic\\WinApi_Graphic";
  ofn.lpstrFilter = L"Image data files v1(*.idf1)\0*.idf1\0" L"Image data files v2(*.idf2)\0*.idf2\0" L"Image data files v3(*.bmp)\0*.idf3\0\0";

  return GetSaveFileName(&ofn);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  int wmId, wmEvent;
  PAINTSTRUCT ps;
  HDC hdc;
  BOOL result;
  int x, y;

  switch (message)
  {
  case WM_CREATE:
    RECT rc;
    GetClientRect(hWnd, &rc);
    CreateWindow(L"Child1", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 0, rc.right, rc.bottom, hWnd, (HMENU)IDC_PANEL, hInst, NULL);
    //CreateWindow(L"Child2", L"", WS_CHILDWINDOW | WS_VISIBLE | WS_BORDER, rc.right / 2 + 10, 10, rc.right / 2 - 10, rc.bottom - 10, hWnd, (HMENU)IDC_PANEL2, hInst, NULL);
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
      result = SaveFileDialog(hWnd, L"default.png", L"Save an Image");
      if (!result)
      {
        MessageBox(NULL, L"Cannot save file", L"Error", MB_OK);
      }
      break;
    case IDM_OPENFILE:
      result = OpenFileDialog(hWnd, szFileName, L"Open an image");
      if (!result)
      {
        MessageBox(NULL, L"Cannot open file", L"Error", MB_OK);
      }
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
    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
    }
    break;
  case WM_SIZE:
  {
    resized = TRUE;
  }
    break;
  case WM_PAINT:
  {       
     hdc = BeginPaint(hWnd, &ps);
     // TODO: Add any drawing code here...
     EndPaint(hWnd, &ps);
  }
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
  //int wmId, wmEvent;
  PAINTSTRUCT ps;
  HDC hdc;
  RECT rc;
  GetClientRect(hWnd, &rc);
  int x, y;

  switch (message)
  {
  case WM_MOUSEMOVE:
    if (wParam & MK_LBUTTON){
      hdc = GetDC(hWnd);
      x = LOWORD(lParam);
      y = HIWORD(lParam);

      HPEN hPen = CreatePen(PS_SOLID, 1, RGB(rand() % 255, rand() % 255, rand() % 255));
      HBRUSH hOldBrush, hBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
      HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
      hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
      switch (DrawShape)
      {
      case RECTANGLE:
      {
        Rectangle(hdc, x + 100, y + 100, x - 50, y - 50);
        Shape_coords coords(x, y);
        Shape_size size((x + 100), (y + 100), (x - 50), (y - 50));
        Color color(GetDCPenColor(hdc), GetDCBrushColor(hdc));
        Shape_type type = Rect;
        Image_Object object(size, coords, color, type);
        object_container.push_back(object);
      }
        break;
      case ELLIPSE:
      {
        Ellipse(hdc, x + 100, y + 100, x - 50, y - 50);
        Shape_coords coords(x, y);
        Shape_size size((x + 100), (y + 100), (x - 50), (y - 50));
        Color color(GetDCPenColor(hdc), GetDCBrushColor(hdc));
        Shape_type type = Ell;
        Image_Object object(size, coords, color, type);
        object_container.push_back(object);
      }
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
    RedrawWindow(hWnd, hdc);
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

//LRESULT CALLBACK WndChildProcRight(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//  //int wmId, wmEvent;
//  PAINTSTRUCT ps;
//  HDC hdc;
//  int nShift = 80;
//  RECT rc;
//  GetClientRect(hWnd, &rc);
//
//  switch (message)
//  {
//  case WM_MOUSEMOVE:
//    if (wParam & MK_LBUTTON){
//      hdc = GetDC(hWnd);
//      int x, y;
//      x = LOWORD(lParam);
//      y = HIWORD(lParam);
//      HPEN hPen = CreatePen(PS_SOLID, 1, RGB(rand() % 255, rand() % 255, rand() % 255));
//      HBRUSH hOldBrush, hBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
//      HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
//      hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
//      switch (DrawShape)
//      {
//      case RECTANGLE:
//        //Ellipse(hdc, x - rand() % 250, y - rand() % 250, x - rand() % 250, y - rand() % 250);
//        Ellipse(hdc, x + 100, y + 100, x - 50, y - 50);
//        break;
//      case ELLIPSE:
//        //Rectangle(hdc, x - rand() % 250, y - rand() % 250, x - rand() % 250, y - rand() % 250);
//        Rectangle(hdc, x+100, y+100, x-50, y-50);
//        break;
//      }
//      SelectObject(hdc, hOldPen);
//      SelectObject(hdc, hOldBrush);
//      DeleteObject(hPen);
//      ReleaseDC(hWnd, hdc);
//    }
//    break;
//  case WM_PAINT:
//    hdc = BeginPaint(hWnd, &ps);
//    RedrawWindow(hWnd, hdc);
//    EndPaint(hWnd, &ps);
//    break;
//  case WM_DESTROY:
//    PostQuitMessage(0);
//    break;
//  default:
//    return DefWindowProc(hWnd, message, wParam, lParam);
//  }
//  return 0;
//}

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


void RedrawWindow(HWND hWND, HDC hDC)
{
  hDC = GetDC(hWND);
  //HPEN hPen;
  //HBRUSH hOldBrush, hBrush;
  //HPEN hOldPen;
  for (unsigned i = 0; i < object_container.size(); ++i)
  {
    HPEN hPen = CreatePen(PS_SOLID, 1, object_container.at(i).color.m_pen_color);
    HBRUSH hOldBrush, hBrush = CreateSolidBrush(object_container.at(i).color.m_brush_color);
    HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);
    hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
    SelectObject(hDC, hOldPen);
    SelectObject(hDC, hOldBrush);
    if (object_container.at(i).type == Rect)
      Rectangle(hDC, object_container.at(i).size.left, object_container.at(i).size.top, object_container.at(i).size.right, object_container.at(i).size.bottom);
    else
      Ellipse(hDC, object_container.at(i).size.left, object_container.at(i).size.top, object_container.at(i).size.right, object_container.at(i).size.bottom);
    
    DeleteObject(hPen);
  }
  ReleaseDC(hWND, hDC);
}
