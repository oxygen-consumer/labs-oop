//
// Created by zaha on 3/3/22.
//

#include "console.h"
#include "../io_operations/read_show.h"
#include "../../Service/problems/problems.h"
#include <iostream>

/**
 * Prints menu options.
 */
void printMenu() {
    std::cout << "\n1. Citire lista\n";
    std::cout << "2. Afisare lista\n";
    // mi lene sa scriu tot enunțul
    std::cout << "3. Cea mai lunga secventa cu proprietatea 8\n";
    std::cout << "4. Cea mai lunga secventa cu proprietatea 11\n";
    std::cout << "x. Iesire\n";
}

void runMenu(int *list, int &size) {
    bool shouldRun = true;

    while (shouldRun) {
        printMenu();
        char option;
        std::pair<int *, int> ans;
        std::cout << "\nIntroduceti optiunea: ";
        std::cin >> option;

        switch (option) {
            case 'x':
                shouldRun = false;
                break;
            case '1':
                read(list, size);
                break;
            case '2':
                show(list, size);
                break;
            case '3':
                ans = problem8(list, size);
                show(ans.first, ans.second);
                break;
            case '4':
                ans = problem11(list, size);
                show(ans.first, ans.second);
                break;
            default:
                std::cout << "\nOptiune inexistenta.\n";
                break;
        }
    }
}