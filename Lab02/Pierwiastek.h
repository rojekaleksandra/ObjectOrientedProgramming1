#pragma once
#include "Algo.h"
#include <cmath>

class Pierwiastek : public Algo{
public:
  Argumenty wykonaj(const Argumenty& x) const{
    Argumenty tmp (x.pokazdl());
    for(int i=0;i<x.pokazdl();i++) tmp(i,sqrt(x.pokazarg(i)));
    return tmp;
  }

  Pierwiastek*  sklonuj() const{
    return new Pierwiastek;
  }
};
