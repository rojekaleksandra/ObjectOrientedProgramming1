#pragma once
#include "Argumenty.h"
#include <cmath>

Argumenty minimum (const Argumenty &arg){
  double min=arg[0];
  for(int i=0;i <arg.pokazdl();i++){
    if (arg.pokazarg(i)<min) min=arg.pokazarg(i);
  } 
  return Argumenty::pojedynczy(min);
}

Argumenty sum (const Argumenty &arg){
  double sum=arg.pokazarg(0);
  for(int i=1;i <arg.pokazdl();i++){
    sum+=arg.pokazarg(i);
  } 
  return Argumenty::pojedynczy(sum);
}

Argumenty sq (const Argumenty &arg){
  double x;
 for(int i=0;i <arg.pokazdl();i++){
    x= sqrt(arg[i]);
  } 
  return Argumenty::pojedynczy(x);
}