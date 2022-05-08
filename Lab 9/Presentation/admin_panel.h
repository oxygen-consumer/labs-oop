//
// Created by zaha on 5/5/22.
//

#include <iostream>
#include "../Service/vending_machine_service.h"

#ifndef LAB_9_ADMIN_PANEL_H
#define LAB_9_ADMIN_PANEL_H


class admin_panel {
private:
    vending_machine_service &serv;

    static void print_menu();

    void list_products();

    void list_banknotes();

    void add_product();

    void add_banknote();

    void remove_product();

    void remove_banknote();

    void edit_product();

    void edit_banknote();

    void show_accepted_banknote_values();

public:
    explicit admin_panel(vending_machine_service &serv) : serv(serv) {}

    ~admin_panel() = default;

    void run();
};


#endif //LAB_9_ADMIN_PANEL_H
