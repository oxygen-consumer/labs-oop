//
// Created by zaha on 5/4/22.
//

#include <vector>
#include "repo_interface.h"

#ifndef LAB_9_VECTOR_REPO_H
#define LAB_9_VECTOR_REPO_H


template<class T>
class repo_in_memory : public repo_interface<T> {
private:
    std::vector<T> data;
public:
    repo_in_memory() = default;

    ~repo_in_memory() = default;

    void add(T obj) override {
        data.push_back(obj);
    }

    void remove(T obj) override {
        for (auto it = data.begin(); it != data.end(); it++) {
            if (*it == obj) {
                data.erase(it);
                break;
            }
        }
    }

    void update(T obj) override {
        for (auto it = data.begin(); it != data.end(); it++) {
            if (*it == obj) {
                *it = obj;
                break;
            }
        }
    }

    std::vector<T> get_all() override {
        return data;
    }

    T get_by_id(int id) override {
        for (auto it = data.begin(); it != data.end(); it++) {
            if ((*it).get_id() == id) {
                return *it;
            }
        }
        return T();
    }

    int size() override {
        return data.size();
    }
};


#endif //LAB_9_VECTOR_REPO_H
