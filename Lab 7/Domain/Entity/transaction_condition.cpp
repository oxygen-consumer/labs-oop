//
// Created by zaha on 4/16/22.
//

#include "transaction_condition.h"

bool
transaction_condition::check_match(transaction t,
                                   std::pair<std::string, std::string> &condition) {
    if (condition.first == "<") {
        return check_value_smaller(stoi(condition.second), t);
    } else if (condition.first == ">") {
        return check_value_bigger(stoi(condition.second), t);
    } else if (condition.first == "=") {
        return check_value_equal(stoi(condition.second), t);
    } else if (condition.first == "!=") {
        return check_value_not_equal(stoi(condition.second), t);
    } else if (condition.first == ">=") {
        return check_value_bigger_equal(stoi(condition.second), t);
    } else if (condition.first == "<=") {
        return check_value_smaller_equal(stoi(condition.second), t);
    } else if (condition.first == "type") {
        return check_type(condition.second, t);
    } else if (condition.first == "day") {
        return check_day(stoi(condition.second), t);
    } else if (condition.first == "description") {
        return check_description(condition.second, t);
    } else {
        throw std::invalid_argument("Invalid transaction_condition");
    }
}

bool
transaction_condition::check_description(const std::string &description,
                                         transaction &t) {
    return description == t.get_description();
}

bool
transaction_condition::check_value_bigger(const int &value, transaction &t) {
    return value > t.get_value();
}

bool
transaction_condition::check_value_smaller(const int &value, transaction &t) {
    return value < t.get_value();
}

bool
transaction_condition::check_value_equal(const int &value, transaction &t) {
    return value == t.get_value();
}

bool transaction_condition::check_day(const int &day, transaction &t) {
    return day == t.get_day();
}

bool transaction_condition::check_value_not_equal(const int &value,
                                                  transaction &t) {
    return value != t.get_value();
}

bool transaction_condition::check_value_bigger_equal(const int &value,
                                                     transaction &t) {
    return value >= t.get_value();
}

bool transaction_condition::check_value_smaller_equal(const int &value,
                                                      transaction &t) {
    return value <= t.get_value();
}

bool
transaction_condition::check_type(const std::string &type, transaction &t) {
    if (type == "in") {
        return t.get_type();
    } else if (type == "out") {
        return !t.get_type();
    } else {
        throw std::invalid_argument("Invalid type");
    }
}
