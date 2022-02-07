#pragma once
#include <iostream>

class FSElement{
public:
  FSElement(const std::string& nazwa) : _nazwa(nazwa){}
  std::string name() const{return _nazwa;}
  virtual void print(int iloscspacji) const=0;
  virtual ~FSElement()=default;
private:
  std::string _nazwa="";
};