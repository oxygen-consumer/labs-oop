//
// Created by zaha on 4/19/22.
//

#include "../Domain/Product.h"
#include "../Repository/Repo.h"
#include <cassert>

#ifndef LAB_9_TEST_H
#define LAB_9_TEST_H


class Test {
private:
    static void test_repo();
    static void test_entity();

public:
    static void run_all_tests();
};


#endif //LAB_9_TEST_H
