//
// Created by zaha on 4/3/22.
//

#include <stack>

#include "../Domain/vector.h"

#ifndef LAB_7_REPO_H
#define LAB_7_REPO_H


template<class T>
class repository {
private:
    vector<T> entities;

    // HACK: this is very inefficient, but it works for now
    std::stack<vector<T>> undoStack;
    std::stack<vector<T>> redoStack;

public:
    repository() = default;

    ~repository() = default;

    void add(T e) {
        undoStack.push(entities);
        redoStack = std::stack<vector<T>>(); //empty the redo stack

        entities.push_back(e);
    }

    void remove(T e) {
        undoStack.push(entities);

        for (int i = 0; i < this->entities.size(); i++) {
            if (this->entities[i] == e) {
                this->entities.remove(i);
                break;
            }
        }

        redoStack = std::stack<vector<T>>(); //empty the redo stack
    }

    void update(unsigned int index, T e) {
        undoStack.push(entities);
        redoStack = std::stack<vector<T>>(); //empty the redo stack

        this->entities.remove(index);
        this->entities.insert(index, e);
    }

    vector<T> get_all() {
        return this->entities;
    }

    bool undo() {
        if (this->undoStack.empty()) {
            return false;
        }

        vector<T> temp = this->undoStack.top();
        this->undoStack.pop();
        this->redoStack.push(temp);

        this->entities = temp;

        return true;
    }

    bool redo() {
        if (this->redoStack.empty()) {
            return false;
        }

        vector<T> temp = this->redoStack.top();
        this->redoStack.pop();
        this->undoStack.push(temp);

        this->entities = temp;

        return true;
    }

    void mass_remove(vector<T> e) {
        undoStack.push(this->entities);
        redoStack = std::stack<vector<T>>(); //empty the redo stack

        for (int i = 0; i < e.size(); i++) {
            for (int j = 0; j < this->entities.size(); j++) {
                if (this->entities[j] == e[i]) {
                    this->entities.remove(j);
                    break;
                }
            }
        }
    }

    unsigned int size() {
        return this->entities.size();
    }
};


#endif //LAB_7_REPO_H
