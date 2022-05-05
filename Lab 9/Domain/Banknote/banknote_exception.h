//
// Created by zaha on 5/5/22.
//

#ifndef LAB_9_BANKNOTE_EXCEPTION_H
#define LAB_9_BANKNOTE_EXCEPTION_H


class banknote_exception : public std::exception {
private:
    std::string message;
public:
    explicit banknote_exception(std::string message) : message(
            std::move(message)) {}

    const char *what() const noexcept override {
        return message.c_str();
    }
};


#endif //LAB_9_BANKNOTE_EXCEPTION_H
