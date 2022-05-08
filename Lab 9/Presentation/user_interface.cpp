//
// Created by zaha on 5/5/22.
//

#include "user_interface.h"

void user_interface::run() {
    bool should_continue = true;
    while (should_continue) {
        std::cout << "1. Admin interface" << std::endl;
        std::cout << "2. Consumer interface" << std::endl;
        std::cout << "3. Exit" << std::endl;

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
                run_admin_menu();
                break;
            }
            case 2: {
                run_consumer_menu();
                break;
            }
            case 3: {
                should_continue = false;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    }
}

void user_interface::run_admin_menu() {
    std::string password;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (password == "admin") { //Security at its finest
        admin_panel panel(serv);
        panel.run();
    } else {
        std::cout << "Wrong password" << std::endl;
    }
}

void user_interface::run_consumer_menu() {
    consumer_panel panel(serv);
    panel.run();
}
