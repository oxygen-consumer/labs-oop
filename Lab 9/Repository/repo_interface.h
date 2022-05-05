//
// Created by zaha on 5/4/22.
//

#include <vector>

#ifndef LAB_9_REPO_INTERFACE_H
#define LAB_9_REPO_INTERFACE_H


template<class T>
class repo_interface {
public:
    virtual void add(T) = 0;

    virtual void remove(T) = 0;

    virtual void update(T) = 0;

    virtual std::vector<T> get_all() = 0;

    virtual T get_by_id(int) = 0;

    virtual int size() = 0;
};


#endif //LAB_9_REPO_INTERFACE_H
