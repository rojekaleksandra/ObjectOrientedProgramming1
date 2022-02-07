#pragma once
#include "Algo.h"

class Suma : public Algo{
public:
Suma() = default;
Argumenty wykonaj(const Argumenty& x) const{
  Argumenty tmp(1);
  double suma=0;
  for(int i=0;i<x.pokazdl();i++) suma+=x.pokazarg(i);
  tmp(0,suma);
  return tmp;
}

Suma* sklonuj() const{
  return new Suma;
}
};
