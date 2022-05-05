//
// Created by zaha on 5/5/22.
//

#include "vending_machine_controller.h"

#include <utility>

vending_machine_controller::vending_machine_controller() {
    this->products_repo = &prepo_type;
    this->banknotes_repo = &brepo_type;
}

std::vector<banknote>
vending_machine_controller::get_change(std::vector<banknote> input) {
    return std::vector<banknote>();
}

std::vector<int>
vending_machine_controller::buy_product(int id, std::vector<int> input) {
    return std::vector<int>();
}

void
vending_machine_controller::add_product(int id, int code, std::string name,
                                        double price, int quantity) {
    product prod(id, code, std::move(name), price, quantity);
    this->products_repo->add(prod);
}

void
vending_machine_controller::add_banknote(int id, double value, int quantity) {
    banknote bn(id, value, quantity);
    this->banknotes_repo->add(bn);
}

void vending_machine_controller::remove_product(int id) {
    std::vector<product> products = this->products_repo->get_all();
    for (auto& product : products) {
        if (product.get_id() == id) {
            this->products_repo->remove(product);
            return;
        }
    }
}

void vending_machine_controller::remove_banknote(int id) {
    std::vector<banknote> banknotes = this->banknotes_repo->get_all();
    for (auto& banknote : banknotes) {
        if (banknote.get_id() == id) {
            this->banknotes_repo->remove(banknote);
            return;
        }
    }
}

void
vending_machine_controller::update_product(int id, int code, std::string name,
                                           double price, int quantity) {
    product prod(id, code, std::move(name), price, quantity);
    this->products_repo->update(prod);
}

void vending_machine_controller::update_banknote(int id, double value,
                                                 int quantity) {
    banknote bn(id, value, quantity);
    this->banknotes_repo->update(bn);
}

std::vector <product> vending_machine_controller::get_products() {
    return this->products_repo->get_all();
}

std::vector <banknote> vending_machine_controller::get_banknotes() {
    return this->banknotes_repo->get_all();
}

std::vector<int> vending_machine_controller::get_accepted_banknote_values() {
    return std::vector<int>();
}
