//
// Created by zaha on 5/5/22.
//

#include "test_banknote.h"

void test_banknote::run_tests() {
    test_banknote_class();
    test_banknote_validator();
}

void test_banknote::test_banknote_class() {
    banknote b0;
    banknote b1(1, 100, 5);
    banknote b2(2, 500, 1);
    banknote b3(b1);
    banknote b4 = b2;

    assert(b0.get_id() == 0);
    assert(b0.get_value() == 0);
    assert(b0.get_quantity() == 0);

    assert(b1.get_id() == 1);
    assert(b1.get_value() == 100);
    assert(b1.get_quantity() == 5);

    assert(b1 == b3);
    assert(b1 != b2);
    assert(b2 == b4);

    b1.set_id(2);
    assert(b1 == b2);
    assert(b1 != b3);
    b1.set_id(1);

    b1.set_value(500);
    assert(b1 != b2);
    b1.set_value(100);

    b3.set_quantity(10);
    assert(b1 == b3);
    assert(b1 != b2);
    assert(b3.get_quantity() == 10);
    b3.set_id(4);
    assert(b3.get_id() == 4);
    b3.set_value(50);
    assert(b3.get_value() == 50);
}

void test_banknote::test_banknote_validator() {

}
