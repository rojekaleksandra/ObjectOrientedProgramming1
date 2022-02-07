/*
 * Celem zadania jest napisanie klasy opisujacej katalogi.
 * Mozna wykozystac fragmenty poprzedniego zadania. 
 * 
 * Implementacja sama zarzadza pamiecia poprzez uzycie shared_ptr
 * W implementacji nalezy uzyc kontenera std::list
 * 
 * Interfejs moglby oczywiscie nie wymagac uzycia shared_ptr. Dla uproszczenia, jednak zadanie jest tak sformulowane zeby bylo to oczywiste.
 *
 * UWAGA: w domu nalezy sobie zadanie rozbudowac tak ze by mozna bylo dodac tez klase File, SoftLink/Lacze.
 */
#include <memory>
#include "Dir.h"
#include "File.h"


int main() {
  auto top = std::shared_ptr<Dir>(new Dir("."));  
  auto home = std::make_shared<Dir>("home"); // to jest to samo
  top->add(home); // dodajemy do kat TOP podkatalog  
  home->add(std::make_shared<Dir>("ewa"));
  home->add(std::make_shared<Dir>("adam"));
  home->add(std::make_shared<Dir>("kacper")); 
  home->add(std::make_shared<File>("Plik1"));
  //  home->add(5); // to ma sie nie kompilowac
  //  home->add( std::make_shared<int>(5)); // to tez ma sie nie kompilowac, a zabezpieczamy poprzez sprawdzenie czy "int" dziedziczy po "FSElement"
  std::cout << *top;

  auto Plik1 = top->get("Plik1");
  std::cout << (Plik1 ? Plik1->name() : "Brak Plik1") << std::endl;
  std::shared_ptr<FSElement> Plik2 = top->get("Plik2");
  std::cout << (Plik2 ? Plik2->name() : "Brak Plik2") << std::endl;


  top->findDir("ewa")->add( std::make_shared<Dir>("desk") );
  top->findDir("desk")->add( std::make_shared<File>("Plik3"));
  top->findDir("ewa")->add( std::make_shared<Dir>("work") );
  top->findDir("ewa")->add( std::make_shared<File>("Plik2") );

  std::cout << *top;
  std::cout << "--------------" << std::endl;  

  home->rem("kacper");
  top->findDir("adam")->add( top->findDir("desk") ); // tu jest trick, gdy dobrze uzyjemy shared_ptr to nie musimy sie martwic pamiecia  
  std::cout << *top;
  std::cout << "--------------" << std::endl;
   

   
}
/* wynik 
\ .
  \ home
    \ ewa
    \ adam
    \ kacper
    . Plik1
Plik1
Brak Plik2
\ .
  \ home
    \ ewa
      \ desk
        . Plik3
      \ work
      . Plik2
    \ adam
    \ kacper
    . Plik1
--------------
\ .
  \ home
    \ ewa
      \ desk
        . Plik3
      \ work
      . Plik2
    \ adam
      \ desk
        . Plik3
    . Plik1
--------------

 */
