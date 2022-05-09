//
// Created by zaha on 5/9/22.
//

#include <cassert>
#include "../../Service/double_compare.h"

#ifndef LAB_9_TEST_DOUBLE_COMPARE_H
#define LAB_9_TEST_DOUBLE_COMPARE_H


class test_double_compare {
private:
    static void test_equal();

    static void test_not_equal();

    static void test_less();

    static void test_greater();

    static void test_less_or_equal();

    static void test_greater_or_equal();

public:
    static void run_tests();
};


#endif //LAB_9_TEST_DOUBLE_COMPARE_H
