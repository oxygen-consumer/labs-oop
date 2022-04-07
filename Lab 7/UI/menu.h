//
// Created by zaha on 4/3/22.
//

#include <iostream>
#include <string>
#include "../Service/transaction_service.h"

#ifndef LAB_7_MENU_H
#define LAB_7_MENU_H


class menu {
private:
    transaction_service serv;

    static void print_menu();

    static void print_property_arguments();

    void add_command(const std::string &command);

    void remove_command(const std::string &command);

    void get_command(const std::string &command);

    void list_command(const std::string &command);

    void update_command(const std::string &command);

    void filter_command(const std::string &command);

    void sol_command(const std::string &command);

    void undo_command();

    void redo_command();

public:
    menu();

    ~menu();

    void start();

};


#endif //LAB_7_MENU_H
