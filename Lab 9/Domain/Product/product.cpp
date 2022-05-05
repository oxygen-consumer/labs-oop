//
// Created by zaha on 4/19/22.
//

#include "product.h"

product::product() {
    this->id = 0;
    this->code = 0;
    this->name = "";
    this->price = 0;
    this->quantity = 0;
}

product::product(int id, int code, std::string name, double price,
                 int quantity) {
    this->id = id;
    this->code = code;
    this->name = std::move(name);
    this->price = price;
    this->quantity = quantity;
}

product::product(const product &rhs) {
    this->id = rhs.id;
    this->code = rhs.code;
    this->name = rhs.name;
    this->price = rhs.price;
    this->quantity = rhs.quantity;
}

product::~product() = default;

int product::get_id() const {
    return this->id;
}

void product::set_id(int new_id) {
    this->id = new_id;
}

int product::get_code() const {
    return this->code;
}

void product::set_code(int new_code) {
    this->code = new_code;
}

std::string product::get_name() const {
    return this->name;
}

void product::set_name(std::string new_name) {
    this->name = std::move(new_name);
}

double product::get_price() const {
    return this->price;
}

void product::set_price(double new_price) {
    this->price = new_price;
}

int product::get_quantity() const {
    return this->quantity;
}

void product::set_quantity(int new_quantity) {
    this->quantity = new_quantity;
}

bool product::operator==(const product &rhs) const {
    return this->id == rhs.id;
}

bool product::operator!=(const product &rhs) const {
    return !(*this == rhs);
}

product &product::operator=(const product &rhs) {
    if (this != &rhs) {
        this->id = rhs.id;
        this->code = rhs.code;
        this->name = rhs.name;
        this->price = rhs.price;
        this->quantity = rhs.quantity;
    }

    return *this;
}

std::ostream &operator<<(std::ostream &os, const product &product) {
    os << "ID: " << product.id
       << " Code: " << product.code
       << " Name: " << product.name
       << " Price: " << product.price
       << " Quantity: " << product.quantity
       << std::endl;

    return os;
}

std::istream &operator>>(std::istream &is, product &product) {
    std::string temp; // We need this to get rid of the descriptions added by ostream
    is >> temp >> product.id
       >> temp >> product.code
       >> temp >> product.name
       >> temp >> product.price
       >> temp >> product.quantity;

    return is;
}
