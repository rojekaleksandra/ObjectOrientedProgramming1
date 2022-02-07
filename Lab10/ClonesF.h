#pragma once
#include <vector>

class Cont{
public:
  //Wirtualny destruktor klasy Cont.
  virtual ~Cont()=default;
};


template <typename T>
class Contener : public Cont{
public:
  //Konstruktor klasy Contener.
  Contener(const T& el) : _element(el){}

  //Zwraca przechowywany element.
  const T& getelemenet() const{return _element;}

private:
  T _element={};
};


class ClonesF{
public:

  //Dodaje nowy obiekt na koniec wektora.
  template <typename T>
  void add(const T& el){
    auto nowy = new Contener<T>(el);
    _vec.push_back(nowy);
  }

  //Zwraca kopie z oryginału.
  template <typename T>
  const T& clone() const{
    for(auto i : _vec){
      auto el = dynamic_cast<Contener<T>*>(i);
      if(el) return el->getelemenet();
    }
  }

  //Zamienia obiekt konkretnego typu w wektorze na nowy.
  template <typename T>
  void replace(const T& el){
    auto nowy = new Contener<T>(el);
    for(unsigned int i=0; i<_vec.size();i++){
      auto elem = dynamic_cast<Contener<T>*>(_vec.at(i));
      if(elem) delete elem;
      _vec.at(i)=nowy;
    }
  }

  //Destruktor. Usuwa obiekty zawarte w wektorze.
  ~ClonesF(){
    for(auto i : _vec) delete i;
  }

private:
  std::vector<Cont*> _vec={};
};