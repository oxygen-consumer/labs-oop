//
// Created by zaha on 5/9/22.
//

#include "test_double_compare.h"

void test_double_compare::run_tests() {
    test_equal();
    test_not_equal();
    test_less();
    test_less_or_equal();
    test_greater();
    test_greater_or_equal();
}

void test_double_compare::test_equal() {
    double a = 1.0;
    double b = 1.0;
    assert(double_compare::equal(a, b));

    a = 1.0;
    b = 2.0;
    assert(!double_compare::equal(a, b));
}

void test_double_compare::test_not_equal() {
    double a = 1.0;
    double b = 1.0;
    assert(!double_compare::not_equal(a, b));

    a = 1.0;
    b = 2.0;
    assert(double_compare::not_equal(a, b));
}

void test_double_compare::test_less() {
    double a = 1.0;
    double b = 1.0;
    assert(!double_compare::less(a, b));

    a = 1.0;
    b = 2.0;
    assert(double_compare::less(a, b));
    assert(!double_compare::less(b, a));
}

void test_double_compare::test_greater() {
    double a = 1.0;
    double b = 1.0;
    assert(!double_compare::greater(a, b));

    a = 1.0;
    b = 2.0;
    assert(!double_compare::greater(a, b));
    assert(double_compare::greater(b, a));
}

void test_double_compare::test_less_or_equal() {
    double a = 1.0;
    double b = 1.0;
    assert(double_compare::less_or_equal(a, b));

    a = 1.0;
    b = 2.0;
    assert(double_compare::less_or_equal(a, b));
    assert(!double_compare::less_or_equal(b, a));
    assert(double_compare::less_or_equal(b, b));
}

void test_double_compare::test_greater_or_equal() {
    double a = 1.0;
    double b = 1.0;
    assert(double_compare::greater_or_equal(a, b));

    a = 1.0;
    b = 2.0;
    assert(double_compare::greater_or_equal(b, a));
    assert(!double_compare::greater_or_equal(a, b));
    assert(double_compare::greater_or_equal(b, b));
}
