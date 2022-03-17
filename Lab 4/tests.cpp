//
// Created by zaha on 3/17/22.
//

#include <cassert>
#include "tests.h"
#include "ComplexNumber.h"

void run_tests() {
    ComplexNumber num1;
    assert(num1.get_img() == 0);
    assert(num1.get_real() == 0);

    num1.set_img(3);
    assert(num1.get_img() == 3);
    num1.set_real(-123);
    assert(num1.get_real() == -123);

    ComplexNumber num2(num1);
    assert(num2.get_real() == -123);
    assert(num2.get_img() == 3);

    // TODO more tests
}
