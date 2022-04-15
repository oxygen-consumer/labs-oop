//
// Created by zaha on 4/3/22.
//

#include "transaction.h"

transaction::transaction() = default;

transaction::transaction(unsigned int id, int value,
                         const char *description, bool is_income,
                         unsigned int day) {
    this->id = id;
    this->value = std::abs(value) * (is_income ? 1 : -1);
    this->description = new char[strlen(description) + 1];
    std::strcpy(this->description, description);
    this->day = day;
}

transaction::transaction(const transaction &rhs) {
    this->id = rhs.get_id();
    this->value = rhs.value;
    this->description = new char[strlen(rhs.description) + 1];
    std::strcpy(this->description, rhs.description);
    this->day = rhs.day;
}

unsigned int transaction::get_id() const {
    return this->id;
}

bool transaction::operator==(const transaction &rhs) const {
    return id == rhs.id;
}

bool transaction::operator!=(const transaction &rhs) const {
    return !(rhs == *this);
}

std::string transaction::to_string() const {
    std::stringstream ss;
    ss << "id: " << id << "; type: " << (value > 0 ? "in" : "out")
       << "; value: "
       << std::abs(value) << "; description: " << description;
    return ss.str();
}

int transaction::get_value() const {
    return std::abs(this->value);
}

char *transaction::get_description() {
    return this->description;
}

unsigned int transaction::get_day() const {
    return this->day;
}

bool transaction::get_type() const {
    return this->value > 0;
}

bool transaction::operator<(const transaction &rhs) const {
    return value < rhs.value;
}

bool transaction::operator>(const transaction &rhs) const {
    return rhs < *this;
}

bool transaction::operator<=(const transaction &rhs) const {
    return !(rhs < *this);
}

bool transaction::operator>=(const transaction &rhs) const {
    return !(*this < rhs);
}

transaction::~transaction() {
    delete[] description;
    this->description = nullptr;
}

[[maybe_unused]] void transaction::set_id(unsigned int i) {
    this->id = i;
}

[[maybe_unused]] void transaction::set_value(unsigned int val) {
    this->value = (int) (val * (this->value < 0 ? -1 : 1));
}

[[maybe_unused]] void transaction::set_description(const char *desc) {
    delete[] this->description;
    this->description = new char[strlen(desc) + 1];
    std::strcpy(this->description, desc);
}

[[maybe_unused]] void transaction::set_day(unsigned int d) {
    this->day = d;
}

[[maybe_unused]] void transaction::set_type(bool is_income) {
    this->value = (int) (this->value * (is_income ? 1 : -1));
}

transaction &transaction::operator=(const transaction &rhs) {
    if (this != &rhs) {
        this->id = rhs.get_id();
        this->value = rhs.value;
        this->description = new char[strlen(rhs.description) + 1];
        std::strcpy(this->description, rhs.description);
        this->day = rhs.day;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const transaction &transaction) {
    os << transaction.to_string();
    return os;
}

bool transaction::is_in() const {
    return get_type();
}
