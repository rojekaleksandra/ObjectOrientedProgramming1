#include "SekwencjaAlgorytmow.h"

void SekwencjaAlgorytmow::add(std::function<Argumenty(const Argumenty&)> arg){
 _vec.push_back(arg);
}

Argumenty SekwencjaAlgorytmow::procesuj(const Argumenty& arg) const{
  Argumenty x(arg);
  for(auto i: _vec) x=i(x);
  return x;
  }