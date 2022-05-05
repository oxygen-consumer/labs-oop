//
// Created by zaha on 5/5/22.
//

#include <cassert>
#include "../../Domain/Product/product.h"
#include "../../Domain/Product/product_validator.h"

#ifndef LAB_9_TEST_PRODUCT_H
#define LAB_9_TEST_PRODUCT_H


class test_product {
private:
    static void test_product_class();

    static void test_product_validator();

public:
    static void run_tests();
};


#endif //LAB_9_TEST_PRODUCT_H
