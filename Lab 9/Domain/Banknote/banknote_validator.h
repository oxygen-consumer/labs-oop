//
// Created by zaha on 5/5/22.
//

#include "banknote.h"
#include <vector>
#include <algorithm>
#include "../../Service/double_compare.h"

#ifndef LAB_9_BANKNOTE_VALIDATOR_H
#define LAB_9_BANKNOTE_VALIDATOR_H


class banknote_validator {
private:
    std::vector<double> accepted_banknotes = {500, 200, 100, 50, 20, 10, 5, 1,
                                              0.5, 0.1, 0.05, 0.01};

public:
    banknote_validator() = default;

    ~banknote_validator() = default;

    bool is_valid(banknote b);

    bool is_valid(double amount);

    std::vector<double> get_accepted_banknotes();

};


#endif //LAB_9_BANKNOTE_VALIDATOR_H
