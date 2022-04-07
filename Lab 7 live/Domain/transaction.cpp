//
// Created by zaha on 4/7/22.
//

#include "transaction.h"

bool transaction::operator==(const transaction &rhs) const {
    return id == rhs.id;
}

bool transaction::operator!=(const transaction &rhs) const {
    return !(rhs == *this);
}

transaction::transaction() {
    id = 0;
}

transaction::transaction(int id) {
    this->id = id;
}

transaction::~transaction() = default;

int transaction::get_id() {
    return this->id;
}

void transaction::set_id(int id) {
    this->id = id;
}
