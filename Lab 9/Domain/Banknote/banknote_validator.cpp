//
// Created by zaha on 5/5/22.
//

#include "banknote_validator.h"

bool banknote_validator::is_valid(banknote b) {
    for (int i = 0; i < accepted_banknotes.size(); ++i) {
        if (b.get_value() == accepted_banknotes[i]) {
            return true;
        }
    }
    return false;
}

bool banknote_validator::is_valid(double amount) {
    for (int i = 0; i < accepted_banknotes.size(); ++i) {
        if (amount == accepted_banknotes[i]) {
            return true;
        }
    }
    return false;
}

std::vector<double> banknote_validator::get_accepted_banknotes() {
    return this->accepted_banknotes;
}
