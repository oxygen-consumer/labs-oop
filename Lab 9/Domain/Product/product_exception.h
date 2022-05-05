//
// Created by zaha on 5/5/22.
//

#ifndef LAB_9_PRODUCT_EXCEPTION_H
#define LAB_9_PRODUCT_EXCEPTION_H


class product_exception : public std::exception {
private:
    std::string message;
public:
    explicit product_exception(std::string message) : message(
            std::move(message)) {}

    const char *what() const noexcept override {
        return message.c_str();
    }
};


#endif //LAB_9_PRODUCT_EXCEPTION_H
