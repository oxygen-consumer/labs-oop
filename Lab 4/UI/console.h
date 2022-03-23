//
// Created by zaha on 3/22/22.
//

#include "../Domain/complex_num.h"

#ifndef LAB_4_CONSOLE_H
#define LAB_4_CONSOLE_H

/**
 * Prints console menu options
 */
void print_menu();

/**
 * Runs the console
 * @param list a list of complex numbers
 * @param size items in the list
 */
void run_menu(complex_num *list, int &size);

#endif //LAB_4_CONSOLE_H
