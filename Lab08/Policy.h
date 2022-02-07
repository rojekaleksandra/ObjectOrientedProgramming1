#pragma once
#include <iostream>

class Policy{};

struct CachePolicy : public Policy {
  public:
    virtual void cacheValueForArgument( double arg, double val )  = 0; // zapamietuje wartosc obliczenia dla argumentu
    virtual bool hasCacheFor( double arg ) const = 0;  // zwraca true jesli w cachu znajduje sie wartosc dla argumentu
    virtual double getCached(double arg) const = 0; // zapamietana wartosc dla argumentu
    virtual std::string policyName() const =0;
};

struct VerbosityPolicy : public Policy {
  public:
    virtual void printArgAndResult( double arg, double val) const = 0; // wypisuje na stdout argument i wynik dzialania na tym argumencie
    virtual std::string policyName() const =0; //zwraca nazwe niewirtualnych polityk
};

class NoCache : virtual public CachePolicy{
  public:
    //pusta metoda, poniewaz polityka NoCache
    void cacheValueForArgument( double arg, double val ) {}
    //zwraca false poniewaz nie zapamietuje argumentu
    bool hasCacheFor( double arg ) const{return false;}
    //pusta metoda, poniewaz polityka NoCache
    double getCached(double arg) const{return 0;}
    //zwraca nazwe klasy
    std::string policyName() const {return "NoCache";}
};

class OneCallCache : virtual public CachePolicy{
    public:
    //zapamietuje argument i obliczona wartosc
      void cacheValueForArgument( double arg, double val){_arg=arg; _val=val;}
      // sprawdza czy podany argument jest rowny zapamietanemu
      bool hasCacheFor( double arg ) const{
        if (_arg==arg) return true;
        return false;
      }
      //zwraca zapamietana wartosc dla argumentu
      double getCached(double arg) const{return _arg;}
      //zwraca nazwe klasy
      std::string policyName() const {return "OneCallCache";}
    private:
      double _arg=0;
      double _val=0;

};

class Verbose : virtual public VerbosityPolicy{
  public:
  //wypisuje na ekran argument i obliczona wartosc
    void printArgAndResult( double arg, double val) const{ std::cout << "f(" << arg << ") = " << val << std::endl;}
    //zwraca nazwe klasy
    std::string policyName() const {return "Verbose";}
};


class Silent : virtual public VerbosityPolicy{
  public:
    //nic nie robi, poniewaz polityka-silent
    void printArgAndResult( double arg, double val) const{}
    //zwraca nazwe klasy
    std::string policyName() const {return "Silent";}
};

