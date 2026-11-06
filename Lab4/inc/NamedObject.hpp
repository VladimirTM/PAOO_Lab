#pragma once

#include <string>

// Item 5: Clasa simpla pentru care compilatorul genereaza automat:
// default constructor, copy constructor, copy assignment (operator=) si destructor
class EmptyRecord {
public:
    int id = 0; // initializare membru built-in
};

// Item 4 & Item 5: Clasa cu membru referinta si membru const
class NamedObject {
private:
    std::string& nameValue_; // referinta: trebuie initializata in lista
    const int objectValue_;  // const: trebuie initializat in lista

public:
    NamedObject(std::string& name, int value);

    // Nu declaram copy constructor -> compilatorul il genereaza automat
    // Nu declaram operator= -> compilatorul il sterge implicit (din cauza referintei si const)

    void setName(const std::string& newName);
    void print() const;
};

