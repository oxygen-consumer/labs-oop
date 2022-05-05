//
// Created by zaha on 5/5/22.
//

#include "admin_panel.h"

void admin_panel::print_menu() {
    std::cout << "=== Admin Panel ===" << std::endl;
    std::cout << "1. List products" << std::endl;
    std::cout << "2. Add product" << std::endl;
    std::cout << "3. Remove product" << std::endl;
    std::cout << "4. Edit product" << std::endl;
    std::cout << "5. List banknotes" << std::endl;
    std::cout << "6. Show accepted bankote values" << std::endl;
    std::cout << "7. Add banknote" << std::endl;
    std::cout << "8. Remove banknote" << std::endl;
    std::cout << "9. Edit banknote" << std::endl;
    std::cout << "10. Exit" << std::endl;
}

void admin_panel::run() {
    bool running = true;

    while (running) {
        print_menu();

        std::cout << "> ";
        std::string input;
        int choice;
        std::cin >> input;
        try {
            choice = std::stoi(input);
        } catch (...) {
            std::cout << "Invalid input" << std::endl;
            continue;
        }

        switch (choice) {
            case 1: {
                list_products();
                break;
            }
            case 2: {
                add_product();
                break;
            }
            case 3: {
                remove_product();
                break;
            }
            case 4: {
                edit_product();
                break;
            }
            case 5: {
                list_banknotes();
                break;
            }
            case 6: {
                show_accepted_banknote_values();
                break;
            }
            case 7: {
                add_banknote();
                break;
            }
            case 8: {
                remove_banknote();
                break;
            }
            case 9: {
                edit_banknote();
                break;
            }
            case 10: {
                running = false;
                break;
            }
        }
    }
}

// TODO: Implement the following functions after implementing controller

void admin_panel::list_products() {

}

void admin_panel::list_banknotes() {

}

void admin_panel::add_product() {

}

void admin_panel::add_banknote() {

}

void admin_panel::remove_product() {

}

void admin_panel::remove_banknote() {

}

void admin_panel::edit_product() {

}

void admin_panel::edit_banknote() {

}

void admin_panel::show_accepted_banknote_values() {

}
