#pragma once
class BaseClass
{
public:
  BaseClass() {}
  virtual ~BaseClass() {}

public:
  virtual void Func1() = 0;
};
