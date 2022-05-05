//
// Created by zaha on 5/5/22.
//

#include <string>
#include <ostream>
#include <istream>
#include <limits>

#ifndef LAB_9_BANKNOTE_H
#define LAB_9_BANKNOTE_H


class banknote {
private:
    int id;
    double value;
    int quantity;
public:
    banknote();

    banknote(int id, double value, int quantity);

    banknote(const banknote &rhs);

    ~banknote();

    int get_id() const;

    void set_id(int new_id);

    double get_value() const;

    void set_value(double new_value);

    int get_quantity() const;

    void set_quantity(int new_quantity);

    bool operator==(const banknote &rhs) const;

    bool operator!=(const banknote &rhs) const;

    bool operator<(const banknote &rhs) const;

    bool operator>(const banknote &rhs) const;

    bool operator<=(const banknote &rhs) const;

    bool operator>=(const banknote &rhs) const;

    banknote &operator=(const banknote &rhs);

    friend std::ostream &operator<<(std::ostream &os, const banknote &banknote);

    friend std::istream &operator>>(std::istream &is, banknote &banknote);
};


#endif //LAB_9_BANKNOTE_H
