//
// Created by zaha on 4/16/22.
//

#include "transaction_validator.h"

#include <utility>

void transaction_validator::check_day(int day) {
    if (day < 1 || day > 31) {
        throw std::invalid_argument("Invalid day");
    }
}

void transaction_validator::check_type(const std::string &type) {
    if (type != "in" && type != "out") {
        throw std::invalid_argument("Invalid type");
    }
}

void transaction_validator::check_value(int value) {
    if (value < 0) {
        throw std::invalid_argument("Invalid value");
    }
}

void transaction_validator::validate(int day, std::string type, int value) {
    check_day(day);
    check_type(std::move(type));
    check_value(value);
}
