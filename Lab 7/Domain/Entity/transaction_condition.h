//
// Created by zaha on 4/16/22.
//

#include <string>
#include <utility>
#include "transaction.h"

#ifndef LAB_7_CONDITION_H
#define LAB_7_CONDITION_H


class transaction_condition {
private:
    static bool
    check_description(const std::string &description, transaction &t);

    static bool check_type(const std::string &type, transaction &t);

    static bool check_value_bigger(const int &value, transaction &t);

    static bool check_value_smaller(const int &value, transaction &t);

    static bool check_value_equal(const int &value, transaction &t);

    static bool check_value_not_equal(const int &value, transaction &t);

    static bool check_value_bigger_equal(const int &value, transaction &t);

    static bool check_value_smaller_equal(const int &value, transaction &t);

    static bool check_day(const int &day, transaction &t);

public:
    /**
     * @brief Check if the transaction matches the condition
     * @param t the transaction to check
     * @param condition the condition to check
     * @return true if the transaction matches the condition
     */
    static bool
    check_match(transaction t, std::pair<std::string, std::string> &condition);
};


#endif //LAB_7_CONDITION_H
