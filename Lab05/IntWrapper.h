#pragma once
#include "Wrapper.h"

class IntWrapper : public Wrapper{
  public:
    IntWrapper(int x) : _x(x){}
    void print() const override {std::cout << _x;}
    Wrapper* copywrapper() const override{
      return new IntWrapper(_x);}
    ~IntWrapper()=default;
  private:
    int _x=0;
};