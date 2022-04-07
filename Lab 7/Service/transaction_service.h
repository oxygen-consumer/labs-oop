//
// Created by zaha on 4/3/22.
//

#include <set>
#include <string>
#include <queue>
#include <cstring>
#include "../Repository/repository.h"
#include "../Domain/transaction.h"

#ifndef LAB_7_SERVICE_H
#define LAB_7_SERVICE_H


class transaction_service {
private:
    repository<transaction> repo;
    unsigned int next_id = 1;

    std::queue<transaction> get_by_property(std::queue<std::string> filters);

public:
    transaction_service();

    ~transaction_service();

    void add_transaction(int value, const std::string &type,
                         const std::string &description,
                         int day);

    void delete_transaction(int id);

    void update_transaction(int id, int value, const std::string &type,
                            const std::string &description, int day);

    std::queue<transaction>
    get_transactions(const std::string &type, std::queue<std::string> filters);

    transaction get_transaction(int id);

    void filter_transactions(std::queue<std::string> filters);

    int get_balance_of_the_day(int day);

    void undo();

    void redo();
};


#endif //LAB_7_SERVICE_H
