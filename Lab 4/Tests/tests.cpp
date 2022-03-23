//
// Created by zaha on 3/17/22.
//

#include <cassert>
#include "tests.h"
#include "../Domain/complex_num.h"

void run_tests() {
    complex_num num1;
    assert(num1.get_img() == 0);
    assert(num1.get_real() == 0);

    num1.set_img(3);
    assert(num1.get_img() == 3);
    num1.set_real(-123);
    assert(num1.get_real() == -123);

    complex_num num2(num1);
    assert(num2.get_real() == -123);
    assert(num2.get_img() == 3);

    assert(num1 == num2);
    assert(num1.to_str() == "-123 + 3i");

    // TODO more tests
}
