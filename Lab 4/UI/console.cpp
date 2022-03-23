//
// Created by zaha on 3/22/22.
//

#include "console.h"
#include <iostream>

void print_menu() {
    std::cout << "1. Adaugare entitate\n";
    std::cout << "2. Afisarea tuturor entitatilor\n";
    std::cout << "x. Iesire\n";
}

void run_menu(complex_num *list, int &size) {
    bool should_run = true;
    
    while (should_run) {
        print_menu();
        char option;
        std::cout << "> ";
        std::cin >> option;

        switch (option) {
            case 'x':
                should_run = false;
                break;
            case '1':
                list[size].read_from_stdin();
                ++size;
                break;
            case '2':
                for (int i = 0; i < size; ++i) {
                    std::cout << list[i].to_str() << "\n";
                }
                break;
            default:
                std::cout << "Optiune invalida!\n";
        }
    }
}
