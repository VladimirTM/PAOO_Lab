#include "Thermometer.hpp"
#include <iostream>
#include <utility>

// Constructor cu lista de initializare
Thermometer::Thermometer(double temp, const std::string& location)
    : location_(location), temperature_(new double(temp)) {
    std::cout << "[Constructor] " << location_ << " (" << *temperature_ << "C, adresa: " << temperature_ << ")\n";
}

// Destructor
Thermometer::~Thermometer() {
    if (temperature_) {
        std::cout << "[Destructor] Eliberare memorie pentru " << location_ << " (adresa: " << temperature_ << ")\n";
        delete temperature_;
        temperature_ = nullptr;
    } else {
        std::cout << "[Destructor] Obiectul " << location_ << " nu are memorie de eliberat (a fost mutat)\n";
    }
}

// Copy constructor (deep copy)
Thermometer::Thermometer(const Thermometer& other)
    : location_(other.location_ + "_copie"),
      temperature_(other.temperature_ ? new double(*other.temperature_) : nullptr) {
    std::cout << "[Copy constructor] Copiere din " << other.location_ << " in " << location_ << "\n";
}

// Move constructor
Thermometer::Thermometer(Thermometer&& other) noexcept
    : location_(std::move(other.location_)), temperature_(other.temperature_) {
    other.temperature_ = nullptr; // eliberam ownership-ul sursei
    std::cout << "[Move constructor] Mutare in " << location_ << "\n";
}

double Thermometer::getTemperature() const {
    return temperature_ ? *temperature_ : 0.0;
}

void Thermometer::setTemperature(double temp) {
    if (temperature_) {
        *temperature_ = temp;
    } else {
        temperature_ = new double(temp);
    }
}

const std::string& Thermometer::getLocation() const {
    return location_;
}

void Thermometer::print() const {
    std::cout << location_ << ": ";
    if (temperature_) {
        std::cout << *temperature_ << "C (adresa: " << temperature_ << ")\n";
    } else {
        std::cout << "null (fara date)\n";
    }
}
