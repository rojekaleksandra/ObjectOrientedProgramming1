#include "Dir.h"

void Dir::operator +=(File* inny){
  _pliki[_iloscplikow] = inny;
  _iloscplikow++;
}

void Dir::print(int iloscspacji) const{
  for (int i=0;i<iloscspacji;i++) std::cout << " ";
  std::cout <<File::weznazwe() << " (DIR)"<<std::endl;
  for(int i=0;i<_iloscplikow;i++) _pliki[i]->print(iloscspacji+2);

}

Dir * Dir::findDir(const std::string& nazwa) const{
  if(_iloscplikow==0) return nullptr;
  for(int i=0;i<_iloscplikow;i++){
    if(_pliki[i]->weznazwe() ==nazwa){
      return dynamic_cast<Dir*> (_pliki[i]);
    }
    else{return dynamic_cast<Dir*> (_pliki[i])->findDir(nazwa);}
  }
  return nullptr;
 }

 void Dir::add(Dir* inny){
   *this+=inny;
 }

 File * Dir::get(const std::string& nazwa) const{
   return dynamic_cast<Dir*> (_pliki[0]);
 }

 Dir::~Dir(){
   std::cout << "Deleting Dir: " << File::weznazwe() <<std::endl;
   for(int i=0;i<_iloscplikow;i++){
     std::cout << "About to delete " << _pliki[i]->weznazwe() <<std::endl;
     delete _pliki[i];
   }
 };

std::ostream& operator <<(std::ostream& o, const File& f){
  f.print(0);
  return o;
}

