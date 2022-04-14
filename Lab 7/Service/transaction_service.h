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

    /**
     * @brief Get the transactions corresponding to the given filters
     * @param filters The filters to be used
     * @return The transactions corresponding to the given filters
     */
    std::queue<transaction> get_by_property(std::queue<std::string> filters);

public:
    /**
     * @brief Construct a new transaction service object
     */
    transaction_service();

    /**
     * @brief Destroy the transaction service object
     */
    ~transaction_service();

    /**
     * @brief Add a new transaction to the repository
     *
     * @param value The value of the transaction
     * @param type The type of the transaction
     * @param description The description of the transaction
     * @param day The day of the transaction
     */
    void add_transaction(int value, const std::string &type,
                         const std::string &description,
                         int day);

    /**
     * @brief Remove a transaction from the repository
     * @param id The id of the transaction to remove
     */
    void delete_transaction(int id);

    /**
     * @brief Update a transaction in the repository
     * @param id The id of the transaction to update
     * @param value The new value of the transaction
     * @param type The new type of the transaction
     * @param description The new description of the transaction
     * @param day The new day of the transaction
     */
    void update_transaction(int id, int value, const std::string &type,
                            const std::string &description, int day);

    /**
     * @brief Get all transactions from the repository corresponding to the given filters
     * @param filters The filters to apply
     * @return The transactions corresponding to the given filters
     */
    std::queue<transaction>
    get_transactions(std::queue<std::string> filters);

    /**
     * @brief Get a transaction from the repository corresponding to the given id
     * @param id The id of the transaction to get
     * @return The transaction corresponding to the given id
     */
    transaction get_transaction(int id);

    /**
     * @brief Remove all transactions from the repository not corresponding to the given filters
     * @param filters The filters to apply
     */
    void filter_transactions(std::queue<std::string> filters);

    /**
     * @brief Get the balance of the transactions from a given day
     * @param day The day of the transactions
     * @return The balance of the transactions
     */
    int get_balance_of_the_day(int day);

    /**
     * @brief Undo the last operation
     */
    void undo();

    /**
     * @brief Redo the last operation
     */
    void redo();

    /**
     * @brief Get the smallest transaction corresponding to the given filters
     * @param filters The filters to apply
     * @return The smallest transaction corresponding to the given filters
     */
    transaction get_min_transaction(std::queue<std::string> filters);

    /**
     * @brief Get the biggest transaction corresponding to the given filters
     * @param filters The filters to apply
     * @return The biggest transaction corresponding to the given filters
     */
    transaction get_max_transaction(std::queue<std::string> filters);

    /**
     * @brief Get the sum of the transactions corresponding to the given filters
     * @param filters The filters to apply
     * @return The sum of the transactions corresponding to the given filters
     */
    int get_sum_of_transactions(std::queue<std::string> filters);

    /**
     * @brief Remove all transactions corresponding to the given filters
     * @param filters The filters to apply
     */
    void clear_transactions(std::queue<std::string> filters);

    /**
     * @brief Get the next id to use
     * @return The next id to use
     */
    unsigned int get_current_id();

};


#endif //LAB_7_SERVICE_H
