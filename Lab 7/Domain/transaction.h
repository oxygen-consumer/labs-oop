//
// Created by zaha on 4/3/22.
//

#include <string>
#include <cstring>
#include <sstream>
#include <ostream>

#ifndef LAB_7_ENTITY_H
#define LAB_7_ENTITY_H

// TODO: make a validator class

class transaction {
private:
    unsigned int id;
    int value;
    char *description;
    unsigned int day;
public:
    /**
     * @brief Construct a new transaction object without initializing it
     */
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
                         const char *description, bool is_income, unsigned int day);

    /**
     * @brief Destroy the transaction object
     */
    ~transaction();

    /**
     * @brief Copy constructor
     * @param rhs
     */
    transaction(const transaction &rhs);

    /**
     * @brief Get the id of the transaction
     * @return
     */
    [[nodiscard]] unsigned int get_id() const;

    /**
     * @brief Construct a string representation of the transaction
     * @return the string representation of the transaction
     */
    [[nodiscard]] std::string to_string() const;

    /**
     * @brief Get the value of the transaction
     * @return the value of the transaction
     */
    [[nodiscard]] int get_value() const;

    /**
     * @brief Get the description of the transaction
     * @return the description of the transaction
     */
    [[nodiscard]] char *get_description();

    /**
     * @brief Get the type of the transaction
     * @return the type of the transaction
     */
    [[nodiscard]] bool get_type() const;

    /**
     * @brief Get the day of the transaction
     * @return the day of the transaction
     */
    [[nodiscard]] unsigned int get_day() const;

    /**
     * @brief Check if the transaction is income
     * @return true if the transaction is income, false otherwise
     */
    [[nodiscard]] bool is_in() const;

    /**
     * @brief Set the id of the transaction
     * @param i the id of the transaction
     */
    [[maybe_unused]] void set_id(unsigned int i);

    /**
     * @brief Set the value of the transaction
     * @param val the value of the transaction
     */
    [[maybe_unused]] void set_value(unsigned int val);

    /**
     * @brief Set the description of the transaction
     * @param description the description of the transaction
     */
    [[maybe_unused]] void set_description(const char *description);

    /**
     * @brief Set the type of the transaction
     * @param is_income the type of the transaction, true if income, false otherwise
     */
    [[maybe_unused]] void set_type(bool is_income);

    /**
     * @brief Set the day of the transaction
     * @param d the day of the transaction
     */
    [[maybe_unused]] void set_day(unsigned int d);

    /**
     * @brief Overload the assignment operator
     * @param rhs the transaction to copy
     * @return the transaction
     */
    transaction &operator=(const transaction &rhs);

    /**
     * @brief Overload of the == operator
     * @param rhs the transaction to compare with
     * @return true if the transactions are equal, false otherwise
     */
    bool operator==(const transaction &rhs) const;

    /**
     * @brief Overload the << operator to print the transaction
     * @param os the output stream
     * @param transaction the transaction to print
     * @return the output stream
     */
    friend std::ostream &
    operator<<(std::ostream &os, const transaction &transaction);

    /**
     * @brief Overload of the != operator
     * @param rhs the transaction to compare with
     * @return true if the transactions are not equal, false otherwise
     */
    bool operator!=(const transaction &rhs) const;

    /**
     * @brief Overload of the < operator
     * @param rhs the transaction to compare with
     * @return true if the transaction is less than the other, false otherwise
     */
    bool operator<(const transaction &rhs) const;

    /**
     * @brief Overload of the > operator
     * @param rhs the transaction to compare with
     * @return true if the transaction is greater than the other, false otherwise
     */
    bool operator>(const transaction &rhs) const;

    /**
     * @brief Overload of the <= operator
     * @param rhs the transaction to compare with
     * @return true if the transaction is less than or equal to the other, false otherwise
     */
    bool operator<=(const transaction &rhs) const;

    /**
     * @brief Overload of the >= operator
     * @param rhs the transaction to compare with
     * @return true if the transaction is greater than or equal to the other, false otherwise
     */
    bool operator>=(const transaction &rhs) const;
};


#endif //LAB_7_ENTITY_H
