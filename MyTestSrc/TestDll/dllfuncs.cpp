#include "dllfuncs.h"
#include <iostream>
using namespace std;

MY_EXPORT_API BaseClass* InitModule()
{
  cout << "InitModule" << endl;
  return (BaseClass*)new MyClass;
}

MY_EXPORT_API void DeleteModule(BaseClass* pModule)
{
  cout << "DeleteModule" << endl;
  if (NULL != pModule) {
    delete pModule;
    pModule = NULL;
  }
}

MyClass::MyClass()
{
  cout << "MyClass::MyClass" << endl;
}

MyClass::~MyClass()
{
  cout << "MyClass::~MyClass" << endl;
}

void MyClass::Func1()
{
  cout << "Func1" << endl;
}