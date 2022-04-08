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

    // TODO: implement efficient undo/redo
    std::stack<vector<T>> undoStack;
    std::stack<vector<T>> redoStack;

public:
    /**
     * @brief Construct a new repository object
     */
    repository() = default;

    /**
     * @brief Destroy the repository object
     */
    ~repository() = default;

    /**
     * @brief Add an entity to the repository
     * @param e The entity to be added
     */
    void add(T e) {
        undoStack.push(entities);
        redoStack = std::stack<vector<T>>(); //empty the redo stack

        entities.push_back(e);
    }

    /**
     * @brief Remove an entity from the repository
     * @param e The entity to be removed
     */
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

    /**
     * @brief Update an entity in the repository
     * @param index The index of the entity to be updated
     * @param e The new entity
     */
    void update(unsigned int index, T e) {
        undoStack.push(entities);
        redoStack = std::stack<vector<T>>(); //empty the redo stack

        this->entities.remove(index);
        this->entities.insert(index, e);
    }

    /**
     * @brief Get the entities
     * @return The entities
     */
    vector<T> get_all() {
        return this->entities;
    }

    /**
     * @brief Undo the last operation
     * @return True if the operation was successful, false otherwise
     */
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

    /**
     * @brief Redo the last operation
     * @return True if the operation was successful, false otherwise
     */
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

    /**
     * @brief Remove multiple entities from the repository
     * @param e The entities to be removed
     */
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

    /**
     * @brief Get the size of the repository
     * @return the size of the repository
     */
    unsigned int size() {
        return this->entities.size();
    }
};


#endif //LAB_7_REPO_H
