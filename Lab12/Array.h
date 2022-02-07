#pragma once
#include <iostream>
#include "X.h"

template <int rozm, typename T>
class Array{
public:
  //Domyslny kontruktor klasy.
  Array(){}
  //Domyslny destruktor klasy.
  ~Array(){}
  //Nadpisanie operatora nawiasów kwadratowych.
  T& operator [](int x);

private:
  T _tab[rozm];
};

//Specjalny konstruktor klasy Array dla rozmiaru 7, o typie int.
template <>
Array<7, int>::Array(){
  for(int i=0;i<7;i++) _tab[i]=0;
}

//Specjalny konstruktor klasy Array dla rozmiaru 5, o typie X*.
template <>
Array<5, X*>::Array(){
  for(int i=0;i<7;i++) _tab[i]=nullptr;
}  

//Nadpisanie operatora nawiasów kwadratowych. Zwraca adres konkretnego pola w tablicy _tab.
template<int rozm, typename T>
T& Array<rozm,T>::operator [](int x) {return _tab[x];}

//Specjalny destruktor klasy Array dla rozmiaru 5, o typie X*.
template <>
Array<5, X*>::~Array(){
  for(int i=0;i<5;i++) delete _tab[i];
}

//Przeciążenie operatora "<<" dla klasy Array o rozmiarze rozm i typie T.
template <int rozm, typename T>
std::ostream& operator <<(std::ostream& o, Array<rozm,T>& tab ){
  for(int i=0;i<rozm;i++) std::cout << tab[i] <<" ";
  return o;
}

//Przeciążenie operatora "<<" dla klasy Array o rozmiarze rozm i typie T*.
template <int rozm, typename T>
std::ostream& operator <<(std::ostream& o, Array<rozm,T*>& tab ){
  for(int i=0;i<rozm;i++){ 
  if(tab[i]) o << *tab[i] <<" ";
  }
  return o;
}