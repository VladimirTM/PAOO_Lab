#include "NamedObject.hpp"
#include <iostream>

// Membrii referinta si const pot fi doar initializati (nu atribuiti in corp)
NamedObject::NamedObject(std::string& name, int value)
    : nameValue_(name), objectValue_(value) {
    std::cout << "[NamedObject] Creat: '" << nameValue_ << "' (valoare const: " << objectValue_ << ")\n";
}

void NamedObject::setName(const std::string& newName) {
    nameValue_ = newName; // modifica string-ul la care face referire
}

void NamedObject::print() const {
    std::cout << "NamedObject { nume: '" << nameValue_
              << "' (adresa string: " << &nameValue_
              << "), valoare: " << objectValue_ << " }\n";
}

