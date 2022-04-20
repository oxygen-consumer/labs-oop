//
// Created by zaha on 4/3/22.
//

#include "../Domain/Entity/transaction.h"
#include "../Domain/vector.h"
#include "../Repository/repository.h"
#include "../Service/transaction_service.h"
#include <cassert>

#ifndef LAB_7_TESTS_H
#define LAB_7_TESTS_H

// TODO: add rest of the tests

class tests {
private:
    /**
     * @brief Test the transaction entity
     */
    static void test_transaction() {
        transaction t1(1, 200, "test", true, 20);
        assert(t1.get_id() == 1);
        assert(t1.get_value() == 200);
        assert(strcmp(t1.get_description(), "test") == 0);
        assert(t1.get_type() == true);
        assert(t1.get_day() == 20);
    }

    /**
     * @brief Test the homemade vector
     */
    static void test_vector() {
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

    /**
     * @brief Test the repository
     */
    static void test_repository() {
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

    /**
     * @brief Test the transaction service
     */
    static void test_transaction_service() {
        // Test the add function
        transaction_service ts;
        ts.add_transaction(200, "in", "test", 20);
        ts.add_transaction(300, "out", "test2", 30);
        std::queue<transaction> q = ts.get_transactions(std::queue<std::string>());
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

        // Test the get function
        assert(ts.get_transaction(1).get_id() == 1);
        assert(ts.get_transaction(1).get_value() == 200);

        // Test the update function
        ts.update_transaction(1, 900, "out", "test", 20);
        q = ts.get_transactions(std::queue<std::string>());
        assert(q.size() == 2);
        assert(q.front().get_id() == 1);
        assert(q.front().get_value() == 900);
        assert(strcmp(q.front().get_description(), "test") == 0);
        assert(q.front().get_type() == false);

        // Test the delete function
        ts.delete_transaction(1);
        q = ts.get_transactions(std::queue<std::string>());
        assert(q.size() == 1);
        assert(q.front().get_id() == 2);
        assert(q.front().get_value() == 300);
        assert(strcmp(q.front().get_description(), "test2") == 0);
        assert(q.front().get_type() == false);

        // Test the get_balance function
        assert(ts.get_balance_of_the_day(30) == -300);
        assert(ts.get_balance_of_the_day(20) == 0);

        // Test clear
        ts.clear_transactions(std::queue<std::string>());
        try {
            ts.get_transaction(1);
            assert(false);
        } catch (std::exception &e) {
            assert(true);
        }

        // Test get_sum_of_transactions
        ts.add_transaction(200, "in", "test", 20);
        ts.add_transaction(300, "out", "test2", 30);
        assert(ts.get_sum_of_transactions(std::queue<std::string>()) == -100);
        ts.add_transaction(400, "in", "test", 20);
        assert(ts.get_sum_of_transactions(std::queue<std::string>()) == 300);

        // Test get_sum_of_transactions_of_type
        std::queue<std::string> q2;
        q2.push("type");
        q2.push("in");
        assert(ts.get_sum_of_transactions(q2) == 600);
        q2.push("type");
        q2.push("out");
        q2.pop();
        q2.pop();
        assert(ts.get_sum_of_transactions(q2) == -300);

        // Test get_sum_of_transactions_of_type_of_day
        q2.pop();
        q2.pop();
        q2.push("day");
        q2.push("20");
        assert(ts.get_sum_of_transactions(q2) == 600);
        q2.push("day");
        q2.push("30");
        q2.pop();
        q2.pop();
        assert(ts.get_sum_of_transactions(q2) == -300);

        // Test get_sum_of_transactions_of_type_of_day_of_description
        q2.pop();
        q2.pop();
        q2.push("description");
        q2.push("test");
        assert(ts.get_sum_of_transactions(q2) == 600);
        q2.push("description");
        q2.push("test2");
        q2.pop();
        q2.pop();
        assert(ts.get_sum_of_transactions(q2) == -300);

        // Test get_sum_of_transactions_of_type_of_day_of_description_of_value
        q2.pop();
        q2.pop();
        q2.push("=");
        q2.push("300");
        assert(ts.get_sum_of_transactions(q2) == -300);

        // Test min and max
        ts.clear_transactions(std::queue<std::string>());
        ts.add_transaction(200, "in", "test", 20);
        ts.add_transaction(300, "out", "test2", 30);
        ts.add_transaction(400, "in", "test", 20);
        transaction t = ts.get_min_transaction(std::queue<std::string>());
        assert(t.get_value() == 200);
        t = ts.get_max_transaction(std::queue<std::string>());
        assert(t.get_value() == 400);
    }

public:
    /**
     * @brief Test the whole program
     */
    static void run_tests() {
        test_transaction();
        test_vector();
        test_repository();
        test_transaction_service();
    }
};


#endif //LAB_7_TESTS_H
