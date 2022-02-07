#pragma once
#include "File.h"
#include <iostream>
// #include <algorithm>
// #include <memory>
#include <list>

class Dir : public File{
public:
  Dir(const std::string& nazwa) : File(nazwa){}
  void operator +=(std::shared_ptr<File> inny);
  void print(int iloscspacji) const;
  std::shared_ptr<Dir> findDir(const std::string& nazwa) const;
  void add(std::shared_ptr<File> inny);
  void rem(const std::string& nazwa);
  std::shared_ptr<FSElement> get(const std::string& nazwa) const;
  ~Dir();

private:
  std::list<std::shared_ptr<File>> _katalogi={};
  int _ilosc=0;
};

std::ostream& operator <<(std::ostream& o, const File& d);