//
// Created by zaha on 5/5/22.
//

#include <algorithm>
#include "double_compare.h"
#include "../Domain/Product/product.h"
#include "../Domain/Banknote/banknote.h"
#include "../Domain/Product/product_exception.h"
#include "../Domain/Banknote/banknote_exception.h"
#include "../Domain/Product/product_validator.h"
#include "../Domain/Banknote/banknote_validator.h"
#include "../Repository/repo_interface.h"
#include "../Repository/repo_in_memory.h"
#include "../Repository/repo_in_file.h"
#include "buy_exception.h"

#ifndef LAB_9_VENDING_MACHINE_CONTROLLER_H
#define LAB_9_VENDING_MACHINE_CONTROLLER_H

class vending_machine_service {
private:
    repo_interface<product> *products_repo;
    repo_interface<banknote> *banknotes_repo;

    banknote_validator bv;

    std::vector<double>
    get_change(const std::vector<double> &input, double price);

public:
    vending_machine_service(repo_interface<product> *products_repo,
                            repo_interface<banknote> *banknotes_repo);

    ~vending_machine_service();

    std::vector<double> buy_product(int id, const std::vector<double> &input);

    void add_product(int id, int code, std::string name, double price,
                     int quantity);

    void add_banknote(int id, double value, int quantity);

    void remove_product(int id);

    void remove_banknote(int id);

    void update_product(int id, int code, std::string name, double price,
                        int quantity);

    void update_banknote(int id, double value, int quantity);

    std::vector<product> get_products();

    product get_product(int id);

    std::vector<banknote> get_banknotes();

    std::vector<double> get_accepted_banknote_values();
};


#endif //LAB_9_VENDING_MACHINE_CONTROLLER_H
