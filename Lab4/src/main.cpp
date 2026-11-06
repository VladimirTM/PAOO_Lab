#include <iostream>
#include <string>
#include "FileSystem.hpp"
#include "NamedObject.hpp"
#include "HomeForSale.hpp"

int main() {
    std::cout << "=== ITEM 4: Initializarea obiectelor inainte de utilizare ===\n";
    // 1. Initializarea manuala a tipurilor built-in
    int builtInCounter = 0;
    double initialPrice = 125000.0;
    std::cout << "Built-in initializate manual: counter = " << builtInCounter
              << ", price = " << initialPrice << "\n";

    // 2. Lista de initializare a membrilor si static local (tfs)
    Directory tempDir("/tmp/cache");
    tempDir.print();
    tfs().print();

    std::cout << "\n=== ITEM 5: Functii generate si apelate silentios de C++ ===\n";
    // 1. Clasa simpla cu functii generate de compilator
    EmptyRecord r1;           // default constructor
    r1.id = 42;
    EmptyRecord r2(r1);       // copy constructor generat de compilator
    EmptyRecord r3;
    r3 = r1;                  // copy assignment (operator=) generat de compilator
    std::cout << "EmptyRecord: r1.id = " << r1.id << ", r2.id = " << r2.id << ", r3.id = " << r3.id << "\n";

    // 2. Clasa cu referinta si membru const (NamedObject)
    std::string newDog("Persephone");
    std::string oldDog("Satch");

    NamedObject p(newDog, 2);
    NamedObject s(oldDog, 36);

    // Copy constructor-ul generat de compilator functioneaza (initializeaza un obiect nou)
    NamedObject copyOfP(p);
    copyOfP.print();

    // Modificarea referintei din copie afecteaza acelasi string referit ("Persephone")
    copyOfP.setName("Persephone_Modificat");
    std::cout << "Dupa modificare prin copie, originalul p este:\n";
    p.print();

    // p = s; // EROARE LA COMPILARE: operator= este sters implicit (referinta + membru const)

    std::cout << "\n=== ITEM 6: Interzicerea explicita a copierii ===\n";
    // 1. Varianta C++11 (= delete)
    HomeForSale h1("Str. Memorandului 10", initialPrice);
    HomeForSale h2("Bd. Eroilor 25", 180000.0);
    h1.print();
    h2.print();

    // HomeForSale h3(h1); // EROARE LA COMPILARE: copy constructor este = delete
    // h1 = h2;            // EROARE LA COMPILARE: operator= este = delete

    // 2. Varianta C++98 (mostenire privata din Uncopyable)
    UniqueProperty prop1("CF-100234");
    UniqueProperty prop2("CF-100235");
    prop1.print();

    // UniqueProperty prop3(prop1); // EROARE LA COMPILARE: Uncopyable copy constructor este privat
    // prop1 = prop2;               // EROARE LA COMPILARE: Uncopyable operator= este privat

    std::cout << "\n=== Final main (apel destructori) ===\n";
    return 0;
}

