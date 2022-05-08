//
// Created by zaha on 5/5/22.
//

#include <iostream>
#include "admin_panel.h"
#include "consumer_panel.h"
#include "../Service/vending_machine_service.h"

#ifndef LAB_9_USER_INTERFACE_H
#define LAB_9_USER_INTERFACE_H


class user_interface {
private:
    vending_machine_service &serv;

    void run_admin_menu();

    void run_consumer_menu();

public:
    explicit user_interface(vending_machine_service &serv) : serv(serv) {}

    ~user_interface() = default;

    void run();
};


#endif //LAB_9_USER_INTERFACE_H
