#include <iostream>
#include <Windows.h>

int main()
{
  wchar_t sStr[20000];
  std::cout << "Enter application name" << std::endl;
  std::wcin.getline(sStr, 512);


  HANDLE procHndl;
  DWORD dwProcessId;
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  SECURITY_ATTRIBUTES sa;

  sa.nLength = sizeof(sa);
  sa.lpSecurityDescriptor = NULL;
  sa.bInheritHandle = true;

  ZeroMemory(&pi, sizeof(pi));

  ZeroMemory(&si, sizeof(si));
  si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
  si.wShowWindow = SW_SHOWNORMAL;
  si.cb = sizeof(si);

  //wchar_t sStr[20000] = L"D:\\WinApi_Graphic.exe";

  if (!CreateProcess(NULL, (LPWSTR)sStr, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi))
  {
    MessageBox(NULL, L"Create Process failed.\n", L"Error creating process", MB_OK | MB_ICONSTOP);
    return 0;
  }

  while (true)
  {
    DWORD result = WaitForSingleObject(pi.hProcess, 0);
    switch (result)
    {
    case WAIT_OBJECT_0:
      CreateProcess(NULL, (LPWSTR)sStr, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
      break;
    defualt:
      break;
    }
  }

  return 0;
}