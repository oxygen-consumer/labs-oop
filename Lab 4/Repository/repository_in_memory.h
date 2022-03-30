//
// Created by zaha on 3/24/22.
//

#include <queue>
#include "../Domain/complex_num.h"

#ifndef LAB_4_REPOSITORY_IN_MEMORY_H
#define LAB_4_REPOSITORY_IN_MEMORY_H

class numbers {
private:
    std::queue<complex_num> storage;

public:
    numbers();
    ~numbers();

    /**
     * Get an complex number from a given position in the repository
     * @param pos the position
     * @return the complex number found or complex_num(0, 0) if position is invalid
     */
    complex_num get(int pos);

    /**
     * Adds an complex_num to repository
     * @param num the number to be added
     * @return the position of the new element
     */
    int add(complex_num num);

    /**
     * Get all numbers from repository
     * @return a queue containing all numbers
     */
    std::queue<complex_num> get_all();

    /**
     * Compare all numbers from repository and return the biggest one
     * @return the biggest number
     */
    complex_num get_biggest();

    /**
     * Get all numbers situated in the first quadrant
     * @return a queue containing the numbers in the first quadrant
     */
    std::queue<complex_num> get_all_in_first_quadrant();

    /**
     * Get the longest sequence containing only equal numbers
     * @return a queue containing the longest sequence
     */
    std::queue<complex_num> get_longest_equal_sequence();
};

#endif //LAB_4_REPOSITORY_IN_MEMORY_H
