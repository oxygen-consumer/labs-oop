//
// Created by zaha on 3/17/22.
//

#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double real, double img) {
    this->real = real;
    this->img = img;
}

ComplexNumber::ComplexNumber() {
    this->real = 0;
    this->img = 0;
}

void ComplexNumber::set_real(double n) {
    this->real = n;
}

void ComplexNumber::set_img(double n) {
    this->img = n;
}

double ComplexNumber::get_real() const {
    return this->real;
}

double ComplexNumber::get_img() const {
    return this->img;
}

ComplexNumber::ComplexNumber(ComplexNumber const &n) {
    this->real = n.get_real();
    this->img = n.get_img();
}

ComplexNumber::~ComplexNumber() = default;
