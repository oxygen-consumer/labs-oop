//
// Created by zaha on 5/5/22.
//

#include "vending_machine_controller.h"

std::vector<double>
vending_machine_controller::get_change(const std::vector<double> &input,
                                       double given_money) {
    std::vector<banknote> banknotes = banknotes_repo->get_all();

    //sort banknotes descending
    std::sort(banknotes.begin(), banknotes.end(),
              [](const banknote &a, const banknote &b) {
                  return a.get_value() > b.get_value();
              });

    std::vector<double> change;
    double change_sum = 0;
    for (auto &i: input) {
        for (auto &j: banknotes) {
            if (j.get_value() == i) {
                update_banknote(j.get_id(), i, j.get_quantity() + 1);
            }
        }
    }

    while (change_sum < given_money) {
        for (auto &i: banknotes) {
            if (i.get_value() <= given_money - change_sum) {
                change_sum += i.get_value();
                change.push_back(i.get_value());
                update_banknote(i.get_id(), i.get_value(),
                                i.get_quantity() - 1);
            }
        }
    }

    if (change_sum < given_money) {
        for (auto &i: change) {
            for (auto &j: banknotes) {
                if (j.get_value() == i) {
                    update_banknote(j.get_id(), i, j.get_quantity() + 1);
                }
            }
        }

        for (auto &i: input) {
            for (auto &j: banknotes) {
                if (j.get_value() == i) {
                    update_banknote(j.get_id(), i, j.get_quantity() - 1);
                }
            }
        }

        throw buy_exception(
                "The vending machine does not have enough money");
    }

    return change;
}

std::vector<double>
vending_machine_controller::buy_product(int id,
                                        const std::vector<double> &input) {
    for (auto &i: input) {
        if (!(bv.is_valid(i))) {
            throw banknote_exception("Invalid banknote");
        }
    }

    product p = products_repo->get_by_id(id);
    double given_money = 0;
    for (auto &i: input) {
        given_money += i;
    }

    return get_change(input, given_money - p.get_price());
}

void
vending_machine_controller::add_product(int id, int code, std::string name,
                                        double price, int quantity) {
    bool ok = true;
    for (auto &i: products_repo->get_all()) {
        if (i.get_id() == id) {
            ok = false;
        }
    }
    if (!ok) {
        throw product_exception("Product already exists");
    }
    product prod(id, code, std::move(name), price, quantity);
    if (product_validator::is_valid(prod)) {
        products_repo->add(prod);
    } else {
        throw product_exception("Invalid product");
    }
}

void
vending_machine_controller::add_banknote(int id, double value, int quantity) {
    bool ok = true;
    for (auto &i: banknotes_repo->get_all()) {
        if (i.get_id() == id) {
            ok = false;
        }
    }
    if (!ok) {
        throw banknote_exception("Banknote already exists");
    }

    banknote bn(id, value, quantity);
    if (bv.is_valid(bn)) {
        banknotes_repo->add(bn);
    } else {
        throw banknote_exception("Invalid banknote");
    }
}

void vending_machine_controller::remove_product(int id) {
    std::vector<product> products = this->products_repo->get_all();
    for (auto &product: products) {
        if (product.get_id() == id) {
            this->products_repo->remove(product);
            return;
        }
    }

    throw product_exception("Product not found");
}

void vending_machine_controller::remove_banknote(int id) {
    std::vector<banknote> banknotes = this->banknotes_repo->get_all();
    for (auto &banknote: banknotes) {
        if (banknote.get_id() == id) {
            this->banknotes_repo->remove(banknote);
            return;
        }
    }

    throw banknote_exception("Banknote does not exist");
}

void
vending_machine_controller::update_product(int id, int code, std::string name,
                                           double price, int quantity) {
    bool ok = false;
    for (auto &i: this->products_repo->get_all()) {
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
        this->products_repo->update(prod);
    } else {
        throw product_exception("Invalid product");
    }
}

void vending_machine_controller::update_banknote(int id, double value,
                                                 int quantity) {
    bool ok = false;
    for (auto &i: this->banknotes_repo->get_all()) {
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
        this->banknotes_repo->update(bn);
    } else {
        throw banknote_exception("Invalid banknote");
    }
}

std::vector<product> vending_machine_controller::get_products() {
    return this->products_repo->get_all();
}

std::vector<banknote> vending_machine_controller::get_banknotes() {
    return this->banknotes_repo->get_all();
}

std::vector<double>
vending_machine_controller::get_accepted_banknote_values() {
    return bv.get_accepted_banknotes();
}

product vending_machine_controller::get_product(int id) {
    std::vector<product> products = this->products_repo->get_all();

    for (auto &product: products) {
        if (product.get_id() == id) {
            return product;
        }
    }

    throw product_exception("Product not found");
}

vending_machine_controller::~vending_machine_controller() {
    delete this->products_repo;
    delete this->banknotes_repo;
}
