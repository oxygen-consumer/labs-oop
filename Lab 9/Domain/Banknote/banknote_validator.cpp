//
// Created by zaha on 5/5/22.
//

#include "banknote_validator.h"

bool banknote_validator::is_valid(banknote b) {
    return std::any_of(accepted_banknotes.begin(), accepted_banknotes.end(),
                       [&](double a) {
                           return double_compare::equal(a, b.get_value());
                       });
}

bool banknote_validator::is_valid(double amount) {
    return std::any_of(accepted_banknotes.begin(), accepted_banknotes.end(),
                       [&](double a) {
                           return double_compare::equal(a, amount);
                       });
}

std::vector<double> banknote_validator::get_accepted_banknotes() {
    return this->accepted_banknotes;
}
