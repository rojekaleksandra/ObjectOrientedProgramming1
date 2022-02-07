#pragma once
#include <iostream>

class Person{
public:
  Person(std::string name, bool p) : _name(name), _isWoman(p){}
  bool isWoman() const{return _isWoman;}
  static Person kobieta(std::string name);
  static Person mezczyzna(std::string name);
  std::string getname() const{return _name;}
private:
  std::string _name;
  bool _isWoman=false;
};

std::ostream& operator <<(std::ostream& o, const Person& p){
  o<<p.getname() ;
  if(p.isWoman()) o <<" K";
  else{ o <<" M";}
  return o;
}

Person Person::kobieta(std::string name){
  return Person(name, 1);
}

Person Person::mezczyzna(std::string name){
  return Person(name, 0);
}
