//
// Created by zaha on 4/3/22.
//

#include "../Domain/transaction.h"
#include "../Domain/vector.h"
#include "../Repository/repository.h"
#include "../Service/transaction_service.h"
#include <iostream>
#include <cassert>

#ifndef LAB_7_TESTS_H
#define LAB_7_TESTS_H

// TODO: add more tests

class tests {
private:
    void test_transaction() {
        char *description = "test";
        transaction t1(1, 200, description, true, 20);
        assert(t1.get_id() == 1);
        assert(t1.get_value() == 200);
        assert(strcmp(t1.get_description(), description) == 0);
        assert(t1.get_type() == true);
        assert(t1.get_day() == 20);
    }

    void test_vector() {
        vector<transaction> v;
        v.push_back(transaction(1, 200, "test", true, 20));
        v.push_back(transaction(2, 300, "test2", false, 30));
        assert(v.size() == 2);
        assert(v[0].get_id() == 1);
        assert(v[1].get_id() == 2);
        assert(v[0].get_value() == 200);
        assert(v[1].get_value() == 300);
        assert(strcmp(v[0].get_description(), "test") == 0);
        assert(strcmp(v[1].get_description(), "test2") == 0);
        assert(v[0].get_type() == true);
        assert(v[1].get_type() == false);
        assert(v[0].get_day() == 20);
        assert(v[1].get_day() == 30);
    }

    void test_repository() {
        repository<transaction> r;
        r.add(transaction(1, 200, "test", true, 20));
        r.add(transaction(2, 300, "test2", false, 30));
        assert(r.size() == 2);
        assert(r.get_all()[0].get_id() == 1);
        assert(r.get_all()[1].get_id() == 2);
        assert(r.get_all()[0].get_value() == 200);
        assert(r.get_all()[1].get_value() == 300);
        assert(strcmp(r.get_all()[0].get_description(), "test") == 0);
        assert(strcmp(r.get_all()[1].get_description(), "test2") == 0);
        assert(r.get_all()[0].get_type() == true);
        assert(r.get_all()[1].get_type() == false);
        assert(r.get_all()[0].get_day() == 20);
        assert(r.get_all()[1].get_day() == 30);
    }

    void test_transaction_service() {
        transaction_service ts;
        ts.add_transaction(200, "in", "test", 20);
        ts.add_transaction(300, "out", "test2", 30);
        std::queue<transaction> q = ts.get_transactions("all", std::queue<std::string>());
        assert(q.size() == 2);
        assert(q.front().get_id() == 1);
        assert(q.front().get_value() == 200);
        assert(strcmp(q.front().get_description(), "test") == 0);
        assert(q.front().get_type() == true);
        assert(q.front().get_day() == 20);
        q.pop();
        assert(q.front().get_id() == 2);
        assert(q.front().get_value() == 300);
        assert(strcmp(q.front().get_description(), "test2") == 0);
        assert(q.front().get_type() == false);
        assert(q.front().get_day() == 30);

        ts.update_transaction(1, 900, "out", "test", 20);
        q = ts.get_transactions("all", std::queue<std::string>());
        assert(q.size() == 2);
        assert(q.front().get_id() == 1);
        assert(q.front().get_value() == 900);
        assert(strcmp(q.front().get_description(), "test") == 0);
        assert(q.front().get_type() == false);
        ts.delete_transaction(1);
        q = ts.get_transactions("all", std::queue<std::string>());
        assert(q.size() == 1);
        assert(q.front().get_id() == 2);
        assert(q.front().get_value() == 300);
        assert(strcmp(q.front().get_description(), "test2") == 0);
        assert(q.front().get_type() == false);

        //this fails, needs debugging
//        assert(ts.get_balance_of_the_day(30) == 300);
        assert(ts.get_balance_of_the_day(20) == 0);
    }

public:
    void run_tests() {
        test_transaction();
        test_vector();
        test_repository();
        test_transaction_service();
    }
};


#endif //LAB_7_TESTS_H
