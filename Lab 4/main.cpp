#include <iostream>
#include "ComplexNumber.h"

int main() {
    ComplexNumber num;
    double tmp;

    std::cout << "Real: ";
    std::cin >> tmp;
    num.set_real(tmp);
    std::cout << "Imaginary: ";
    std::cin >> tmp;
    num.set_img(tmp);

    std::cout << num.get_real() << (num.get_img() > 0 ? " + " : " - ") <<
        std::abs(num.get_img()) << "i";
    return 0;
}
