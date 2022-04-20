//
// Created by zaha on 4/19/22.
//

#include "Test.h"

// TODO: Add more tests

void Test::test_repo() {
    Repo<Product> repo;
    Product p1(1, 1, "desc1", 10);
    Product p2(2, 2, "desc2", 20);
    repo.addElem(p1);
    repo.addElem(p2);
    assert(repo.getSize() == 2);
    assert(repo.getAll()[0] == p1);
    assert(repo.getAll()[1] == p2);
    repo.delElem(p1);
    assert(repo.getSize() == 1);
    assert(repo.getAll()[0] == p2);
    repo.delElem(p2);
    assert(repo.getSize() == 0);
}

void Test::test_entity() {
    Product p1(1, 1, "desc", 10);
    assert(p1.getId() == 1);
    assert(p1.getPrice() == 10);
    assert(p1.getName() == "desc");
    assert(p1.getCode() == 1);
}

void Test::run_all_tests() {
    test_entity();
    test_repo();
}
