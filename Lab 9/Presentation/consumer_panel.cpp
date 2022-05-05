//
// Created by zaha on 5/5/22.
//

#include "consumer_panel.h"

void consumer_panel::print_menu() {
    std::cout << "=== Consumer Panel ===" << std::endl;
    std::cout << "1. List products" << std::endl;
    std::cout << "2. Buy product" << std::endl;
    std::cout << "3. Show accepted banknote values" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

void consumer_panel::run() {
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
                buy_product();
                break;
            }
            case 3: {
                show_accepted_banknote_values();
                break;
            }
            case 4: {
                running = false;
                break;
            }
            default: {
                std::cout << "Invalid input" << std::endl;
                break;
            }
        }
    }
}

void consumer_panel::list_products() {
    // TODO: Implement after implementing controller
}

void consumer_panel::buy_product() {
    std::cout << "Enter the product ID: ";
    std::string input;
    std::cin >> input;
    int product_id;
    try {
        product_id = std::stoi(input);
    } catch (...) {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    // TODO: Implement after implementing controller
}

void consumer_panel::show_accepted_banknote_values() {
    // TODO: Implement after implementing controller
}
