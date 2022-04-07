//
// Created by zaha on 4/7/22.
//

#include "../Domain/vector.h"

#ifndef LAB_7_LIVE_REPOSITORY_H
#define LAB_7_LIVE_REPOSITORY_H


template<class T>
class repository {
private:
    vector<T> elems;
public:
    repository() {
        this->elems = vector<T>();
    }

    ~repository() = default;

    void add(T elem) {
        elems.push_back(elem);
    }

    vector<T> get_all() {
        return elems;
    }

    int size() {
        return elems.size();
    }

    void remove(int index) {
        elems.remove(index);
    }
};


#endif //LAB_7_LIVE_REPOSITORY_H
