#pragma once
#include <iostream>

class Argumenty{
public:
  friend std::ostream& operator<<(std::ostream& o, const Argumenty& arg);
  Argumenty() = default;
  Argumenty(int x);
  Argumenty(const Argumenty& arg);
  Argumenty& operator=(const Argumenty& arg);
  Argumenty& operator()(int ind, double wart);
  void print(std::ostream& s = std::cout) const;
  int pokazdl() const;
  double pokazarg(int ind) const;
  double operator[](int i) const;
  static Argumenty pojedynczy(double x);
  ~Argumenty();

private:
  double *_argumenty;
  int _dlarg =0;
};

std::ostream& operator<<(std::ostream& o, const Argumenty& arg);
