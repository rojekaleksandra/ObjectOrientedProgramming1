#pragma once
#include <iostream>

class Argumenty{
public:
Argumenty() = default;
  Argumenty(int x);
  Argumenty& operator()(int ind, double wart);
  void print(std::string napis, std::ostream& s = std::cout) const;
  int pokazdl() const;
  double pokazarg(int ind) const;
  ~Argumenty();

private:
  double *_argumenty;
  int _dlarg =0;
};
