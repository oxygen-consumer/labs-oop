//
// Created by zaha on 4/3/22.
//

#include "transaction_service.h"

#include <utility>

transaction_service::transaction_service() = default;

std::queue<transaction>
transaction_service::get_by_property(std::queue<std::string> filters) {
    std::queue<transaction> ans;
    vector<transaction> transactions = this->repo.get_all();

    bool desc = false;
    char *desc_arg;
    bool type = false;
    bool type_arg;
    bool day = false;
    int day_arg;
    bool smaller = false;
    int smaller_arg;
    bool bigger = false;
    int bigger_arg;
    bool equal = false;
    int equal_arg;

    while (!filters.empty()) {
        std::string filter = filters.front();
        filters.pop();
        if (filter == "desc") {
            desc = true;
            desc_arg = new char[filters.front().length() + 1];
            strcpy(desc_arg, filters.front().c_str());
            filters.pop();
        } else if (filter == "type") {
            type = true;
            std::string type_arg_str = filters.front();
            if (type_arg_str == "in") {
                type_arg = true;
            } else if (type_arg_str == "out") {
                type_arg = false;
            } else {
                throw std::invalid_argument("Invalid type argument");
            }
            filters.pop();
        } else if (filter == "day") {
            day = true;
            day_arg = std::stoi(filters.front());
            if (day_arg < 1 || day_arg > 31) {
                throw std::invalid_argument("Invalid day argument");
            }
            filters.pop();
        } else if (filter == "smaller") {
            smaller = true;
            smaller_arg = std::stoi(filters.front());
            filters.pop();
        } else if (filter == "bigger") {
            bigger = true;
            bigger_arg = std::stoi(filters.front());
            filters.pop();
        } else if (filter == "equal") {
            equal = true;
            equal_arg = std::stoi(filters.front());
            filters.pop();
        } else {
            throw std::invalid_argument("Invalid property");
        }
    }

    for (int i = 0; i < transactions.size(); i++) {
        if (desc) {
            if (transactions[i].get_description() != desc_arg) {
                continue;
            }
        }
        if (type) {
            if (transactions[i].get_type() != type_arg) {
                continue;
            }
        }
        if (day) {
            if (transactions[i].get_day() != day_arg) {
                continue;
            }
        }
        if (smaller) {
            if (transactions[i].get_value() >= smaller_arg) {
                continue;
            }
        }
        if (bigger) {
            if (transactions[i].get_value() <= bigger_arg) {
                continue;
            }
        }
        if (equal) {
            if (transactions[i].get_value() == equal_arg) {
                continue;
            }
        }
        ans.push(transactions[i]);
    }

    return ans;
}

void transaction_service::add_transaction(int value, const std::string &type,
                                          const std::string &description,
                                          int day) {
    if (type != "in" && type != "out") {
        throw std::invalid_argument("Invalid type");
    }

    if (value <= 0) {
        throw std::invalid_argument("Invalid value");
    }

    if (day < 1 || day > 31) {
        throw std::invalid_argument("Invalid day");
    }

    bool is_in = type == "in";
    char *cstr = new char[description.length() + 1];
    std::strcpy(cstr, description.c_str());
    transaction t(next_id, value, cstr, is_in, (unsigned int) day);
    this->repo.add(t);
    this->next_id++;
}

void transaction_service::delete_transaction(int id) {
    vector<transaction> transactions = repo.get_all();
    for (int i = 0; i < transactions.size(); i++) {
        if (transactions[i].get_id() == id) {
            repo.remove(transactions[i]);
            return;
        }
    }

    throw std::invalid_argument("Invalid id");
}

void
transaction_service::update_transaction(int id, int value,
                                        const std::string &type,
                                        const std::string &description,
                                        int day) {
    if (type != "in" && type != "out") {
        throw std::invalid_argument("Invalid type");
    }

    if (value <= 0) {
        throw std::invalid_argument("Invalid value");
    }

    if (day < 1 || day > 31) {
        throw std::invalid_argument("Invalid day");
    }

    bool is_in = type == "in";
    char *cstr = new char[description.length() + 1];
    std::strcpy(cstr, description.c_str());
    transaction t(id, value, cstr, is_in, (unsigned int) day);

    vector<transaction> transactions = repo.get_all();
    for (int i = 0; i < transactions.size(); i++) {
        if (transactions[i].get_id() == id) {
            repo.update(i, t);
            return;
        }
    }

    throw std::invalid_argument("Invalid id");
}

std::queue<transaction>
transaction_service::get_transactions(
        std::queue<std::string> filters) {
    std::queue<transaction> transactions = get_by_property(std::move(filters));

    if (transactions.empty()) {
        throw std::invalid_argument("No transactions found");
    }

    return transactions;
}

transaction transaction_service::get_transaction(int id) {
    vector<transaction> transactions = repo.get_all();
    for (int i = 0; i < transactions.size(); i++) {
        if (transactions[i].get_id() == id) {
            return transactions[i];
        }
    }

    throw std::invalid_argument("Invalid id");
}

void
transaction_service::filter_transactions(std::queue<std::string> filters) {
    std::queue<transaction> transactions = get_by_property(std::move(filters));
    vector<transaction> all = repo.get_all();

    if (transactions.empty()) {
        throw std::invalid_argument("No transactions found");
    }

    // TODO: Optimize this, currently it is O(n^2)
    vector<transaction> to_remove;
    for (int i = 0; i < all.size(); i++) {
        bool found = false;
        for (int j = 0; j < transactions.size(); j++) {
            if (all[i].get_id() == transactions.front().get_id()) {
                found = true;
                break;
            }
            transactions.push(transactions.front());
            transactions.pop();
        }
        if (!found) {
            to_remove.push_back(all[i]);
        }
    }

    repo.mass_remove(to_remove);
}

int transaction_service::get_balance_of_the_day(int day) {
    vector<transaction> transactions = repo.get_all();
    int balance = 0;
    for (int i = 0; i < transactions.size(); i++) {
        if (transactions[i].get_day() == day) {
            if (transactions[i].is_in()) {
                balance += (int) transactions[i].get_value();
            } else {
                balance -= (int) transactions[i].get_value();
            }
        }
    }

    return balance;
}

void transaction_service::undo() {
    if (!repo.undo()) {
        throw std::invalid_argument("No more transactions to undo");
    }
}

void transaction_service::redo() {
    if (!repo.redo()) {
        throw std::invalid_argument("No more transactions to redo");
    }
}

transaction
transaction_service::get_min_transaction(std::queue<std::string> filters) {
    std::queue<transaction> transactions = get_by_property(std::move(filters));

    if (transactions.empty()) {
        throw std::invalid_argument("No transactions found");
    }

    transaction min = transactions.front();
    while (!transactions.empty()) {
        if (transactions.front().get_value() < min.get_value()) {
            min = transactions.front();
        }
        transactions.pop();
    }

    return min;
}

transaction
transaction_service::get_max_transaction(std::queue<std::string> filters) {
    std::queue<transaction> transactions = get_by_property(std::move(filters));

    if (transactions.empty()) {
        throw std::invalid_argument("No transactions found");
    }

    transaction max = transactions.front();
    while (!transactions.empty()) {
        if (transactions.front().get_value() > max.get_value()) {
            max = transactions.front();
        }
        transactions.pop();
    }

    return max;
}

int
transaction_service::get_sum_of_transactions(std::queue<std::string> filters) {
    std::queue<transaction> transactions = get_by_property(std::move(filters));

    if (transactions.empty()) {
        throw std::invalid_argument("No transactions found");
    }

    int sum = 0;
    while (!transactions.empty()) {
        sum += (int) transactions.front().get_value() *
               (transactions.front().is_in() ? 1 : -1);
        transactions.pop();
    }

    return sum;
}

void transaction_service::clear_transactions(std::queue<std::string> filters) {
    std::queue<transaction> transactions = get_by_property(std::move(filters));

    if (transactions.empty()) {
        throw std::invalid_argument("No transactions found");
    }

    vector<transaction> v;
    while (!transactions.empty()) {
        v.push_back(transactions.front());
        transactions.pop();
    }

    repo.mass_remove(v);
}

transaction_service::~transaction_service() = default;