//
// Created by zaha on 4/3/22.
//

#include "menu.h"

menu::menu() = default;

menu::~menu() = default;

void menu::print_menu() {
    std::cout << std::endl;
    std::cout << "help\n\t print this menu" << std::endl;
    std::cout << "exit\n\t exit the program" << std::endl;
    std::cout << std::endl;

    std::cout
            << "add <value> <type> <description> <day>\n\t add a new transaction with the given arguments"
            << std::endl;
    std::cout << "get <id>\n\t get the transaction with the given id"
              << std::endl;
    std::cout
            << "update <id> <value> <type> <description> <day>\n\t update the transaction with the given id"
            << std::endl;
    std::cout
            << "remove <id>\n\t remove the transaction corresponding to the given id"
            << std::endl;
    std::cout << "undo\n\t undo the last transaction" << std::endl;
    std::cout << "redo\n\t redo the last undone transaction" << std::endl;
    std::cout
            << "properties\n\t print the available formats for the property argument"
            << std::endl;
    std::cout
            << "list [propriety]\n\t print the transactions respecting the given property"
            << "\n\tfor the available properties, type properties"
            << std::endl;
    std::cout
            << "filter <propriety>\n\t remove the transactions not respecting the given property"
            << "\n\tfor the available properties, type properties"
            << std::endl;
    std::cout
            << "clear [propriety]\n\t remove the transactions respecting the given property"
            << "\n\tfor the available properties, type properties"
            << std::endl;
    std::cout << "sol <day>\n\t print the balance for the given day"
              << std::endl;
    std::cout
            << "min [propriety]\n\t print the minimum value for the given property"
            << "\n\tfor the available properties, type properties"
            << std::endl;
    std::cout
            << "max [propriety]\n\t print the maximum value for the given property"
            << "\n\tfor the available properties, type properties"
            << std::endl;
    std::cout
            << "sum [propriety]\n\t print the sum of the transactions following the given property"
            << "\n\tfor the available properties, type properties"
            << std::endl;
    std::cout << std::endl;

    std::cout << "<arg> means the argument is required" << std::endl;
    std::cout << "[arg] means the argument is optional" << std::endl;
    std::cout << "arg1|arg2 means at most one of the arguments can be used"
              << std::endl;
    std::cout << std::endl;
}

void menu::print_property_arguments() {
    std::cout << "The following arguments can be combined however you want\n"
              << std::endl;
    std::cout << "desc <description>\n\t description of the transaction"
              << std::endl;
    std::cout << "type <in|out>\n\t type of the transaction" << std::endl;
    std::cout << "day <day>\n\t day of the transaction" << std::endl;
    std::cout
            << "< <value>\n\t transactions with a value less than the given one"
            << std::endl;
    std::cout
            << "> <value>\n\t transactions with a value greater than the given one"
            << std::endl;
    std::cout
            << "= <value>\n\t transactions with a value equal to the given one"
            << std::endl;
    std::cout << "If property is not given, all the transactions are considered"
              << std::endl;
    std::cout << std::endl;
}

void menu::start() {
    std::cout << "Welcome, for a help menu, type help" << std::endl;
    std::string command;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command == "help") {
            print_menu();
        } else if (command == "exit") {
            break;
        } else if (command.find("add") != std::string::npos) {
            add_command(command);
        } else if (command.find("get") != std::string::npos) {
            get_command(command);
        } else if (command.find("update") != std::string::npos) {
            update_command(command);
        } else if (command.find("remove") != std::string::npos) {
            remove_command(command);
        } else if (command == "undo") {
            undo_command();
        } else if (command == "redo") {
            redo_command();
        } else if (command == "properties") {
            print_property_arguments();
        } else if (command.find("list") != std::string::npos) {
            list_command(command);
        } else if (command.find("filter") != std::string::npos) {
            filter_command(command);
        } else if (command.find("sol") != std::string::npos) {
            sol_command(command);
        } else if (command.find("min") != std::string::npos) {
            min_command(command);
        } else if (command.find("max") != std::string::npos) {
            max_command(command);
        } else if (command.find("sum") != std::string::npos) {
            sum_command(command);
        } else if (command.find("clear") != std::string::npos) {
            clear_command(command);
        } else {
            std::cout << "Invalid command" << std::endl;
        }
    }
}

void menu::add_command(const std::string &command) {
    std::stringstream ss(command);
    std::string command_type;
    std::string value;
    std::string type;
    std::string description;
    std::string day;

    ss >> command_type >> value >> type >> description >> day;

    if (command_type == "add") {
        if (value.empty() || type.empty() || description.empty() ||
            day.empty()) {
            std::cout << "Missing arguments" << std::endl;
        } else {
            try {
                serv.add_transaction(stoi(value), type, description,
                                     stoi(day));
                std::cout << "Transaction added" << std::endl;
            } catch (std::invalid_argument &e) {
                std::cout << e.what() << std::endl;
            }
        }
    } else {
        std::cout << "Invalid command" << std::endl;
    }
}

void menu::remove_command(const std::string &command) {
    std::stringstream ss(command);
    std::string command_type;
    std::string id;

    ss >> command_type >> id;

    if (command_type == "remove") {
        if (id.empty()) {
            std::cout << "Missing arguments" << std::endl;
        } else {
            try {
                serv.delete_transaction(stoi(id));
                std::cout << "Transaction removed" << std::endl;
            } catch (std::invalid_argument &e) {
                std::cout << e.what() << std::endl;
            }
        }
    } else {
        std::cout << "Invalid command" << std::endl;
    }
}

void menu::get_command(const std::string &command) {
    std::stringstream ss(command);
    std::string command_type;
    std::string id;

    ss >> command_type >> id;

    if (command_type == "get") {
        if (id.empty()) {
            std::cout << "Missing arguments" << std::endl;
        } else {
            try {
                std::cout << serv.get_transaction(stoi(id)) << std::endl;
            } catch (std::invalid_argument &e) {
                std::cout << e.what() << std::endl;
            }
        }
    } else {
        std::cout << "Invalid command" << std::endl;
    }
}

void menu::list_command(const std::string &command) {
    std::stringstream ss(command);
    std::string command_type;
    std::queue<std::string> filters;
    std::string arg;

    ss >> command_type;
    while (ss >> arg) {
        filters.push(arg);
    }

    if (command_type == "list") {
        try {
            std::queue<transaction> transactions =
                    serv.get_transactions(filters);
            std::cout << "Transactions:" << std::endl;
            while (!transactions.empty()) {
                std::cout << transactions.front() << std::endl;
                transactions.pop();
            }
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
        }
    } else {
        std::cout << "Invalid command" << std::endl;
    }
}

void menu::update_command(const std::string &command) {
    std::stringstream ss(command);
    std::string command_type;
    std::string id;
    std::string value;
    std::string type;
    std::string description;
    std::string day;

    ss >> command_type >> id >> value >> type >> description >> day;

    if (command_type == "update") {
        if (id.empty() || value.empty() || type.empty() ||
            description.empty() ||
            day.empty()) {
            std::cout << "Missing arguments" << std::endl;
        } else {
            try {
                serv.update_transaction(stoi(id), stoi(value), type,
                                        description, stoi(day));
                std::cout << "Transaction updated" << std::endl;
            } catch (std::invalid_argument &e) {
                std::cout << e.what() << std::endl;
            }
        }
    } else {
        std::cout << "Invalid command" << std::endl;
    }
}

void menu::filter_command(const std::string &command) {
    std::stringstream ss(command);
    std::string command_type;
    std::string arg;
    std::queue<std::string> filters;

    ss >> command_type;
    while (ss >> arg) {
        filters.push(arg);
    }

    if (command_type == "filter") {
        if (filters.empty()) {
            std::cout << "Missing arguments" << std::endl;
        } else {
            try {
                serv.filter_transactions(filters);
                std::cout << "Transactions filtered" << std::endl;
            } catch (std::invalid_argument &e) {
                std::cout << e.what() << std::endl;
            }
        }
    } else {
        std::cout << "Invalid command" << std::endl;
    }
}

void menu::sol_command(const std::string &command) {
    std::stringstream ss(command);
    std::string command_type;
    std::string day;

    ss >> command_type >> day;

    if (command_type == "sol") {
        if (day.empty()) {
            std::cout << "Missing arguments" << std::endl;
        } else {
            try {
                std::cout << serv.get_balance_of_the_day(stoi(day)) << std::endl;
            } catch (std::invalid_argument &e) {
                std::cout << e.what() << std::endl;
            }
        }
    } else {
        std::cout << "Invalid command" << std::endl;
    }
}

void menu::undo_command() {
    try {
        serv.undo();
        std::cout << "Undo successful" << std::endl;
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
}

void menu::redo_command() {
    try {
        serv.redo();
        std::cout << "Redo successful" << std::endl;
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
}

void menu::min_command(const std::string &command) {
    std::stringstream ss(command);
    std::string command_type;
    std::queue<std::string> filters;
    std::string arg;

    ss >> command_type;
    while (ss >> arg) {
        filters.push(arg);
    }

    if (command_type == "min") {
        try {
            std::cout << serv.get_min_transaction(filters) << std::endl;
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
        }
    } else {
        std::cout << "Invalid command" << std::endl;
    }
}

void menu::max_command(const std::string &command) {
    std::stringstream ss(command);
    std::string command_type;
    std::queue<std::string> filters;
    std::string arg;

    ss >> command_type;
    while (ss >> arg) {
        filters.push(arg);
    }

    if (command_type == "max") {
        try {
            std::cout << serv.get_max_transaction(filters) << std::endl;
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
        }
    } else {
        std::cout << "Invalid command" << std::endl;
    }
}

void menu::sum_command(const std::string &command) {
    std::stringstream ss(command);
    std::string command_type;
    std::queue<std::string> filters;
    std::string arg;

    ss >> command_type;
    while (ss >> arg) {
        filters.push(arg);
    }

    if (command_type == "sum") {
        try {
            std::cout << serv.get_sum_of_transactions(filters) << std::endl;
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
        }
    } else {
        std::cout << "Invalid command" << std::endl;
    }
}

void menu::clear_command(const std::string &command) {
    std::stringstream ss(command);
    std::string command_type;
    std::queue<std::string> filters;
    std::string arg;

    ss >> command_type;
    while (ss >> arg) {
        filters.push(arg);
    }

    if (command_type == "clear") {
        try {
            serv.clear_transactions(filters);
            std::cout << "Transactions cleared" << std::endl;
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
        }
    } else {
        std::cout << "Invalid command" << std::endl;
    }
}
