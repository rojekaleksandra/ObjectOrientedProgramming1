#pragma once
#include <iostream>
#include <algorithm>
#include <memory>
#include <list>

class Dir{
public:
  Dir(const std::string& nazwa) : _nazwa(nazwa){}
  void operator +=(std::shared_ptr<Dir> inny);
  void print(int iloscspacji) const;
  std::shared_ptr<Dir> findDir(const std::string& nazwa) const;
  void add(std::shared_ptr<Dir> inny);
  void rem(const std::string& nazwa);
  std::string weznazwe() const{return _nazwa;}
  ~Dir();

private:
  std::list<std::shared_ptr<Dir>> _katalogi={};
  int _ilosc=0;
  std::string _nazwa="";
};

std::ostream& operator <<(std::ostream& o, const Dir& d);