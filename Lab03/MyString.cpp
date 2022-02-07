#include "MyString.h"
#include <string>

MyString& MyString::operator +=(const char*name){
  MyString *nowy = new MyString(name);
  int x = fragments();
  MyString *temp = this;
  for(int i=0;i<x-1;i++) temp=temp->_next;
  temp->_next=nowy;
  _size+=strlen(name);
  return *this;
}

void MyString::operator +=(MyString&& inny) { 
    this->_next=&inny;
    this->_size=inny._size;
}

int MyString::fragments() const{
  return 1 + (_next ? _next->fragments() : 0) ;
}

const MyString& MyString::fragment(int i) const{
  const MyString *temp =  this;
  for (int j=0;j<i;j++) temp=temp->_next;
  return *temp;
}

std::ostream& operator<<(std::ostream& o , const MyString& ms){
  ms.print(o);
  MyString *temp = ms._next; 
  for(int i=0;i<ms.fragments()-1;i++){
    temp->print(o);
    std::cout <<" ";
    temp=temp->_next;
  }
  return o;
}

MyString::MyString(MyString &&ms){
  _tab = ms._tab;
  _next=ms._next;
  _size=ms._size;
  ms._size=0;
  ms._tab=nullptr;
  ms._next=nullptr;
}

MyString& MyString::operator=(MyString&& ms){
    _tab = ms._tab;
  _next=ms._next;
  _size=ms._size;
  ms._size=0;
  ms._tab=nullptr;
  ms._next=nullptr;
  return *this;
}

std::string MyString::str() const{
  return _tab;
}
