//
// Created by zaha on 3/5/22.
//

#ifndef LAB_2_PROBLEMS_H
#define LAB_2_PROBLEMS_H

#include <utility>

/**
 * Get the longest sequence in which consecutive elements have opposite signs.
 * Complexity: linear, O(size)
 * @param list an array
 * @param size array length
 * @return pair of a pointer to the start of the longest sequence with above
 * propriety and it's size
 */
std::pair<int *, int> oppositeSignsSequence(int *list, int size);

/**
 * Get the longest sequence with a mountain form (the elements are increasing,
 * then decreasing).
 * Complexity: linear, O(size)
 * @param list an array
 * @param size array length
 * @return pair of a pointer to the start of the longest sequence with above
 * propriety and it's size
 */
std::pair<int *, int> mountainSequence(int *list, int size);

#endif //LAB_2_PROBLEMS_H
