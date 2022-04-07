//
// Created by zaha on 4/3/22.
//

#include <string>
#include <sstream>
#include <ostream>

#ifndef LAB_7_ENTITY_H
#define LAB_7_ENTITY_H


class transaction {
private:
    unsigned int id;
    int value;
    char *description;
    unsigned int day;
public:
    transaction();

    /**
     * @brief Construct a new transaction object
     * @param id the id of the transaction
     * @param value the value of the transaction
     * @param description the description of the transaction
     * @param is_income the type of the transaction
     * @param day the day of the transaction
     */
    explicit transaction(unsigned int id, int value,
                         char *description, bool is_income, unsigned int day);

    ~transaction();

    transaction(const transaction &rhs);

    [[nodiscard]] unsigned int get_id() const;

    [[nodiscard]] std::string to_string() const;

    [[nodiscard]] unsigned int get_value() const;

    [[nodiscard]] char *get_description() const;

    [[nodiscard]] bool get_type() const;

    [[nodiscard]] unsigned int get_day() const;

    [[nodiscard]] bool is_in() const;

    [[maybe_unused]] void set_id(unsigned int i);

    [[maybe_unused]] void set_value(unsigned int val);

    [[maybe_unused]] void set_description(char *description);

    [[maybe_unused]] void set_type(bool is_income);

    [[maybe_unused]] void set_day(unsigned int d);

    transaction &operator=(const transaction &rhs);

    bool operator==(const transaction &rhs) const;

    friend std::ostream &
    operator<<(std::ostream &os, const transaction &transaction);

    bool operator!=(const transaction &rhs) const;

    bool operator<(const transaction &rhs) const;

    bool operator>(const transaction &rhs) const;

    bool operator<=(const transaction &rhs) const;

    bool operator>=(const transaction &rhs) const;
};


#endif //LAB_7_ENTITY_H
