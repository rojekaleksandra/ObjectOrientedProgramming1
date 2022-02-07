#pragma once
#include "Policy.h"

//generuje klase z roznymi wariantami polityk
#define MyCalculation(calc, policy1, policy2) \
  class calc : public policy1, public policy2{ \
  public: \
    void eval(int arg){ \
      if(hasCacheFor( arg ) ) return; \
      double result = sqrt( pow(arg - 7, 2) ); \
      cacheValueForArgument( arg, result ); \
      printArgAndResult(arg, result); \
    } \
  }; 
