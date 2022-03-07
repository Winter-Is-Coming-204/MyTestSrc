#pragma once
#include "CommonDefine.h"

#define MY_EXPORT_API __declspec(dllexport)
#ifdef __cplusplus
extern "C"
{
#endif

  MY_EXPORT_API BaseClass* InitModule();
  MY_EXPORT_API void DeleteModule(BaseClass* pModule);

#ifdef __cplusplus
}
#endif

class MyClass : public BaseClass
{
public:
	MyClass();
	~MyClass();

public:
  virtual void Func1();
};

