//
// Created by zaha on 3/3/22.
//

#include "read_show.h"
#include <iostream>

void readArray(int *list, int &size) {
    std::cout << "Lungimea șirului: ";
    std::cin >> size;

    if (size > 0) {
        std::cout << "Elementele șirului: ";
    } else {
        std::cout << "Lista a fost golita.\n";
    }
    for (int i = 0; i < size; ++i) {
        std::cin >> list[i];
    }
}

void showArray(int *list, int size) {
    if (size <= 0) {
        std::cout << "*sunete de greier*\n";
    } else {
        for (int i = 0; i < size; ++i) {
            std::cout << list[i] << " ";
        }
        std::cout << "\n";
    }
}