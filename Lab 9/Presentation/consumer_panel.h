//
// Created by zaha on 5/5/22.
//

#include <iostream>
#include <sstream>
#include "../Service/vending_machine_service.h"

#ifndef LAB_9_CONSUMER_PANEL_H
#define LAB_9_CONSUMER_PANEL_H


class consumer_panel {
private:
    vending_machine_service &serv;

    static void print_menu();

    void list_products();

    void buy_product();

    void show_accepted_banknote_values();

public:
    explicit consumer_panel(vending_machine_service &serv) : serv(serv) {}

    ~consumer_panel() = default;

    void run();
};


#endif //LAB_9_CONSUMER_PANEL_H
