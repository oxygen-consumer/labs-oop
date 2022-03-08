//
// Created by zaha on 3/8/22.
//

#include "read_show.h"
#include <iostream>

void read(int *list, int &size) {
    std::cout << "Lungimea șirului: ";
    std::cin >> size;

    if (size)
        std::cout << "Elementele șirului: ";
    for (int i = 0; i < size; ++i)
        std::cin >> list[i];
}

void show(int *list, int size) {
    if (!size)
        std::cout << "*sunete de greier*\n";
    else {
        for (int i = 0; i < size; ++i)
            std::cout << list[i] << " ";
        std::cout << "\n";
    }
}
