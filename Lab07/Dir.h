#pragma once
#include "File.h"
#include <iostream>

class Dir final : public File{
public:
  Dir(const std::string& napis) : File(napis){}
  void operator +=(File* inny);
  void print(int iloscspacji) const;
  Dir * findDir(const std::string& nazwa) const;
  void add(Dir* inny);
  File * get(const std::string& nazwa) const;
  ~Dir();
private:
  File * _pliki[10];
  int _iloscplikow=0;
};

std::ostream& operator <<(std::ostream& o, const File& f);