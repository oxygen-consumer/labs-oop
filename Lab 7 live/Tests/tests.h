//
// Created by zaha on 4/7/22.
//

#include "../Domain/transaction.h"
#include "../Domain/vector.h"
#include "../Repository/repository.h"
#include <cassert>

#ifndef LAB_7_LIVE_TESTS_H
#define LAB_7_LIVE_TESTS_H


class tests {
private:
    void test_transaction();

    void test_vector();

    void test_repository();

public:
    void run_tests();
};


#endif //LAB_7_LIVE_TESTS_H
