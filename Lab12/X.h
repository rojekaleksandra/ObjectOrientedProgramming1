#pragma once
#include <iostream>

class X{
public:
  X()=default;
  X(std::string napis) : _napis(napis){}
  //Wirtualny głośny destruktor klasy.
  virtual ~X(){std::cout << "deleting X " << _napis<< std::endl;}
  //Zwraca wartość prywatnego pola _napis.
  virtual std::string napis() const{return _napis;}
private:
  std::string _napis="";
};

//Przeciążenie operatora "<<" dla klasy X.
std::ostream& operator <<(std::ostream& o, const X& x){
  o << x.napis();
  return o;
}

class Y : public X{
public:
  Y(std::string napis) : X(napis){}
  //Głośny destruktor klasy.
  ~Y(){std::cout << "deleting Y " << napis()<< std::endl;}
};