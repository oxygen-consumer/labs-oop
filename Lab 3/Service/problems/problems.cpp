//
// Created by zaha on 3/8/22.
//

#include "problems.h"
#include <utility>

std::pair<int *, int> problem8(int *list, int size) {
    int *ans, *cur_ans = list;
    int ans_sz = 0, cur_sz = 1;


    for (int i = 1; i <= size; ++i) {
        if ((i < size &&
             (list[i] > 0 && list[i - 1] < 0) ||
             (list[i] < 0 && list[i - 1] > 0)))
            ++cur_sz;
        else {
            if (cur_sz > ans_sz) {
                ans = cur_ans;
                ans_sz = cur_sz;
            }
            cur_ans = list + i;
            cur_sz = 1;
        }
    }

    return std::make_pair(ans, ans_sz);
}

std::pair<int *, int> problem11(int *list, int size) {
    int *ans, *cur_ans = list;
    int ans_sz = 0, cur_sz = 1;
    bool descending = false;

    for (int i = 1; i <= size; ++i) {
        if (i < size &&
            (!descending || (descending && list[i] < list[i - 1]))) {
            if (!descending && list[i] < list[i - 1])
                descending = true;
            ++cur_sz;
        } else {
            if (cur_sz > ans_sz) {
                ans = cur_ans;
                ans_sz = cur_sz;
            }
            cur_ans = list + (i - 1);
            cur_sz = 2;
            descending = false;
        }
    }

    return std::make_pair(ans, ans_sz);
}
