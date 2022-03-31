//
// Created by zaha on 3/17/22.
//

#include "complex_num.h"
#include <limits>

#define EPS std::numeric_limits<double>::epsilon()

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

bool complex_num::operator<(const complex_num &rhs) const {
    if (real < rhs.real)
        return true;
    if (rhs.real < real)
        return false;
    return img < rhs.img;
}

bool complex_num::operator>(const complex_num &rhs) const {
    return rhs < *this;
}

bool complex_num::operator<=(const complex_num &rhs) const {
    return !(rhs < *this);
}

bool complex_num::operator>=(const complex_num &rhs) const {
    return !(*this < rhs);
}

bool complex_num::operator==(const complex_num &rhs) const {
    return std::abs(real - rhs.real) < EPS && std::abs(img - rhs.img) < EPS;
}

bool complex_num::operator!=(const complex_num &rhs) const {
    return !(rhs == *this);
}

bool complex_num::in_first_quadrant() {
    return real > 0 && img > 0;
}

complex_num::~complex_num() = default;
