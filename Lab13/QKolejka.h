#pragma once
#include <list>
#include <functional>
#include <iostream>
#include <initializer_list>

template <typename T>
class QKolejka{
public:
  QKolejka(std::function<int(const T&)> fun) : _fun(fun){}

  void dodaj(const T& per){
    if (_list.empty()==0){
      for(auto it = _list.begin(); it!=_list.end(); ++it){
        if(_fun(per) < _fun(*it)){
          _list.insert(it, per);
          return;
        }
      }
      _list.push_back(per);
      return;
    }
    else{_list.push_back(per);}
  }

  void dodaj(std::initializer_list<T> l){
    for(auto el : l) dodaj(el);
  }

  typename std::list<T>::const_iterator begin() const{
    return _list.cbegin();
  }

  
  typename std::list<T>::const_iterator end() const{
    return _list.cend();
  }

  using const_reverse_iterator = typename std::list<T>::const_reverse_iterator;


  const_reverse_iterator rbegin() const{
      return _list.crbegin();
  }


  const_reverse_iterator rend() const{
    return _list.crend();
  }
  
private:
  std::list<T> _list={};
  std::function<int(const T&)> _fun;
};

