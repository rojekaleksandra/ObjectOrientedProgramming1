#pragma once
#include <vector>
#include <iostream>

//Klasa, monitorująca dane.
class Obserwator{
public:
  //Funkcja wirtualna, analizująca dane.
  virtual void wykonaj(int x)=0;

  //Wirtualny destruktor klasy.
  virtual ~Obserwator()=default;
};

//Klasa sumująca podane dane.
class ObserwatorLicznik : public Obserwator{
public:

  //Nadpisanie funkcji z klasy bazowej. Dodaje podaną daną do sumy.
  void wykonaj(int x) override {_sum+=x;}

  //Funkcja zwracająca wyliczoną sumę danych.
  int suma() const{return _sum;};

private:
  int _sum=0;
};

//Klasa wypisująca dane.
class ObserwatorWypisywacz : public Obserwator{
public:
  //Nadpisanie funkcji z klasy bazowej. Wypisuje podaną daną na ekran.
  void wykonaj(int x) override {std::cout<<x<<" ";}
};