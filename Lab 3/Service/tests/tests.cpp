//
// Created by zaha on 3/8/22.
//

#include "tests.h"
#include <cassert>
#include "../problems/problems.h"

void testProblems() {
    int *arr = new int[10] {-40, -64, -53, 3, -44, 76, -87, 64, 87, -59};
    assert(oppositeSignsSequence(arr, 10) == std::make_pair(arr + 2, 6));
    assert(mountainSequence(arr, 10) == std::make_pair(arr + 1, 4));
    delete[] arr;

    int *arr2 = new int[10] {33, 30, 41, 34, 91, 71, 90, 99, 26, 53};
    assert(oppositeSignsSequence(arr2, 10) == std::make_pair(arr2, 1));
    assert(mountainSequence(arr2, 10) == std::make_pair(arr2 + 5, 4));
    delete[] arr2;

    int *arr3 = new int[1] {0};
    assert(oppositeSignsSequence(arr3, 1) == std::make_pair(arr3, 1));
    assert(mountainSequence(arr3, 1) == std::make_pair(arr3, 1));
    delete[] arr3;
}

void runTests() {
    testProblems();
}
