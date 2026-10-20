#include <iostream>
#include <utility>
#include "Thermometer.hpp"

int main() {
    std::cout << "--- 1. Constructor si initializare membri ---\n";
    Thermometer t1(21.5, "Sufragerie");
    t1.print();

    std::cout << "\n--- 2. Copy constructor (Deep Copy) ---\n";
    Thermometer t2 = t1;
    t2.setTemperature(26.0); // modificam doar copia

    std::cout << "Original: ";
    t1.print();
    std::cout << "Copie:    ";
    t2.print();

    std::cout << "\n--- 3. Move constructor ---\n";
    Thermometer t3 = std::move(t1);

    std::cout << "Sursa dupa move: ";
    t1.print();
    std::cout << "Destinatie:      ";
    t3.print();

    std::cout << "\n--- 4. Apel destructori la iesirea din scope ---\n";
    return 0;
}
