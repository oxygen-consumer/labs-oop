//
// Created by zaha on 4/19/22.
//

#include <string>
#include <ostream>
#include <istream>

#ifndef LAB_9_PRODUCT_H
#define LAB_9_PRODUCT_H


class product {
private:
    int id;
    int code;
    std::string name;
    int price;
    int quantity;

public:
    product();

    product(int id, int code, std::string name, int price, int quantity);

    product(const product &rhs);

    ~product();

    int get_id() const;

    int get_code() const;

    std::string get_name() const;

    int get_price() const;

    int get_quantity() const;

    void set_id(int new_id);

    void set_code(int new_code);

    void set_name(std::string new_name);

    void set_price(int new_price);

    void set_quantity(int new_quantity);

    bool operator==(const product &rhs) const;

    bool operator!=(const product &rhs) const;

    product &operator=(const product &rhs);

    friend std::ostream &operator<<(std::ostream &os, const product &product);

    friend std::istream &operator>>(std::istream &is, product &product);
};


#endif //LAB_9_PRODUCT_H
