//
// Created by zaha on 5/5/22.
//

#include "product_validator.h"

bool product_validator::is_valid(product &p) {
    if (p.get_name().empty()) {
        return false;
    }

    if (p.get_price() < 0) {
        return false;
    }

    if (p.get_quantity() < 0) {
        return false;
    }

    return true;
}
