//
// Created by zaha on 3/8/22.
//

#include "console.h"
#include "../io_operations/read_show.h"
#include "../../Service/problems/problems.h"
#include <iostream>

void printMenu() {
    std::cout << "\n1. Citire lista\n";
    std::cout << "2. Afisare lista\n";
    // we divide the string to respect Eighty Columns Rule
    std::cout << "3. Cea mai lunga secventa cu proprietatea ca elementele de" \
        "pe poziții consecutive au semne contrare\n";
    std::cout << "4. Cea mai lunga secventa in forma de munte\n";
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
                readArray(list, size);
                break;
            case '2':
                showArray(list, size);
                break;
            case '3':
                ans = oppositeSignsSequence(list, size);
                showArray(ans.first, ans.second);
                break;
            case '4':
                ans = mountainSequence(list, size);
                showArray(ans.first, ans.second);
                break;
            default:
                std::cout << "\nOptiune inexistenta.\n";
                break;
        }
    }
}
