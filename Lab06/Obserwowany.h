#pragma once
#include <vector>
#include "Obserwator.h"

//Klasa, w której zmieniają się dane.
class Obserwowany{
public:
  //Funkcja przesylajaca dane do Obserwatorów.
  void noweDaneNadeszly(int x){for(auto i : v) i->wykonaj(x);};
  //Funkcja dodająca wskaźnik na nowego Obserwatora.
  void dodajObserwatora( Obserwator* o ){v.push_back(o);}

private:
  std::vector <Obserwator*> v;
};