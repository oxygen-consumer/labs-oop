//
// Created by zaha on 4/7/22.
//

#include "tests.h"

void tests::test_transaction() {
    transaction t1;
    t1.set_id(1);
    assert(t1.get_id() == 1);
    transaction t2(2);
    assert(t2.get_id() == 2);
    transaction t3(t2);
    assert(t3 == t2);
}

void tests::test_vector() {
    vector<transaction> v;
    v.push_back(transaction(1));
    v.push_back(transaction(2));
    v.push_back(transaction(3));
    assert(v.size() == 3);
    assert(v[0].get_id() == 1);
    assert(v[1].get_id() == 2);
    assert(v[2].get_id() == 3);
    v.remove(1);
    assert(v.size() == 2);
    assert(v[0].get_id() == 1);
    assert(v[1].get_id() == 3);
    v.remove(0);
    assert(v.size() == 1);
    assert(v[0].get_id() == 3);
    v.remove(3);
    assert(v.size() == 0);
}

void tests::test_repository() {
    repository<transaction> r;
    r.add(transaction(1));
    r.add(transaction(2));
    r.add(transaction(3));
    assert(r.size() == 3);
    assert(r.get_all()[0].get_id() == 1);
    assert(r.get_all()[1].get_id() == 2);
    assert(r.get_all()[2].get_id() == 3);
    r.remove(1);
    assert(r.size() == 2);
    assert(r.get_all()[0].get_id() == 1);
    assert(r.get_all()[1].get_id() == 3);
    r.remove(0);
    assert(r.size() == 1);
    assert(r.get_all()[0].get_id() == 3);
    r.remove(0);
    assert(r.size() == 0);
}

void tests::run_tests() {
    test_transaction();
    test_vector();
    test_repository();
}
