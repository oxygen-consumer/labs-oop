//
// Created by zaha on 3/22/22.
//

#include "../Domain/complex_num.h"
#include "../Repository/repository_in_memory.h"

#ifndef LAB_4_CONSOLE_H
#define LAB_4_CONSOLE_H

/**
 * Prints console menu options
 */
void print_menu();

/**
 * Runs the console
 * @param repo Repository to store complex numbers
 */
void run_menu(numbers repo);

/**
 * Print a queue of complex numbers to stdout
 * @param q the queue to print
 */
void show_queue(std::queue<complex_num> q);

/**
 * Adds a complex number to the repository
 * @param repo Repository to store complex numbers
 */
void add_number(numbers &repo);

#endif //LAB_4_CONSOLE_H
