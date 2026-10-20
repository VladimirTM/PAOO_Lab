#pragma once

#include <string>

class Thermometer {
private:
    std::string location_;
    double* temperature_;

public:
    Thermometer(double temp, const std::string& location = "Camera");
    ~Thermometer();
    Thermometer(const Thermometer& other);
    Thermometer(Thermometer&& other) noexcept;

    double getTemperature() const;
    void setTemperature(double temp);
    const std::string& getLocation() const;

    void print() const;
};
