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

void run_menu(numbers repo) {
    bool should_run = true;
    
    while (should_run) {
        print_menu();
        char option;
        std::cout << "> ";
        std::cin >> option;

        switch (option) {
            case 'x': {
                should_run = false;
                break;
            }
            case '1': {
                complex_num num;
                num.read_from_stdin();
                repo.add(num);
                break;
            }
            case '2': {
                std::queue<complex_num> q = repo.get_all();
                while (!q.empty()) {
                    std::cout << q.front().to_str() << "\n";
                    q.pop();
                }
                break;
            }
            default: {
                std::cout << "Optiune invalida!\n";
            }
        }
    }
}
