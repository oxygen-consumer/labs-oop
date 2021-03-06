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
    std::vector<product> products = serv.get_products();
    for (const auto& product : products) {
        std::cout << product;
    }
}

void consumer_panel::buy_product() {
    std::cout << "Enter the product code: ";
    std::string input;
    std::cin >> input;
    int product_code;
    try {
        product_code = std::stoi(input);
    } catch (...) {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    double price;
    try {
        price = serv.get_product(product_code).get_price();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return;
    }

    double money_inserted = 0;
    std::vector<double> banknotes;
    try {
        while (money_inserted < price) {
            std::cout << "You need to add " << price - money_inserted
                      << " RON more"
                      << std::endl;
            std::cout << "Enter the amount of money inserted: ";
            std::cin >> input;
            money_inserted += std::stod(input);
            banknotes.push_back(std::stod(input));
        }
    }
    catch (...) {
        std::cout << "Invalid input" << std::endl;
        std::cout << "You got your money back" << std::endl;
        return;
    }

    try {
        std::vector<double> change = serv.buy_product(product_code, banknotes);
        std::cout << "Change: ";
        for (const auto& banknote : change) {
            std::cout << banknote << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        std::cout << "You got your money back" << std::endl;
    }
}

void consumer_panel::show_accepted_banknote_values() {
    std::vector<double> banknotes = serv.get_accepted_banknote_values();
    std::cout << "Accepted banknotes: ";
    for (const auto& banknote : banknotes) {
        std::cout << banknote << " ";
    }
    std::cout << std::endl;
}
