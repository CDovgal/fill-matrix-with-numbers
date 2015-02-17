// WinApi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "WinApi_Graphic.h"
#include <Winspool.h>
#include <vector>
#include <CommDlg.h>
#include <iostream>
#include <fstream>
#include <Shlwapi.h>
#include "Image_Data.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];
TCHAR szChild1[MAX_LOADSTRING];
TCHAR szChild2[MAX_LOADSTRING];
TCHAR szFileName[MAX_PATH];
void RedrawImage(HDC hdc);



static DrawKind DrawShape;
static std::vector<Image_Object> object_container;

void SaveImage(wchar_t *filename)
{
  std::ofstream myfile;
  myfile.open(filename);
  if (myfile.is_open())
  {
    myfile << object_container.size() << std::endl;
    for (unsigned i = 0; i < object_container.size(); ++i)
    {
      myfile << object_container.at(i);
    }
  }
  else
    std::cout << "Unable to open file\n";
  myfile.close();
}

void LoadImageFrom(const wchar_t *filename)
{
  Image_Object obj;
  size_t shapes_count;
  std::ifstream myfile(filename);
  if (myfile.is_open())
  {
    myfile >> shapes_count;
    object_container.resize(shapes_count);
    for (size_t i = 0; i < shapes_count;)
    {
      myfile >> obj;
      object_container.push_back(obj);
      ++i;
    }
  }
  else
    std::cout << "Unable to open file\n";
  myfile.close();
}





// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
BOOL OpenFileDialog(HWND hwnd, LPTSTR pFileName, LPTSTR pTitleName);
BOOL SaveFileDialog(HWND hwnd, LPTSTR pFileName, LPTSTR pTitleName);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
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
  SaveImage(pFileName);
  return GetSaveFileName(&ofn);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  int wmId, wmEvent;
  HDC hdc;
  BOOL result;
  PAINTSTRUCT ps;
  
  int x, y;
  
  switch (message)
  {
  case WM_CREATE:
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
      result = SaveFileDialog(hWnd, szFileName, L"Save an Image");
      if (!result)
      {
        MessageBox(NULL, L"Cannot save file", L"Error", MB_OK);
      }
      break;
    case IDM_OPENFILE:
      RECT rc;
      GetClientRect(hWnd, &rc);
      result = OpenFileDialog(hWnd, szFileName, L"Open an image");
      if (!result)
      {
        MessageBox(NULL, L"Cannot open file", L"Error", MB_OK);
      }
      LoadImageFrom(szFileName);
      InvalidateRect(hWnd, &rc, TRUE);
      hdc = GetDC(hWnd);
      RedrawImage(hdc);
      ReleaseDC(hWnd, hdc);
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
    case WM_MOUSEMOVE:
    if (wParam & MK_LBUTTON){
      hdc = GetDC(hWnd);
      x = LOWORD(lParam);
      y = HIWORD(lParam);
      //int p_r = rand() % 255;
      const COLORREF penColorRed = RGB(255, 0, 0);
      const COLORREF brushColorGreen = RGB(0, 255, 128);
      HPEN hPen = CreatePen(PS_SOLID, 1, penColorRed);
      HBRUSH hOldBrush, hBrush = CreateSolidBrush(brushColorGreen);
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
        DrawKind type = RECTANGLE;
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
        DrawKind type = ELLIPSE;
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
  case WM_SIZE:
    //InvalidateRect(hWnd, 0, TRUE);
    break;
  case WM_PAINT:
     hdc = BeginPaint(hWnd, &ps);
     RedrawImage(hdc);
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


void RedrawImage(HDC hdc)
{
  for (unsigned i = 0; i < object_container.size(); ++i)
  {
    HPEN hPen = CreatePen(PS_SOLID, 1, object_container.at(i).color.m_pen_color);
    HBRUSH hOldBrush, hBrush = CreateSolidBrush(object_container.at(i).color.m_brush_color);
    HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
    hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
    
    if (object_container.at(i).type == RECTANGLE)
      Rectangle(hdc, object_container.at(i).size.left, object_container.at(i).size.top, object_container.at(i).size.right, object_container.at(i).size.bottom);
    else if (object_container.at(i).type == ELLIPSE)
      Ellipse(hdc, object_container.at(i).size.left, object_container.at(i).size.top, object_container.at(i).size.right, object_container.at(i).size.bottom);
    
    SelectObject(hdc, hOldPen);
    SelectObject(hdc, hOldBrush);
    DeleteObject(hPen);
  }
}
