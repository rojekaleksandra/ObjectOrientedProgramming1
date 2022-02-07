#pragma once
#include <iostream>

class Wrapper{
  public:
    Wrapper()=default;
    virtual void print() const=0;
    virtual Wrapper* copywrapper() const=0;
    virtual ~Wrapper()=default;
};