//
// Created by zaha on 5/5/22.
//

#include "banknote.h"

#define EPS std::numeric_limits<double>::epsilon()

banknote::banknote() {
    this->id = 0;
    this->value = 0;
    this->quantity = 0;
}

banknote::banknote(int id, double value, int quantity) {
    this->id = id;
    this->value = value;
    this->quantity = quantity;
}

banknote::banknote(const banknote &rhs) {
    this->id = rhs.id;
    this->value = rhs.value;
    this->quantity = rhs.quantity;
}

banknote::~banknote() = default;

int banknote::get_id() const {
    return id;
}

void banknote::set_id(int new_id) {
    this->id = new_id;
}

double banknote::get_value() const {
    return value;
}

void banknote::set_value(double new_value) {
    this->value = new_value;
}

int banknote::get_quantity() const {
    return quantity;
}

void banknote::set_quantity(int new_quantity) {
    this->quantity = new_quantity;
}

bool banknote::operator==(const banknote &other) const {
    return this->id == other.id;
}

bool banknote::operator!=(const banknote &other) const {
    return !(*this == other);
}

bool banknote::operator<(const banknote &rhs) const {
    if (std::abs(rhs.value - this->value) < EPS) {
        return false;
    }
    return this->value < rhs.value;
}

bool banknote::operator>(const banknote &rhs) const {
    return rhs < *this;
}

bool banknote::operator<=(const banknote &rhs) const {
    return !(rhs < *this);
}

bool banknote::operator>=(const banknote &rhs) const {
    return !(*this < rhs);
}

banknote &banknote::operator=(const banknote &rhs) {
    if (this != &rhs) {
        this->id = rhs.id;
        this->value = rhs.value;
        this->quantity = rhs.quantity;
    }

    return *this;
}

std::ostream &operator<<(std::ostream &os, const banknote &banknote) {
    os << "ID: " << banknote.id
       << " Value: " << banknote.value
       << " Quantity: " << banknote.quantity
       << std::endl;

    return os;
}

std::istream &operator>>(std::istream &is, banknote &banknote) {
    std::string temp; // We need this to get rid of the descriptions added by ostream
    is >> temp >> banknote.id
       >> temp >> banknote.value
       >> temp >> banknote.quantity;

    return is;
}
