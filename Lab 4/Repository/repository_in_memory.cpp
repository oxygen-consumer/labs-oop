//
// Created by zaha on 3/24/22.
//

#include "repository_in_memory.h"

numbers::numbers() = default;

numbers::~numbers() = default;

complex_num numbers::get(int pos) {
    if (pos >= this->storage.size() || pos < 0) {
        return {0, 0};
    }

    complex_num ans;
    for (int i = 0; i < this->storage.size(); ++i) {
        if (i == pos) {
            ans = this->storage.front();
        }

        this->storage.push(this->storage.front());
        this->storage.pop();
    }

    return ans;
}

int numbers::add(complex_num num) {
    this->storage.push(num);
    return (int)this->storage.size();
}

std::queue<complex_num> numbers::get_all() {
    return this->storage;
}
