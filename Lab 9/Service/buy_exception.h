//
// Created by zaha on 5/5/22.
//

#include <string>
#include <exception>
#include <utility>

#ifndef LAB_9_BUY_EXCEPTION_H
#define LAB_9_BUY_EXCEPTION_H


class buy_exception : public std::exception {
private:
    std::string message;
public:
    explicit buy_exception(std::string message) : message(
            std::move(message)) {}

    const char *what() const noexcept override {
        return message.c_str();
    }
};


#endif //LAB_9_BUY_EXCEPTION_H
