//
// Created by zaha on 2/24/22.
//

#include <cassert>
#include "test_palindrom.h"
#include "../Problem/palindrom.h"

void test_palindrom() {
    assert(palindrom(1234) == 12344321);
    assert(palindrom(1) == 11);
    assert(palindrom(0) == 0);
    assert(palindrom(10) == 1001);
}