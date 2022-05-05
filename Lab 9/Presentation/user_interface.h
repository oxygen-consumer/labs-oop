//
// Created by zaha on 5/5/22.
//

#include <iostream>
#include "admin_panel.h"
#include "consumer_panel.h"

#ifndef LAB_9_USER_INTERFACE_H
#define LAB_9_USER_INTERFACE_H


class user_interface {
private:
    static void run_admin_menu();

    static void run_consumer_menu();

public:
    static void run();
};


#endif //LAB_9_USER_INTERFACE_H
