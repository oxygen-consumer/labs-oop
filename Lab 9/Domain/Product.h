//
// Created by zaha on 4/19/22.
//

#include <string>

#ifndef LAB_9_PRODUCT_H
#define LAB_9_PRODUCT_H


class Product {
private:
    int id;
    int code;
    std::string name;
    int price;

public:
    Product();
    Product(int id, int code, std::string name, int price);
    Product(const Product &product);
    ~Product();

    int getId() const;
    int getCode() const;
    std::string getName() const;
    int getPrice() const;

    void setId(int id);
    void setCode(int code);
    void setName(std::string name);
    void setPrice(int price);

    Product &operator=(const Product &product);
    bool operator==(const Product &product);
    bool operator!=(const Product &product);

    std::string toString();
};


#endif //LAB_9_PRODUCT_H
