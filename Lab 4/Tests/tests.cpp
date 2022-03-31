//
// Created by zaha on 3/17/22.
//

#include <cassert>
#include "tests.h"
#include "../Domain/complex_num.h"
#include "../Repository/repository_in_memory.h"

// TODO: add more tests

void run_tests() {
    test_complex_num();
    test_repository();
    test_biggest_entity();
    test_first_quadrant();
    test_longest_equal_length();
}

void test_complex_num() {
    complex_num num1;
    assert(num1.get_img() == 0);
    assert(num1.get_real() == 0);

    num1.set_img(3);
    assert(num1.get_img() == 3);
    num1.set_real(-123);
    assert(num1.get_real() == -123);

    complex_num num2(num1);
    assert(num2.get_real() == -123);
    assert(num2.get_img() == 3);

    assert(num1 == num2);
    assert(num1.to_str() == "-123 + 3i");
}

void test_repository() {
    numbers repo;
    repo.add(complex_num(1, 2));
    repo.add(complex_num(3, 4));
    repo.add(complex_num(5, 6));
    assert(repo.get_all().size() == 3);
    std::queue<complex_num> q = repo.get_all();
    assert(q.front().get_real() == 1);
    assert(q.front().get_img() == 2);
    q.pop();
    assert(q.front().get_real() == 3);
    assert(q.front().get_img() == 4);
    q.pop();
    assert(q.front().get_real() == 5);
    assert(q.front().get_img() == 6);
    q.pop();
    assert(q.empty());
}

void test_biggest_entity() {
    numbers repo;
    repo.add(complex_num(1, 2));
    repo.add(complex_num(3, 4));
    repo.add(complex_num(5, 6));
    assert(repo.get_biggest().get_real() == 5);
    assert(repo.get_biggest().get_img() == 6);
}

void test_first_quadrant() {
    numbers repo;
    repo.add(complex_num(1, 2));
    repo.add(complex_num(3, 4));
    repo.add(complex_num(-1, 6));
    assert(repo.get_all_in_first_quadrant().size() == 2);
    std::queue<complex_num> q = repo.get_all_in_first_quadrant();
    assert(q.front().get_real() == 1);
    assert(q.front().get_img() == 2);
    q.pop();
    assert(q.front().get_real() == 3);
    assert(q.front().get_img() == 4);
    q.pop();
    assert(q.empty());
}

void test_longest_equal_length() {
    numbers repo;
    repo.add(complex_num(1, 2));
    repo.add(complex_num(3, 4));
    repo.add(complex_num(3, 4));
    repo.add(complex_num(3, 4));
    repo.add(complex_num(5, 6));

    assert(repo.get_longest_equal_sequence().size() == 3);
    std::queue<complex_num> q = repo.get_longest_equal_sequence();
    assert(q.front().get_real() == 3);
    assert(q.front().get_img() == 4);
    q.pop();
    assert(q.front().get_real() == 3);
    assert(q.front().get_img() == 4);
    q.pop();
    assert(q.front().get_real() == 3);
    assert(q.front().get_img() == 4);
    q.pop();
    assert(q.empty());
}
