#include "PArr.h"

PArr::PArr(int size){
  _size=size;
  _w = new Wrapper*[size];
}

PArr::PArr(PArr&& p){
  _size=p._size;
  _w=p._w;
  p._size=0;
  p._w=nullptr;
}


Wrapper *& PArr::operator[](int i) const{
  return _w[i];
}

std::ostream& operator<<(std::ostream &o, const PArr& w){
  for(int i=0;i<w._size;i++){
      w[i]->print();
      o<< " ";
  }
  return o;
}

PArr& PArr::operator=(const PArr& w){
  if(&w==this) return *this;
  for(int i=0;i<_size;i++) delete _w[i];
  delete []_w;
  _size=w._size;
  _w=new Wrapper*[_size];
  for(int i=0;i<_size;i++) _w[i]=w[i]->copywrapper();
  return *this;
}


PArr::~PArr(){
  for(int i=0;i<_size;i++) delete _w[i];
  delete [] _w;
}