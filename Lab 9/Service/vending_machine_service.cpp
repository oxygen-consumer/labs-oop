//
// Created by zaha on 5/5/22.
//

#include "vending_machine_service.h"

std::vector<double>
vending_machine_service::get_change(const std::vector<double> &input,
                                    double price) {
    double given_money = 0;
    for (auto &money: input) {
        given_money += money;
    }

    // add given money to the vending machine
    for (auto &money: input) {
        for (auto &banknote: this->banknotes_repo.get_all()) {
            if (double_compare::equal(banknote.get_value(), money)) {
                update_banknote(banknote.get_id(), banknote.get_value(),
                                banknote.get_quantity() + 1);
            }
        }
    }

    std::vector<double> change;
    double change_money = given_money - price;
    while (double_compare::greater(change_money, 0)) {
        // TODO: banknotes are sorted from highest to lowest in repository, should implement a sorting algorithm in repository
        for (auto &banknote: this->banknotes_repo.get_all()) {
            while (double_compare::greater_or_equal(change_money,
                                                    banknote.get_value()) &&
                   banknote.get_quantity() > 0) {
                // add banknote to change
                change.push_back(banknote.get_value());
                change_money -= banknote.get_value();

                // update banknote quantity
                update_banknote(banknote.get_id(), banknote.get_value(),
                                banknote.get_quantity() - 1);
                banknote.set_quantity(banknote.get_quantity() - 1);
            }
        }
    }

    // check if the change is enough
    if (double_compare::greater(change_money, 0)) {
        // add change back to the vending machine
        for (auto &money: change) {
            for (auto &banknote: this->banknotes_repo.get_all()) {
                if (double_compare::equal(banknote.get_value(), money)) {
                    update_banknote(banknote.get_id(), banknote.get_value(),
                                    banknote.get_quantity() + 1);
                }
            }
        }

        // remove given money from the vending machine
        for (auto &money: input) {
            for (auto &banknote: this->banknotes_repo.get_all()) {
                if (double_compare::equal(banknote.get_value(), money)) {
                    update_banknote(banknote.get_id(), banknote.get_value(),
                                    banknote.get_quantity() - 1);
                }
            }
        }

        throw buy_exception("Not enough money to give change");
    }

    return change;
}

std::vector<double>
vending_machine_service::buy_product(int id,
                                     const std::vector<double> &input) {
    for (auto &i: input) {
        if (!(bv.is_valid(i))) {
            throw banknote_exception("Invalid banknote");
        }
    }

    product p = products_repo.get_by_id(id);
    std::vector<double> change = get_change(input, p.get_price());
    update_product(p.get_id(), p.get_code(), p.get_name(), p.get_price(),
                   p.get_quantity() - 1);
    return change;
}

void
vending_machine_service::add_product(int id, int code, std::string name,
                                     double price, int quantity) {
    bool ok = true;
    for (auto &i: products_repo.get_all()) {
        if (i.get_id() == id) {
            ok = false;
        }
    }
    if (!ok) {
        throw product_exception("Product already exists");
    }
    product prod(id, code, std::move(name), price, quantity);
    if (product_validator::is_valid(prod)) {
        products_repo.add(prod);
    } else {
        throw product_exception("Invalid product");
    }
}

void
vending_machine_service::add_banknote(int id, double value, int quantity) {
    bool ok = true;
    for (auto &i: banknotes_repo.get_all()) {
        if (i.get_id() == id) {
            ok = false;
        }
    }
    if (!ok) {
        throw banknote_exception("Banknote already exists");
    }

    banknote bn(id, value, quantity);
    if (bv.is_valid(bn)) {
        banknotes_repo.add(bn);
    } else {
        throw banknote_exception("Invalid banknote");
    }
}

void vending_machine_service::remove_product(int id) {
    std::vector<product> products = this->products_repo.get_all();
    for (auto &product: products) {
        if (product.get_id() == id) {
            this->products_repo.remove(product);
            return;
        }
    }

    throw product_exception("Product not found");
}

void vending_machine_service::remove_banknote(int id) {
    std::vector<banknote> banknotes = this->banknotes_repo.get_all();
    for (auto &banknote: banknotes) {
        if (banknote.get_id() == id) {
            this->banknotes_repo.remove(banknote);
            return;
        }
    }

    throw banknote_exception("Banknote does not exist");
}

void
vending_machine_service::update_product(int id, int code, std::string name,
                                        double price, int quantity) {
    bool ok = false;
    for (auto &i: this->products_repo.get_all()) {
        if (i.get_id() == id) {
            ok = true;
            break;
        }
    }
    if (!ok) {
        throw product_exception("The product does not exist");
    }

    product prod(id, code, std::move(name), price, quantity);
    if (product_validator::is_valid(prod)) {
        this->products_repo.update(prod);
    } else {
        throw product_exception("Invalid product");
    }
}

void vending_machine_service::update_banknote(int id, double value,
                                              int quantity) {
    bool ok = false;
    for (auto &i: this->banknotes_repo.get_all()) {
        if (i.get_id() == id) {
            ok = true;
            break;
        }
    }
    if (!ok) {
        throw banknote_exception("The banknote does not exist");
    }

    banknote bn(id, value, quantity);
    if (bv.is_valid(bn)) {
        this->banknotes_repo.update(bn);
    } else {
        throw banknote_exception("Invalid banknote");
    }
}

std::vector<product> vending_machine_service::get_products() {
    return this->products_repo.get_all();
}

std::vector<banknote> vending_machine_service::get_banknotes() {
    return this->banknotes_repo.get_all();
}

std::vector<double>
vending_machine_service::get_accepted_banknote_values() {
    return bv.get_accepted_banknotes();
}

product vending_machine_service::get_product(int id) {
    std::vector<product> products = this->products_repo.get_all();

    for (auto &product: products) {
        if (product.get_id() == id) {
            return product;
        }
    }

    throw product_exception("Product not found");
}
