#include "HomeForSale.hpp"
#include <iostream>

UniqueProperty::UniqueProperty(const std::string& cadastralId)
    : cadastralId_(cadastralId) {
    std::cout << "[UniqueProperty] Inregistrat CF: " << cadastralId_ << "\n";
}

void UniqueProperty::print() const {
    std::cout << "UniqueProperty (Uncopyable C++98) -> CF: " << cadastralId_ << "\n";
}

HomeForSale::HomeForSale(const std::string& address, double price)
    : address_(address), price_(price) {
    std::cout << "[HomeForSale] Listata proprietatea: " << address_ << " (" << price_ << " EUR)\n";
}

HomeForSale::~HomeForSale() {
    std::cout << "[HomeForSale] Eliminata din catalog: " << address_ << "\n";
}

void HomeForSale::print() const {
    std::cout << "HomeForSale (= delete C++11) -> " << address_ << ", pret: " << price_ << " EUR\n";
}

