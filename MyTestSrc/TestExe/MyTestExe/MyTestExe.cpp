#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <set>
#include "CommonDefine.h"

using namespace std;

#ifdef _CONSOLE

#endif // _CONSOLE


typedef BaseClass* (*m_pInitModule)();
typedef void (*m_pDeleteModule)(BaseClass* pMudule);

m_pInitModule g_pInitModule;
m_pDeleteModule g_pDeleteModule;

int main()
{
  HMODULE hModule = LoadLibrary(_T("TestDll.dll"));
  cout << "hModule:" << hModule << endl;

  if (NULL != hModule) {
    g_pInitModule = (m_pInitModule)GetProcAddress(hModule, "InitModule");
    g_pDeleteModule = (m_pDeleteModule)GetProcAddress(hModule, "DeleteModule");
    cout << "g_pInitModule:" << g_pInitModule << endl;
    cout << "g_pDeleteModule:" << g_pDeleteModule << endl;
  }

  if (NULL != g_pInitModule) {
    BaseClass* pClass = g_pInitModule();
    if (NULL != pClass)
      pClass->Func1();

    if (NULL != g_pDeleteModule)
      g_pDeleteModule(pClass);
  }


  set<int> ints;
  ints.insert(1);
  ints.insert(1);
  ints.insert(2);
  cout << "ints size:" << ints.size() << endl;

  system("pause");
}
