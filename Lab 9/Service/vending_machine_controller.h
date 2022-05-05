//
// Created by zaha on 5/5/22.
//

#include "../Domain/Product/product.h"
#include "../Domain/Banknote/banknote.h"
#include "../Repository/repo_interface.h"
#include "../Repository/repo_in_memory.h"

#ifndef LAB_9_VENDING_MACHINE_CONTROLLER_H
#define LAB_9_VENDING_MACHINE_CONTROLLER_H

// TODO: implement and handle exceptions

class vending_machine_controller {
private:
    repo_in_memory<product> prepo_type;
    repo_interface<product> *products_repo;
    repo_in_memory<banknote> brepo_type;
    repo_interface<banknote> *banknotes_repo;

    std::vector<banknote> get_change(std::vector<banknote> input);

public:
    vending_machine_controller();

    ~vending_machine_controller() = default;

    std::vector<int> buy_product(int id, std::vector<int> input);

    void add_product(int id, int code, std::string name, double price, int quantity);

    void add_banknote(int id, double value, int quantity);

    void remove_product(int id);

    void remove_banknote(int id);

    void update_product(int id, int code, std::string name, double price, int quantity);

    void update_banknote(int id, double value, int quantity);

    std::vector<product> get_products();

    std::vector<banknote> get_banknotes();

    std::vector<int> get_accepted_banknote_values();
};


#endif //LAB_9_VENDING_MACHINE_CONTROLLER_H
