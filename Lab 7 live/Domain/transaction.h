//
// Created by zaha on 4/7/22.
//

#ifndef LAB_7_LIVE_TRANSACTION_H
#define LAB_7_LIVE_TRANSACTION_H


class transaction {
private:
    int id;

public:
    transaction();

    transaction(int id);

    ~transaction();

    int get_id();

    void set_id(int id);

    bool operator==(const transaction &rhs) const;

    bool operator!=(const transaction &rhs) const;
};


#endif //LAB_7_LIVE_TRANSACTION_H
