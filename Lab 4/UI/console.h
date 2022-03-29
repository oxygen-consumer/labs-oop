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

#endif //LAB_4_CONSOLE_H
