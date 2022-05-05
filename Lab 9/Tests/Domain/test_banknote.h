//
// Created by zaha on 5/5/22.
//

#include <cassert>
#include "../../Domain/Banknote/banknote.h"
#include "../../Domain/Banknote/banknote_validator.h"

#ifndef LAB_9_TEST_BANKNOTE_H
#define LAB_9_TEST_BANKNOTE_H


class test_banknote {
private:
    static void test_banknote_class();

    static void test_banknote_exception();

    static void test_banknote_validator();

public:
    static void run_tests();
};


#endif //LAB_9_TEST_BANKNOTE_H
