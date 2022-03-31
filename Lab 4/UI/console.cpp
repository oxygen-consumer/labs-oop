//
// Created by zaha on 3/22/22.
//

#include "console.h"
#include <iostream>

void print_menu() {
    std::cout << "1. Adaugare entitate\n";
    std::cout << "2. Afisarea tuturor entitatilor\n";
    std::cout << "3. Afisarea celei mai mari entitati\n";
    std::cout << "4. Afisarea entitatilor aflate in primul cadran\n";
    std::cout << "5. Afisarea celei mai lungi secvente de entitati egale\n";
    std::cout << "x. Iesire\n";
}

void show_queue(std::queue<complex_num> q) {
    while (!q.empty()) {
        std::cout << q.front().to_str() << " ";
        q.pop();
    }
    std::cout << "\n";
}

void add_number(numbers &repo) {
    complex_num num;
    num.read_from_stdin();
    repo.add(num);
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
                add_number(repo);
                break;
            }
            case '2': {
                show_queue(repo.get_all());
                break;
            }
            case '3': {
                std::cout << repo.get_biggest().to_str() << "\n";
                break;
            }
            case '4': {
                show_queue(repo.get_all_in_first_quadrant());
                break;
            }
            case '5': {
                show_queue(repo.get_longest_equal_sequence());
                break;
            }
            default: {
                std::cout << "Optiune invalida!\n";
            }
        }
    }
}

