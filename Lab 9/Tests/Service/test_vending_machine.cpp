//
// Created by zaha on 5/9/22.
//

#include "test_vending_machine.h"

void test_vending_machine::run_tests() {
    test_vending_machine_service();
}

void test_vending_machine::test_vending_machine_service() {
    repo_in_memory<product> prepo;
    repo_in_memory<banknote> brepo;
    repo_interface<product> &products_repo = prepo;
    repo_interface<banknote> &banknotes_repo = brepo;
    vending_machine_service serv(products_repo, banknotes_repo);

    // test add product
    serv.add_product(1, 1, "product 1", 10, 10);
    serv.add_product(2, 1, "product 2", 20, 20);
    serv.add_product(3, 1, "product 3", 30, 30);
    serv.add_product(4, 1, "product 4", 40, 40);

    // test add banknote
    serv.add_banknote(1, 5, 10);
    serv.add_banknote(2, 10, 20);
    serv.add_banknote(3, 20, 30);
    serv.add_banknote(4, 50, 50);

    // test get products
    std::vector<product> products = serv.get_products();
    assert(products.size() == 4);
    assert(products[0].get_id() == 1);
    assert(products[0].get_price() == 10);
    assert(products[0].get_quantity() == 10);
    assert(products[0].get_name() == "product 1");
    assert(products[1].get_id() == 2);
    assert(products[1].get_price() == 20);
    assert(products[1].get_quantity() == 20);
    assert(products[1].get_name() == "product 2");
    assert(products[2].get_id() == 3);
    assert(products[2].get_price() == 30);
    assert(products[2].get_quantity() == 30);
    assert(products[2].get_name() == "product 3");
    assert(products[3].get_id() == 4);
    assert(products[3].get_price() == 40);
    assert(products[3].get_quantity() == 40);
    assert(products[3].get_name() == "product 4");

    // test get banknotes
    std::vector<banknote> banknotes = serv.get_banknotes();
    assert(banknotes.size() == 4);
    assert(banknotes[0].get_id() == 1);
    assert(banknotes[0].get_value() == 5);
    assert(banknotes[0].get_quantity() == 10);
    assert(banknotes[1].get_id() == 2);
    assert(banknotes[1].get_value() == 10);
    assert(banknotes[1].get_quantity() == 20);
    assert(banknotes[2].get_id() == 3);
    assert(banknotes[2].get_value() == 20);
    assert(banknotes[2].get_quantity() == 30);
    assert(banknotes[3].get_id() == 4);
    assert(banknotes[3].get_value() == 50);
    assert(banknotes[3].get_quantity() == 50);

    // test get product
    product product = serv.get_product(1);
    assert(product.get_id() == 1);
    assert(product.get_price() == 10);
    assert(product.get_quantity() == 10);
    assert(product.get_name() == "product 1");

    // test update product
    serv.update_product(1, 1, "product 1", 10, 10);
    product = serv.get_product(1);
    assert(product.get_id() == 1);
    assert(product.get_price() == 10);
    assert(product.get_quantity() == 10);
    assert(product.get_name() == "product 1");

    // test buy product
    std::vector<double> inpt = {10};
    std::vector<double> outpt = serv.buy_product(1, inpt);
    assert(outpt.size() == 0);

    // test remove banknote
    serv.remove_banknote(1);
    serv.remove_banknote(2);
    serv.remove_banknote(3);
    serv.remove_banknote(4);

    // test remove product
    serv.remove_product(1);
    serv.remove_product(2);
    serv.remove_product(3);
    serv.remove_product(4);
}
