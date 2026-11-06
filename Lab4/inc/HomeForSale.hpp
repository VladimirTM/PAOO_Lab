#pragma once

#include <string>

// Item 6 (varianta C++98 din carte): Clasa de baza care blocheaza copierea
class Uncopyable {
protected:
    Uncopyable() = default;
    ~Uncopyable() = default;

private:
    // Declarate private si nedefinite pentru a preveni copierea
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
};

class UniqueProperty : private Uncopyable {
private:
    std::string cadastralId_;

public:
    explicit UniqueProperty(const std::string& cadastralId);
    void print() const;
};

// Item 6 (varianta moderna C++11): Interzicerea explicita cu = delete
class HomeForSale {
private:
    std::string address_;
    double price_;

public:
    HomeForSale(const std::string& address, double price);
    ~HomeForSale();

    // Interzicem explicit functiile de copiere generate de compilator
    HomeForSale(const HomeForSale&) = delete;
    HomeForSale& operator=(const HomeForSale&) = delete;

    void print() const;
};

