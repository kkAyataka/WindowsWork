#include <iostream>

#include <Windows.h>

int main(const int argc, const char * const argv[]) {
  HDESK desk0 = GetThreadDesktop(GetCurrentThreadId());

  HDESK desk1 = CreateDesktop(
    L"Desktop1",
    NULL, // reserved parameter
    NULL, // reserved parameter
    0,
    GENERIC_ALL,
    NULL
    );

  BOOL r = SetThreadDesktop(desk1);

  wchar_t exe[100] = { L"explorer.exe " };
  STARTUPINFO si = {};
  si.cb = sizeof(STARTUPINFO);
  si.lpDesktop = L"Desktop1";
  PROCESS_INFORMATION pi = {};
  CreateProcess(
    NULL,
    exe,
    NULL,
    NULL,
    FALSE,
    0,
    NULL,
    NULL,
    &si,
    &pi
    );

  BOOL res = SwitchDesktop(desk1);

  //SetThreadDesktop(desk1);

  Sleep(3 * 1000);

  res = SwitchDesktop(desk0);

  //SetThreadDesktop(desk0);

  CloseDesktop(desk1);

  return 0;
}
