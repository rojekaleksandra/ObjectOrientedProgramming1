#pragma once
#include "Wrapper.h"

class FloatWrapper : public Wrapper{
  public:
    FloatWrapper(float x) : _x(x){}
    void print() const override{std::cout << _x;}
    Wrapper* copywrapper() const override{
      return new FloatWrapper(_x);}
    ~FloatWrapper()=default;
  private:
    float _x=0;
};