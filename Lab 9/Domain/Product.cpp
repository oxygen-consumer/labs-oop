//
// Created by zaha on 4/19/22.
//

#include "Product.h"

#include <utility>

Product::Product() {
    this->id = 0;
    this->code = 0;
    this->name = "";
    this->price = 0;
}

Product::Product(int id, int code, std::string name, int price) {
    this->id = id;
    this->code = code;
    this->name = std::move(name);
    this->price = price;
}

Product::Product(const Product &product) {
    this->id = product.id;
    this->code = product.code;
    this->name = product.name;
    this->price = product.price;
}

Product::~Product() = default;

int Product::getId() const {
    return this->id;
}

int Product::getCode() const {
    return this->code;
}

std::string Product::getName() const {
    return this->name;
}

int Product::getPrice() const {
    return this->price;
}

void Product::setId(int id) {
    this->id = id;
}

void Product::setCode(int code) {
    this->code = code;
}

void Product::setName(std::string name) {
    this->name = std::move(name);
}

void Product::setPrice(int price) {
    this->price = price;
}

Product &Product::operator=(const Product &product) {
    if (this != &product) {
        this->id = product.id;
        this->code = product.code;
        this->name = product.name;
        this->price = product.price;
    }
    return *this;
}

bool Product::operator==(const Product &product) {
    return this->id == product.id && this->code == product.code && this->name == product.name &&
           this->price == product.price;
}

bool Product::operator!=(const Product &product) {
    return !(*this == product);
}

std::string Product::toString() {
    return "Product: " + std::to_string(this->id) + " " + std::to_string(this->code) + " " + this->name + " " +
           std::to_string(this->price);
}
