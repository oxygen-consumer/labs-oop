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
    std::cout << "6. Show accepted banknote values" << std::endl;
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

void admin_panel::list_products() {
    std::vector<product> products = controller.get_products();
    for (const auto& product : products) {
        std:: cout << product << std::endl;
    }
}

void admin_panel::list_banknotes() {
    std::vector<banknote> banknotes = controller.get_banknotes();
    for (const auto& banknote : banknotes) {
        std:: cout << banknote << std::endl;
    }
}

void admin_panel::add_product() {
    int id;
    int code;
    std::string name;
    double price;
    int quantity;

    try {
        std::cout << "Enter product id: ";
        std::cin >> id;
        std::cout << "Enter product code: ";
        std::cin >> code;
        std::cout << "Enter product name: ";
        std::cin >> name;
        std::cout << "Enter product price: ";
        std::cin >> price;
        std::cout << "Enter product quantity: ";
        std::cin >> quantity;
    } catch (...) {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    controller.add_product(id, code, name, price, quantity);
}

void admin_panel::add_banknote() {
    int id;
    int value;
    int quantity;

    try {
        std::cout << "Enter banknote id: ";
        std::cin >> id;
        std::cout << "Enter banknote value: ";
        std::cin >> value;
        std::cout << "Enter banknote quantity: ";
        std::cin >> quantity;
    } catch (...) {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    controller.add_banknote(id, value, quantity);
}

void admin_panel::remove_product() {
    int id;
    try {
        std::cout << "Enter product id: ";
        std::cin >> id;
    } catch (...) {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    controller.remove_product(id);
}

void admin_panel::remove_banknote() {
    int id;
    try {
        std::cout << "Enter banknote id: ";
        std::cin >> id;
    } catch (...) {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    controller.remove_banknote(id);
}

void admin_panel::edit_product() {
    int id;
    int code;
    std::string name;
    double price;
    int quantity;

    try {
        std::cout << "Enter product id: ";
        std::cin >> id;
        std::cout << "Enter product code: ";
        std::cin >> code;
        std::cout << "Enter product name: ";
        std::cin >> name;
        std::cout << "Enter product price: ";
        std::cin >> price;
        std::cout << "Enter product quantity: ";
        std::cin >> quantity;
    } catch (...) {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    controller.update_product(id, code, name, price, quantity);
}

void admin_panel::edit_banknote() {
    int id;
    int value;
    int quantity;

    try {
        std::cout << "Enter banknote id: ";
        std::cin >> id;
        std::cout << "Enter banknote value: ";
        std::cin >> value;
        std::cout << "Enter banknote quantity: ";
        std::cin >> quantity;
    } catch (...) {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    controller.update_banknote(id, value, quantity);
}

void admin_panel::show_accepted_banknote_values() {
    std::vector<int> banknotes = controller.get_accepted_banknote_values();
    std::cout << "Accepted banknotes: " << std::endl;
    for (auto& banknote : banknotes) {
        std::cout << banknote << " ";
    }
}
