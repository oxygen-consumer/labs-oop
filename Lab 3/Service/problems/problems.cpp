//
// Created by zaha on 3/8/22.
//

#include "problems.h"
#include <utility>

std::pair<int *, int> oppositeSignsSequence(int *list, int size) {
    // ans stores the longest sequence, ans_sz stores its size
    // cur_ans stores the current sequence we are working with, similarly,
    // cur_sz stores its size
    int *ans, *cur_ans = list;
    int ans_sz = 0, cur_sz = 1;

    for (int i = 1; i <= size; ++i) {
        // if we didn't pass through the whole array already check if the
        // current number has the opposite sign to the previous one
        if ((i < size &&
             (list[i] > 0 && list[i - 1] < 0) ||
             (list[i] < 0 && list[i - 1] > 0))) {
            ++cur_sz;
        }

        // if the above condition isn't met, check if the current sequence is
        // longer than the longest one then replace the longest one if needed
        else {
            if (cur_sz > ans_sz) {
                ans = cur_ans;
                ans_sz = cur_sz;
            }
            // resets the current sequence
            cur_ans = list + i;
            cur_sz = 1;
        }
    }

    return std::make_pair(ans, ans_sz);
}

std::pair<int *, int> mountainSequence(int *list, int size) {
    // ans stores the longest sequence, ans_sz stores its size
    // cur_ans stores the current sequence we are working with, similarly,
    // cur_sz stores its size
    int *ans, *cur_ans = list;
    int ans_sz = 0, cur_sz = 1;
    bool descending = false;

    for (int i = 1; i <= size; ++i) {
        // if we didn't pass through the whole array, check if the current
        // sequence respects the mountain form: increasing then decreasing
        if (i < size &&
            (!descending || (descending && list[i] < list[i - 1]))) {
            if (!descending && list[i] < list[i - 1]) {
                descending = true;
            }
            ++cur_sz;
        }

        // if the above condition isn't met, check if the current sequence is
        // longer than the longest one then replace the longest one if needed
        else {
            if (cur_sz > ans_sz) {
                ans = cur_ans;
                ans_sz = cur_sz;
            }
            // resets the current sequence
            cur_ans = list + (i - 1);
            cur_sz = 2;
            descending = false;
        }
    }

    return std::make_pair(ans, ans_sz);
}
