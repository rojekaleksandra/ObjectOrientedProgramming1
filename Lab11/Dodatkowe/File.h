#pragma once
#include "FSElement.h"
#include <iostream>
#include <algorithm>
#include <memory>

class File : public FSElement{
public:
  File(const std::string& nazwa) : FSElement(nazwa){}
  virtual void print(int iloscspacji) const;
  virtual ~File()=default;
};