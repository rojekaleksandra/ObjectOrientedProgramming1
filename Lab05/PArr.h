#pragma once
#include "Wrapper.h"
#include <iostream>

class PArr{
  friend std::ostream& operator<<(std::ostream &o, const PArr& w);
  public:
    PArr(int size);
    PArr(PArr&& p);
    Wrapper *& operator[](int i) const;
    PArr& operator=(const PArr& w);
    ~PArr();

  private:
    int _size=0;
    Wrapper ** _w;
};

std::ostream& operator<<(std::ostream &o, const PArr& w);