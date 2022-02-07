#pragma once
#include <iostream>

class MyString{
public:
friend std::ostream& operator<<(std::ostream& o , const MyString& ms);
  MyString()=default;
  MyString(const char *name) : _tab(name), _size(strlen(name)){};
  MyString& operator +=(const char*napis);
  void operator +=(MyString&& inny) ;
  int size()const {return _size;};
  int fragments() const;
  const MyString& fragment(int i) const;
  void print(std::ostream& o) const{ if(_tab!=nullptr)o<<_tab;};
  MyString(MyString&&ms);
  MyString& operator=(MyString&& ms);
  std::string str() const;
private:
  const char* _tab=nullptr;
  MyString* _next=nullptr;
  int _size=0;
};

std::ostream& operator<<(std::ostream& o , const MyString& ms);