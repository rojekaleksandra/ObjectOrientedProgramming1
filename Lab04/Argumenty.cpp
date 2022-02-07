#include "Argumenty.h"

Argumenty Argumenty::pojedynczy(double x){ 
return Argumenty(1)(0,x);
}

Argumenty::Argumenty(int x){
  _argumenty = new double[x];
  _dlarg=x;
}

Argumenty& Argumenty::operator()(int ind, double wart){
  _argumenty[ind] = wart;
  return *this;
}

Argumenty::Argumenty(const Argumenty& arg){
  _dlarg=arg._dlarg;
  _argumenty = new double[_dlarg];
  for (int i=0;i<_dlarg;i++) _argumenty[i]=arg._argumenty[i];
}

Argumenty& Argumenty::operator=(const Argumenty& arg){
if(_argumenty==arg._argumenty) return *this;
delete [] _argumenty;
_argumenty=new double[arg._dlarg];
_dlarg=arg._dlarg;
for (int i=0;i<_dlarg;i++) _argumenty[i]=arg._argumenty[i];
return *this;
}

void Argumenty::print(std::ostream& s) const{
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

std::ostream& operator<<(std::ostream& o, const Argumenty& arg){
  arg.print();
 return o;
}

 double Argumenty::operator[](int i) const{
   return _argumenty[i];
 }

