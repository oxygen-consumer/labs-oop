//
// Created by zaha on 4/19/22.
//

#include <vector>

#ifndef LAB_9_REPO_H
#define LAB_9_REPO_H


template <class T>
class Repo {
private:
    std::vector<T> elems;
public:
    Repo() = default;

    ~Repo() = default;

    void addElem(T elem) {
        elems.push_back(elem);
    }

    void delElem(T elem) {
        for (auto it = elems.begin(); it != elems.end(); it++) {
            if (*it == elem) {
                elems.erase(it);
                break;
            }
        }
    }

    void updateElem(T elem) {
        for (auto it = elems.begin(); it != elems.end(); it++) {
            if (*it == elem) {
                elems.erase(it);
                elems.push_back(elem);
                break;
            }
        }
    }

    std::vector<T> getAll() {
        return elems;
    }

    int getSize() {
        return elems.size();
    }
};


#endif //LAB_9_REPO_H
