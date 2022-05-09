//
// Created by zaha on 5/5/22.
//

#include "test_product.h"

void test_product::run_tests() {
    test_product_class();
    test_product_validator();
}

void test_product::test_product_class() {
    product p0;
    product p1(1, 1, "prod1", 20.0, 1);
    product p2(2, 2, "prod2", 30.0, 2);
    product p3(p1);
    product p4 = p2;

    assert(p0.get_id() == 0);
    assert(p0.get_quantity() == 0);
    assert(p0.get_name().empty());
    assert(p0.get_price() == 0.0);
    assert(p0.get_code() == 0);

    assert(p1.get_id() == 1);
    assert(p1.get_code() == 1);
    assert(p1.get_name() == "prod1");
    assert(p1.get_price() == 20.0);
    assert(p1.get_quantity() == 1);

    assert(p3 == p1);
    assert(p1 != p2);
    assert(p4 == p2);

    p1.set_id(2);
    assert(p1 == p2);
    assert(p1 != p3);
    p1.set_id(1);

    p2.set_id(3);
    assert(p1 != p2);
    assert(p2 != p4);
    p2.set_id(2);

    p1.set_code(2);
    assert(p1.get_code() == 2);
    assert(p1 != p2);
    p1.set_code(1);

    p1.set_name("test");
    assert(p1.get_name() == "test");
    p1.set_price(10.0);
    assert(p1.get_price() == 10.0);
    p1.set_quantity(2);
    assert(p1.get_quantity() == 2);
}

void test_product::test_product_validator() {
    product p1(1, 1, "prod1", 20.0, 1);
    product p2(2, 2, "prod2", 30.0, 2);
    product p3(3, 3, "prod3", 40.0, -1);
    product p4(4, 4, "", 50.0, 0);

    assert(product_validator::is_valid(p1));
    assert(product_validator::is_valid(p2));
    assert(!product_validator::is_valid(p3));
    assert(!product_validator::is_valid(p4));
}

