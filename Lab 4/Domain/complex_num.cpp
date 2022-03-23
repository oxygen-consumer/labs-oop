//
// Created by zaha on 3/17/22.
//

#include "complex_num.h"

complex_num::complex_num(double real, double img) {
    this->real = real;
    this->img = img;
}

complex_num::complex_num() {
    this->real = 0;
    this->img = 0;
}

void complex_num::set_real(double n) {
    this->real = n;
}

void complex_num::set_img(double n) {
    this->img = n;
}

double complex_num::get_real() const {
    return this->real;
}

double complex_num::get_img() const {
    return this->img;
}

complex_num::complex_num(complex_num const &n) {
    this->real = n.get_real();
    this->img = n.get_img();
}

bool operator==(const complex_num &x, const complex_num &y) {
    return (x.get_img() == y.get_img() && x.get_real() == y.get_real());
}

std::string complex_num::to_str() const {
    std::ostringstream oss;

    if (this->real == 0 && this->img != 0) {
        oss << this->img << "i";
    } else if (this->real != 0 && this->img == 0) {
        oss << this->real;
    } else {
        oss << this->real << (this->img > 0 ? " + " : " - ") <<
            std::abs(this->img) << "i";
    }

    return oss.str();
}

void complex_num::read_from_stdin() {
    std::cout << "real: ";
    std::cin >> this->real;
    std::cout << "img: ";
    std::cin >> this->img;
}

double complex_num::distance_from_orig() {
    return sqrt(pow(this->real, 2) + pow(this->img, 2));
}

complex_num::~complex_num() = default;
