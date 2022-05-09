//
// Created by zaha on 5/5/22.
//

#include "test_repo_in_file.h"

void test_repo_in_file::run_tests() {
    test_repo();
}

void test_repo_in_file::test_repo() {
    repo_in_file<product> repo("test_repo.txt");
    product p1(1, 1, "p1", 10.0, 5);
    product p2(2, 2, "p2", 20.0, 5);
    product p3(3, 3, "p3", 30.0, 5);
    repo.add(p1);
    repo.add(p2);
    repo.add(p3);
    assert(repo.get_all().size() == 3);
    assert(repo.get_by_id(1) == p1);
    assert(repo.get_by_id(2) == p2);
    assert(repo.get_by_id(3) == p3);
    repo.remove(p1);
    assert(repo.get_all().size() == 2);
    assert(repo.get_by_id(1) == product());
    assert(repo.get_by_id(2) == p2);
    assert(repo.get_by_id(3) == p3);
    p2.set_name("p2_new");
    repo.update(p2);
    assert(repo.get_all().size() == 2);
    assert(repo.get_by_id(1) == product());
    assert(repo.get_by_id(2) == p2);
    assert(repo.get_by_id(3) == p3);
    assert(repo.size() == 2);

    repo.remove(p2);
    repo.remove(p3);
    assert(repo.size() == 0);
}
