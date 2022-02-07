#pragma once
#include <iostream>

class File{
public:
  File(const std::string& nazwa) : _nazwa(nazwa){}
  virtual void print(int iloscspacji) const;
  virtual void add(File* inny){};
  std::string weznazwe() const{return _nazwa;}
  virtual ~File()=default;
private:
  std::string _nazwa="";
};