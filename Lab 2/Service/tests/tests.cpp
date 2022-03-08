//
// Created by zaha on 3/5/22.
//

#include <cassert>
#include "tests.h"
#include "../problems/problems.h"

void testProblems() {
    int arr[10] = {-40, -64, -53, 3, -44, 76, -87, 64, 87, -59};
    assert(oppositeSignsSequence(arr, 10) == std::make_pair(arr + 2, 6));
    assert(mountainSequence(arr, 10) == std::make_pair(arr + 1, 4));

    int arr2[10] = {33, 30, 41, 34, 91, 71, 90, 99, 26, 53};
    assert(oppositeSignsSequence(arr2, 10) == std::make_pair(arr2, 1));
    assert(mountainSequence(arr2, 10) == std::make_pair(arr2 + 5, 4));

    int arr3[1] = {0};
    assert(oppositeSignsSequence(arr3, 1) == std::make_pair(arr3, 1));
    assert(mountainSequence(arr3, 1) == std::make_pair(arr3, 1));
}

void runTests() {
    testProblems();
}