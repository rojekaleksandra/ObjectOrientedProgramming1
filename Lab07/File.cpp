#include "File.h"

void File::print(int iloscspacji) const{
  for (int i=0;i<iloscspacji;i++) std::cout << " ";
  std::cout <<_nazwa << " (FILE)"<< std::endl;
}