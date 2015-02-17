// WinApi2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "WinApi2.h"
#include <wchar.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <Shlwapi.h>
#include <sstream>
#include <shellapi.h>

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
BOOL DeleteFromDir(const std::wstring& path, const wchar_t *current);
BOOL DeleteAllExceptThis(HWND hList, HWND hEditEx, const std::wstring& dyn_path);
BOOL DeleteAllThis(HWND hList, HWND hEditEx, const std::wstring& dyn_path);
void ReloadDrive(HWND hCB, HWND hList, HWND hPathEdit, std::wstring& dyn_path, std::vector<std::wstring>& dirs);
void LoadDrives(HWND hCB, HWND hList, HWND hPathEdit, std::wstring& dyn_path);
void GoDirUp(HWND hList, HWND hEdit, std::wstring& dyn_path, std::vector<std::wstring>& dirs);
void GoRoot(HWND hCB, HWND hList, HWND hEdit, std::wstring& dyn_path, std::vector<std::wstring>& dirs);
void GoToNextDir(HWND hList, HWND hEdit, std::wstring& dyn_path, std::vector<std::wstring>& dirs, const wchar_t *cur_dir);
void GoToPath(HWND hList, HWND hEdit, std::wstring& dyn_path, std::vector<std::wstring>& dirs);
BOOL IsFolder(const std::wstring& current);
void OpenImage(const wchar_t *filename);

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

      SendMessage(hRadioBtnAllExc, BM_SETCHECK, BST_CHECKED, 0);

      LoadDrives(hDriveCombo, hList, hEdit, dynamic_path);
      
      return (INT_PTR)TRUE;
      break;
  }
  case WM_COMMAND:
    wmId = LOWORD(wParam);
    wmEvent = HIWORD(wParam);
    
    switch (wmId)
    {
    case IDC_BUTTON_DELETE:
      if (SendMessage(hRadioBtnAllExc, BM_GETCHECK, 0, 0))
      {
        DeleteAllExceptThis(hList, hEditExtens, dynamic_path);
      }
      else if (SendMessage(hRadioBtnAllThis, BM_GETCHECK, 0, 0))
      {
        DeleteAllThis(hList, hEditExtens, dynamic_path);
      }
      SendMessage(hList, LB_RESETCONTENT, 0, 0);
      ShowDirContent(dynamic_path.c_str(), hList);
      break;
    case IDC_COMBO_ADDDRIVE:
      switch (wmEvent)
      {
      case CBN_SELCHANGE:
      {
        ReloadDrive(hDriveCombo, hList, hEdit, dynamic_path, dirs);
      }
        break;
      }
      break;
    case IDC_LIST1:
      switch (wmEvent)
      {
      case LBN_DBLCLK:
        int lb_cur = SendMessage(hList, LB_GETCURSEL, 0, 0);
        wchar_t current[50];
        if (lb_cur != LB_ERR)
        {
          SendMessage(hList, LB_GETTEXT, lb_cur, (LPARAM)current);
          std::wstring cur_sel(current);
          std::wstring whole_path(dynamic_path);
          whole_path.append(cur_sel);
          wchar_t *extension = PathFindExtension(current);
          if (wcscmp(L".", current) == 0)
          {
            GoDirUp(hList, hEdit, dynamic_path, dirs);
          }
          else if (wcscmp(L"..", current) == 0)
          {
            GoRoot(hDriveCombo, hList, hEdit, dynamic_path, dirs);
          }
          else if (wcscmp(extension, L".idf1") == 0 || wcscmp(extension, L".idf2") == 0 || wcscmp(extension, L".idf3") == 0)
          {
            wchar_t w_path[MAX_PATH];
            wcscpy_s(w_path, wcslen(dynamic_path.c_str())+1, dynamic_path.c_str());
            wcscat_s(w_path, sizeof(w_path), current);
            OpenImage(w_path);
            //MessageBox(NULL, current, L"Image Data File", MB_OK | MB_ICONINFORMATION);
          }
          else if (!IsFolder(whole_path))
          {
            MessageBox(NULL, current, L"File not supported", MB_OK | MB_ICONSTOP);
          }
          else
          {
            GoToNextDir(hList, hEdit, dynamic_path, dirs, current);
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
      GoToPath(hList, hEdit, dynamic_path, dirs);
      break;
    }
  }
  return (INT_PTR)FALSE;
}


void OpenImage(const wchar_t *filename)
{
  STARTUPINFO si;
  PROCESS_INFORMATION pi;

  /*GetStartupInfo(&si);
  if (!CreateProcess(L"D:\\Projects\\WinApi_Graphic\\bin\\WinApi_Graphic\\Debug\\WinApi_Graphic.exe",
    NULL,
    NULL,
    NULL,
    FALSE,
    0,
    NULL,
    NULL,
    &si,
    &pi))
  {
    MessageBox(NULL, L"Couldnt open image.", L"Error", MB_OK | MB_ICONERROR);
  }*/

  if ((UINT)ShellExecute(
    GetDesktopWindow(),
    L"open",
    L"D:\\qwerty.txt",
    NULL,
    NULL,
    SW_SHOWNORMAL) <= 32) 
  {
    MessageBox(NULL, L"Executable file error.", L"Error", MB_OK | MB_ICONERROR);
  }
}

BOOL IsFolder(const std::wstring& current)
{
  DWORD file_attributes = GetFileAttributes(current.c_str()); 
  if (file_attributes == FILE_ATTRIBUTE_DIRECTORY)
    return true;
  else
    return false;
}

void GoToNextDir(HWND hList, HWND hEdit, std::wstring& dyn_path, std::vector<std::wstring>& dirs, const wchar_t *cur_dir)
{
  wchar_t slash[] = L"\\";
  dyn_path.append(cur_dir);
  dyn_path.append(slash);
  dirs.push_back(cur_dir);
  SendMessage(hList, LB_RESETCONTENT, 0, 0);
  SetWindowText(hEdit, dyn_path.c_str());
  ShowDirContent(dyn_path.c_str(), hList);
}


void GoToPath(HWND hList, HWND hEdit, std::wstring& dyn_path, std::vector<std::wstring>& dirs)
{
  wchar_t s_path[MAX_PATH];
  GetWindowText(hEdit, s_path, MAX_PATH);
  dyn_path.clear();
  dyn_path.append(s_path);
  SendMessage(hList, LB_RESETCONTENT, 0, 0);
  ShowDirContent(s_path, hList);
  wchar_t *context = NULL;
  wchar_t *token = wcstok_s(s_path, L"\\", &context);
  while (token)
  {
    dirs.push_back(token);
    token = wcstok_s(NULL, L"\\", &context);
  }
}

void GoDirUp(HWND hList, HWND hEdit, std::wstring& dyn_path, std::vector<std::wstring>& dirs)
{
  std::wstring::size_type found = dyn_path.rfind(dirs.back());
  if (found != std::wstring::npos)
  {
    dyn_path.erase(found);
    dirs.pop_back();
  }
  SendMessage(hList, LB_RESETCONTENT, 0, 0);
  SetWindowText(hEdit, dyn_path.c_str());
  ShowDirContent(dyn_path.c_str(), hList);
}

void GoRoot(HWND hCB, HWND hList, HWND hEdit, std::wstring& dyn_path, std::vector<std::wstring>& dirs)
{
  int cb_id = SendMessage(hCB, CB_GETCURSEL, 0, 0);
  if (cb_id != CB_ERR)
  {
    wchar_t drive[10];
    SendMessage(hCB, CB_GETLBTEXT, cb_id, (LPARAM)drive);
    SetWindowText(hEdit, drive);
    SendMessage(hList, LB_RESETCONTENT, 0, 0);
    ShowDirContent(drive, hList);
    dirs.clear();
    dyn_path.clear();
    dyn_path.append(drive);
  }
}

void ReloadDrive(HWND hCB, HWND hList, HWND hPathEdit, std::wstring& dyn_path, std::vector<std::wstring>& dirs)
{
  wchar_t s_buffer_drive[10];
  int i_id = 0;
  i_id = SendMessage(hCB, CB_GETCURSEL, 0, 0);
  if (i_id != CB_ERR)
  {
    SendMessage(hList, LB_RESETCONTENT, 0, 0);
    SendMessage(hCB, CB_GETLBTEXT, i_id, (LPARAM)s_buffer_drive);
    dyn_path.clear();
    dirs.clear();
    dyn_path.append(s_buffer_drive);
    SetWindowText(hPathEdit, dyn_path.c_str());
    ShowDirContent(dyn_path.c_str(), hList);
  }
}


BOOL DeleteFromDir(const std::wstring& path, const wchar_t *current)
{
  const wchar_t *current_path = path.c_str();
  static wchar_t path_to_delete[MAX_PATH];
  wcscpy_s(path_to_delete, wcslen(current_path) + 1, current_path);
  wcscat_s(path_to_delete, sizeof(path_to_delete), current);
  return DeleteFile(path_to_delete);
}

BOOL DeleteAllExceptThis(HWND hList, HWND hEditEx, const std::wstring& dyn_path)
{
  BOOL status;
  wchar_t s_buffer[50];
  wchar_t current[50];
  int count = SendMessage(hList, LB_GETCOUNT, 0, 0);
  for (int i = 0; i < count; ++i)
  {
    count = SendMessage(hList, LB_GETCOUNT, 0, 0);
    SendMessage(hList, LB_GETTEXT, i, (LPARAM)current);
    GetWindowText(hEditEx, s_buffer, 50);
    wchar_t *extension = PathFindExtension(current);
    wchar_t *context = NULL;
    BOOL is_equal;
    wchar_t *token = wcstok_s(s_buffer, L", ", &context);
    while (token)
    {
      if (wcscmp(token, extension) != 0)
      {
        token = wcstok_s(NULL, L", ", &context);
        is_equal = FALSE;
      }
      else
      {
        is_equal = TRUE;
        break;
      }
    }
    if (!is_equal)
    {
      status = DeleteFromDir(dyn_path, current);
    }
  }
  return status;
}
BOOL DeleteAllThis(HWND hList, HWND hEditEx, const std::wstring& dyn_path)
{
  BOOL status;
  wchar_t s_buffer[50];
  wchar_t current[50];
  int count = SendMessage(hList, LB_GETCOUNT, 0, 0);
  for (int i = 0; i < count; ++i)
  {
    count = SendMessage(hList, LB_GETCOUNT, 0, 0);
    SendMessage(hList, LB_GETTEXT, i, (LPARAM)current);
    GetWindowText(hEditEx, s_buffer, 50);
    wchar_t *extension = PathFindExtension(current);
    wchar_t *context = NULL;
    wchar_t *token = wcstok_s(s_buffer, L", ", &context);
    while (token)
    {
      if (wcscmp(token, extension) == 0)
      {
        if (!DeleteFromDir(dyn_path, current))
        {
          status = FALSE;
          MessageBox(NULL, current, L"File haven't been deleted.", MB_OK);
        }
      }
      token = wcstok_s(NULL, L", ", &context);
    }
  }
  return status;
}


void LoadDrives(HWND hCB, HWND hList, HWND hPathEdit, std::wstring& dyn_path)
{
  wchar_t s_buffer[100];
  int i_id = 0, i = 0;

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
    SendMessage(hCB, CB_ADDSTRING, 0, (LPARAM)p_Tok);
    p_Tok += 4;
  }
  SendMessage(hCB, CB_SETCURSEL, i_id, (LPARAM)p_Tok);
  dyn_path.append(pDrive);
  SetWindowText(hPathEdit, dyn_path.c_str());
  ShowDirContent(pDrive, hList);
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





