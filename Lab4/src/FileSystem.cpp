#include "FileSystem.hpp"
#include <iostream>

// Item 4: Folosirea listei de initializare in ordinea declararii membrilor
FileSystem::FileSystem(const std::string& name, std::size_t numDisks)
    : name_(name), numDisks_(numDisks), mounted_(true) {
    std::cout << "[FileSystem] Initializat: " << name_ << " (" << numDisks_ << " discuri)\n";
}

FileSystem::~FileSystem() {
    std::cout << "[FileSystem] Destructor pentru: " << name_ << "\n";
}

std::size_t FileSystem::numDisks() const {
    return numDisks_;
}

void FileSystem::print() const {
    std::cout << "FileSystem '" << name_ << "' | discuri: " << numDisks_
              << " | montat: " << (mounted_ ? "da" : "nu") << "\n";
}

// Obiectul static local este creat garantat la primul apel al functiei
FileSystem& tfs() {
    static FileSystem fs("RootFS", 2);
    return fs;
}

// Directory foloseste tfs() in siguranta, fara riscul de a citi un static neinitializat
Directory::Directory(const std::string& path)
    : path_(path), disksAvailable_(tfs().numDisks()) {
    std::cout << "[Directory] Creat '" << path_ << "' pe sistemul cu " << disksAvailable_ << " discuri\n";
}

void Directory::print() const {
    std::cout << "Directory '" << path_ << "' (discuri disponibile: " << disksAvailable_ << ")\n";
}

