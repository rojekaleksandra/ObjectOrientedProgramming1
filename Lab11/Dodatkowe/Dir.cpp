#include "Dir.h"

void Dir::operator +=(std::shared_ptr<File> inny){
  _katalogi.push_back(inny);
  _ilosc++;
}

void Dir::print(int iloscspacji) const{
  for (int i=0;i<iloscspacji;i++) std::cout << " ";
  std::cout <<"\\ " << name() <<std::endl;
  for(auto i : _katalogi) i->print(iloscspacji+2);

}

std::shared_ptr<Dir> Dir::findDir(const std::string& nazwa) const{
  std::shared_ptr<FSElement> el = get(nazwa);
  std::shared_ptr<Dir> dir= std::dynamic_pointer_cast<Dir>(el);
  if(dir) return dir;
  return 0;
 }

  std::shared_ptr<FSElement> Dir::get(const std::string& nazwa) const{
    if(_ilosc==0) return nullptr;
    for(auto i : _katalogi){
      if(i->name() ==nazwa) return i;
      std::shared_ptr<Dir> dir= std::dynamic_pointer_cast<Dir>(i);
      if(dir){
        std::shared_ptr<FSElement> el = dir->get(nazwa);
        if(el) return el;
      }
    }
    return 0;
  }

 void Dir::add(std::shared_ptr<File> inny){
   *this+=inny;
 }

 void Dir::rem(const std::string& nazwa){
    auto el = findDir(nazwa);
    for (auto it = _katalogi.begin(); it != _katalogi.end(); ) {
        if ((*it)->name()==nazwa) {
            it = _katalogi.erase(it);
            return;
        } else {
            ++it;
        }
    }
 }

  Dir::~Dir(){
  //  std::cout << "Deleting Dir: " << name() <<std::endl;
  }

std::ostream& operator <<(std::ostream& o, const File& d){
  d.print(0);
  return o;
}