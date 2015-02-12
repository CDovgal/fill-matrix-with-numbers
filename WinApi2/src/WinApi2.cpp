// WinApi2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "WinApi2.h"
#include <wchar.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <Shlwapi.h>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];


// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	FileDlgProc(HWND, UINT, WPARAM, LPARAM);

void ShowDirContent(const wchar_t* pDrive, HWND hList);
void SetDrive(HWND hDriveCombo, const wchar_t* drive);

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
  LoadString(hInstance, IDC_WINAPI2, szWindowClass, MAX_LOADSTRING);
  MyRegisterClass(hInstance);

  // Perform application initialization:
  if (!InitInstance(hInstance, nCmdShow))
  {
    return FALSE;
  }

  hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI2));

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



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
  WNDCLASSEX wcex;

  wcex.cbSize = sizeof(WNDCLASSEX);

  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = WndProc;
  wcex.cbClsExtra = 0;
  wcex.cbWndExtra = 0;
  wcex.hInstance = hInstance;
  wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI2));
  wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
  wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  wcex.lpszMenuName = MAKEINTRESOURCE(IDC_WINAPI2);
  wcex.lpszClassName = szWindowClass;
  wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

  return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
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

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  int wmId, wmEvent;
  PAINTSTRUCT ps;
  HDC hdc;

  switch (message)
  {
  case WM_COMMAND:
    wmId = LOWORD(wParam);
    wmEvent = HIWORD(wParam);
    // Parse the menu selections:
    switch (wmId)
    {
    case ID_FILE_OPEN:
      DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_FILE_OPEN), hWnd, FileDlgProc);
      break;
    case IDM_ABOUT:
      DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
      break;
    case IDM_EXIT:
      DestroyWindow(hWnd);
      break;
    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
    }
    break;
  case WM_PAINT:
    hdc = BeginPaint(hWnd, &ps);
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

INT_PTR CALLBACK FileDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
  int wmId, wmEvent;
  static HWND hDriveCombo, hList, hEdit, hEditExtens, hRadioBtnAllThis, hRadioBtnAllExc;
  wchar_t slash[] = L"\\";
  int count = 0;
  static std::wstring dynamic_path;
  static std::vector<std::wstring> dirs;
  
  UNREFERENCED_PARAMETER(lParam);
  switch (message)
  {

  case WM_INITDIALOG:
  {
      hDriveCombo = GetDlgItem(hDlg, IDC_COMBO_ADDDRIVE);
      hList = GetDlgItem(hDlg, IDC_LIST1);
      hEdit = GetDlgItem(hDlg, IDC_PATHEDIT);
      hRadioBtnAllThis = GetDlgItem(hDlg, IDC_RADIO_DELETE_ALLTHIS);
      hRadioBtnAllExc = GetDlgItem(hDlg, IDC_RADIO_DELETE_EXCEPT);
      hEditExtens = GetDlgItem(hDlg, IDC_EDIT_EXTENSIONS);
      wchar_t s_buffer[100];
      int i_id = 0, i = 0;

      SendMessage(hRadioBtnAllExc, BM_SETCHECK, BST_CHECKED, 0);
      GetLogicalDriveStrings(100, s_buffer);
      wchar_t *p_Tok = s_buffer, *pDrive = s_buffer;

      while (*p_Tok != 0)
      {
        if (wcscmp(L"C:\\", p_Tok) == 0)
        {
          i_id = i;
          pDrive = p_Tok;
        }
        ++i;
        SendMessage(hDriveCombo, CB_ADDSTRING, 0, (LPARAM)p_Tok);
        //SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)p_Tok);
        p_Tok += 4;
      }
      SendMessage(hDriveCombo, CB_SETCURSEL, i_id, (LPARAM)p_Tok);
      dynamic_path.append(pDrive);
      SetWindowText(hEdit, dynamic_path.c_str());
      ShowDirContent(pDrive, hList);
      return (INT_PTR)TRUE;
      break;
  }
  case WM_COMMAND:
    wmId = LOWORD(wParam);
    wmEvent = HIWORD(wParam);
    wchar_t s_buffer_drive[10];
    switch (wmId)
    {
    case IDC_RADIO_DELETE_EXCEPT:
      break;
    case IDC_RADIO_DELETE_ALLTHIS:
      break;
    case IDC_BUTTON_DELETE:
      wchar_t s_buffer[50];
      //GetWindowText(hEditExtens, s_buffer, 50);
      wchar_t current[50];
      count = SendMessage(hList, LB_GETCOUNT, 0, 0);
      if (SendMessage(hRadioBtnAllExc, BM_GETCHECK, 0, 0))
      {
        MessageBox(NULL, L"All this deleted.", L"Notification", MB_OK);
      }
      else if (SendMessage(hRadioBtnAllThis, BM_GETCHECK, 0, 0))
      {
        for (int i = 0; i < count; ++i)
        {
          SendMessage(hList, LB_GETTEXT, i, (LPARAM)current);
          GetWindowText(hEditExtens, s_buffer, 50);
          wchar_t *extension = PathFindExtension(current);
          wchar_t *context = NULL;
          wchar_t *token = wcstok_s(s_buffer, L",", &context);
          while (token)
          {
            if (wcscmp(token, extension) == 0)
            {
              const wchar_t *current_path = dynamic_path.c_str();
              wchar_t path_to_delete[100];
              wcscpy_s(path_to_delete, wcslen(current_path) + 1, current_path);
              wcscat_s(path_to_delete, sizeof(current), current);
              BOOL delete_result = DeleteFile(path_to_delete);
              if (!delete_result)
              {
                MessageBox(NULL, L"File haven't been deleted.", path_to_delete, MB_OK);
              }
            }
            token = wcstok_s(NULL, L",", &context);
          }
        }
      }
      SendMessage(hList, LB_RESETCONTENT, 0, 0);
      ShowDirContent(dynamic_path.c_str(), hList);
      break;
    case IDC_EDIT_EXTENSIONS:
      break;
    case IDC_COMBO_ADDDRIVE:
      switch (wmEvent)
      {
      case CBN_SELCHANGE:
      {
          int i_id = 0;
          i_id = SendMessage(hDriveCombo, CB_GETCURSEL, 0, 0);
          if (i_id != CB_ERR)
          {
            SendMessage(hList, LB_RESETCONTENT, 0, 0);
            SendMessage(hDriveCombo, CB_GETLBTEXT, i_id, (LPARAM)s_buffer_drive);
            dynamic_path.clear();
            dirs.clear();
            dynamic_path.append(s_buffer_drive);
            SetWindowText(hEdit, dynamic_path.c_str());
            ShowDirContent(dynamic_path.c_str(), hList);
          }
      }
        break;
      }
      break;
    case IDC_LIST1:
      switch (wmEvent)
      {
      case LBN_SELCHANGE:
        break;
      case LBN_DBLCLK:
        int lb_cur = SendMessage(hList, LB_GETCURSEL, 0, 0);
        wchar_t current[50];
        if (lb_cur != LB_ERR)
        {
          SendMessage(hList, LB_GETTEXT, lb_cur, (LPARAM)current);
          if (wcscmp(L".", current) == 0)
          {
            std::wstring::size_type found = dynamic_path.rfind(dirs.back());
            if (found != std::wstring::npos)
            {
              dynamic_path.erase(found);
              dirs.pop_back();
            }
            SendMessage(hList, LB_RESETCONTENT, 0, 0);
            SetWindowText(hEdit, dynamic_path.c_str());
            ShowDirContent(dynamic_path.c_str(), hList);
          }
          else if (wcscmp(L"..", current) == 0)
          {
            int cb_id = SendMessage(hDriveCombo, CB_GETCURSEL, 0, 0);
            if (cb_id != CB_ERR)
            {
              wchar_t drive[10];
              SendMessage(hDriveCombo, CB_GETLBTEXT, cb_id, (LPARAM)drive);
              SetWindowText(hEdit, drive);
              SendMessage(hList, LB_RESETCONTENT, 0, 0);
              ShowDirContent(drive, hList);
              dirs.clear();
              dynamic_path.clear();
              dynamic_path.append(drive);
            }
          }
          else
          {
            dynamic_path.append(current);
            dynamic_path.append(slash);
            dirs.push_back(current);
            SendMessage(hList, LB_RESETCONTENT, 0, 0);
            SetWindowText(hEdit, dynamic_path.c_str());
            ShowDirContent(dynamic_path.c_str(), hList);
          }
          
        }
        break;
      }
      break;
    case IDOK:
    case IDCANCEL:
      EndDialog(hDlg, LOWORD(wParam));
      return (INT_PTR)TRUE;
    case IDC_BUTTON_GO:
      wchar_t s_path[MAX_PATH];
      GetWindowText(hEdit, s_path, MAX_PATH);
      dynamic_path.clear();
      dynamic_path.append(s_path);
      SendMessage(hList, LB_RESETCONTENT, 0, 0);
      ShowDirContent(s_path, hList);
      wchar_t *context = NULL;
      wchar_t *token = wcstok_s(s_path, L"\\", &context);
      while (token)
      {
        dirs.push_back(token);
        token = wcstok_s(NULL, L"\\", &context);
      }
      break;
    }
  }
  return (INT_PTR)FALSE;
}


void SetDrive(HWND hDriveCombo, const wchar_t* drive)
{
  
}

void ShowDirContent(const wchar_t* pDrive, HWND hList)
{
  wchar_t sOut[100];
  wsprintf(sOut, L"%s*.*", pDrive);
  WIN32_FIND_DATA wf;
  HANDLE hFile = FindFirstFile(sOut, &wf);
  if (hFile != INVALID_HANDLE_VALUE)
  {
    BOOL bOk = TRUE;
    while (bOk)
    {
      SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)wf.cFileName);
      bOk = FindNextFile(hFile, &wf);
    }
    FindClose(hFile);
  }
}





