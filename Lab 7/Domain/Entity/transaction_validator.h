//
// Created by zaha on 4/16/22.
//

#include <string>
#include <stdexcept>

#ifndef LAB_7_TRANSACTION_VALIDATOR_H
#define LAB_7_TRANSACTION_VALIDATOR_H


class transaction_validator {
private:
    static void check_day(int day);

    static void check_type(const std::string &type);

    static void check_value(int value);

public:
    static void validate(int day, std::string type, int value);
};


#endif //LAB_7_TRANSACTION_VALIDATOR_H
