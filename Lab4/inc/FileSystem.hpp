#pragma once

#include <cstddef>
#include <string>

// Item 4: Initializarea membrilor si obiecte statice locale
class FileSystem {
private:
    // Membrii sunt initializati in ordinea declararii in clasa
    std::string name_;
    std::size_t numDisks_;
    bool mounted_;

public:
    FileSystem(const std::string& name, std::size_t numDisks);
    ~FileSystem();

    std::size_t numDisks() const;
    void print() const;
};

// Inlocuirea obiectului static global cu o functie ce returneaza un static local
FileSystem& tfs();

class Directory {
private:
    std::string path_;
    std::size_t disksAvailable_;

public:
    explicit Directory(const std::string& path);
    void print() const;
};

