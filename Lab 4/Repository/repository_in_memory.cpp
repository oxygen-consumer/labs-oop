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
    return (int) this->storage.size();
}

std::queue<complex_num> numbers::get_all() {
    return this->storage;
}

complex_num numbers::get_biggest() {
    complex_num ans = this->storage.front();
    for (int i = 0; i < this->storage.size(); ++i) {
        if (this->storage.front() > ans) {
            ans = this->storage.front();
        }

        this->storage.push(this->storage.front());
        this->storage.pop();
    }

    return ans;
}

std::queue<complex_num> numbers::get_all_in_first_quadrant() {
    std::queue<complex_num> ans;
    for (int i = 0; i < this->storage.size(); ++i) {
        if (this->storage.front().in_first_quadrant()) {
            ans.push(this->storage.front());
        }

        this->storage.push(this->storage.front());
        this->storage.pop();
    }

    return ans;
}

// TODO: refactor this monster
std::queue<complex_num> numbers::get_longest_equal_sequence() {
    complex_num ans;
    int max_len = 0;

    complex_num curr = this->storage.front();
    int curr_len = 1;

    this->storage.push(this->storage.front());
    this->storage.pop();

    for (int i = 1; i < this->storage.size(); ++i) {
        if (this->storage.front() == curr) {
            ++curr_len;
        } else {
            if (curr_len > max_len) {
                ans = curr;
                max_len = curr_len;
            }

            curr = this->storage.front();
            curr_len = 1;
        }

        this->storage.push(this->storage.front());
        this->storage.pop();
    }

    if (curr_len > max_len) {
        ans = curr;
        max_len = curr_len;
    }

    std::queue<complex_num> ans_queue;
    for (int i = 0; i < max_len; ++i) {
        ans_queue.push(ans);
    }
    return ans_queue;
}
