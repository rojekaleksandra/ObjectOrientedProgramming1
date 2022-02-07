#include "Argumenty.h"

Argumenty::Argumenty(int x){
  _argumenty = new double[x];
  _dlarg=x;
}

Argumenty& Argumenty::operator()(int ind, double wart){
  _argumenty[ind] = wart;
  return *this;
}

void Argumenty::print(std::string napis, std::ostream& s) const{
  s << napis;
  for (int i=0;i<_dlarg;i++) std::cout << " " << _argumenty[i];
  s << std::endl;
}

int Argumenty::pokazdl() const{
  return _dlarg;
}

double Argumenty::pokazarg(int ind) const{
  return _argumenty[ind];
}

Argumenty::~Argumenty(){
  delete [] _argumenty;
}
