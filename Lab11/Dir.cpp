#include "Dir.h"

void Dir::operator +=(std::shared_ptr<Dir> inny){
  _katalogi.push_back(inny);
  _ilosc++;
}

void Dir::print(int iloscspacji) const{
  for (int i=0;i<iloscspacji;i++) std::cout << " ";
  std::cout <<_nazwa <<std::endl;
  for(auto i : _katalogi) i->print(iloscspacji+2);

}

std::shared_ptr<Dir> Dir::findDir(const std::string& nazwa) const{
  if(_ilosc==0) return nullptr;
  for(auto i : _katalogi){
    if(i->_nazwa ==nazwa){
      return i;
    }
    else {
      if(i->findDir(nazwa)) return i->findDir(nazwa);
    }
  }
  return nullptr;
 }

 void Dir::add(std::shared_ptr<Dir> inny){
   *this+=inny;
 }

 void Dir::rem(const std::string& nazwa){
    auto el = findDir(nazwa);
    for (auto it = _katalogi.begin(); it != _katalogi.end(); ) {
        if ((*it)->weznazwe()==nazwa) {
            it = _katalogi.erase(it);
            return;
        } else {
            ++it;
        }
    }
 }

  Dir::~Dir(){
   std::cout << "Deleting Dir: " << _nazwa <<std::endl;
  }

std::ostream& operator <<(std::ostream& o, const Dir& d){
  d.print(0);
  return o;
}