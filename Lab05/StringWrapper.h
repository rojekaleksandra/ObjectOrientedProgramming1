#pragma once
#include <cstring>
#include "Wrapper.h"

class StringWrapper : public Wrapper{
  public:
    StringWrapper(const char* x){strcpy(_x,x);}
    void print() const override{std::cout << _x;}
    Wrapper* copywrapper() const override{
      return new StringWrapper(_x);}
    ~StringWrapper()=default;
  private:
    char _x[80];
};