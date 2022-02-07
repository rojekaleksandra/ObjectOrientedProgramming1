#pragma once
#include <vector>
#include <functional>
#include "Argumenty.h"

class SekwencjaAlgorytmow{
  public:
    void add(std::function<Argumenty(const Argumenty&)> arg);
    Argumenty procesuj(const Argumenty& arg) const;
  private:
  std::vector <std::function<Argumenty(const Argumenty &)>> _vec ={};
};
