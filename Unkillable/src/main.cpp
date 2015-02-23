#include <iostream>
#include <Windows.h>

int main()
{
  char *name;
  std::cout << "Enter application name" << std::endl;
  std::cin >> name;

  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  SECURITY_ATTRIBUTES sa;

  ZeroMemory(&pi, sizeof(pi));

  ZeroMemory(&si, sizeof(si));
  si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
  si.wShowWindow = SW_HIDE;
  si.cb = sizeof(si);

  HANDLE hndl = (HANDLE)CreateProcess(NULL,
    (LPWSTR)name,
    NULL,
    NULL,
    TRUE,
    0,
    NULL,
    NULL,
    &si,
    &pi)
    );
    MessageBox(NULL, L"Create Process failed.\n", L"Error creating process", MB_OK | MB_ICONSTOP);
    return 0;

  

}