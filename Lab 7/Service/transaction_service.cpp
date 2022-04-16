//
// Created by zaha on 4/3/22.
//

#include "transaction_service.h"

transaction_service::transaction_service() = default;

std::queue<transaction>
transaction_service::get_by_property(std::queue<std::string> filters) {
    if (filters.size() & 1) { // The number of filters must be even
        throw std::invalid_argument("Invalid property");
    }

    vector<transaction> transactions = repo.get_all();

    while (!filters.empty()) {
        std::string property, argument;
        property = std::move(filters.front());
        filters.pop();
        argument = std::move(filters.front());
        filters.pop();
        std::pair<std::string, std::string> condition = std::make_pair(
                property, argument);

        for (int i = 0; i < transactions.size(); i++) {
            if (!(transaction_condition::check_match(transactions[i],
                                                     condition))) {
                transactions.remove(i);
            }
        }
    }

    std::queue<transaction> result;
    for (int i = 0; i < transactions.size(); i++) {
        result.push(transactions[i]);
    }
    return result;

}

void transaction_service::add_transaction(int value, const std::string &type,
                                          const std::string &description,
                                          int day) {
    transaction_validator::validate(day, type, value);

    bool is_in = type == "in";

    transaction t(next_id, value, description.c_str(), is_in, (unsigned int) day);
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
    transaction_validator::validate(day, type, value);

    bool is_in = type == "in";

    transaction t(id, value, description.c_str(), is_in, (unsigned int) day);

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

unsigned int transaction_service::get_current_id() const {
    return this->next_id;
}

transaction_service::~transaction_service() = default;