//
// Created by zaha on 5/5/22.
//

#include <string>
#include <fstream>
#include "repo_interface.h"

#ifndef LAB_9_REPO_IN_FILE_H
#define LAB_9_REPO_IN_FILE_H


template<class T>
class repo_in_file : public repo_interface<T> {
private:
    std::string file_name;
    std::vector<T> data;

    void read_from_file() {
        std::ifstream file(file_name);
        T t;
        while (file >> t) {
            data.push_back(t);
        }
        file.close();
    }

    void write_to_file() {
        std::ofstream file(file_name);
        for (auto t: data) {
            file << t << std::endl;
        }
        file.close();
    }

public:
    explicit repo_in_file(const std::string &file_name) {
        this->file_name = file_name;
        read_from_file();
    }

    ~repo_in_file() {
        write_to_file();
    }

    void add(T t) override {
        data.push_back(t);
        write_to_file();
    }

    void remove(T t) override {
        data.erase(std::remove(data.begin(), data.end(), t));
        write_to_file();
    }

    void update(T t) override {
        for (auto &elem: data) {
            if (elem == t) {
                elem = t;
                write_to_file();
                return;
            }
        }
    }

    std::vector<T> get_all() override {
        return data;
    }

    T get_by_id(int id) override {
        for (auto &elem: data) {
            if (elem.get_id() == id) {
                return elem;
            }
        }
        return T();
    }

    int size() override {
        return data.size();
    }
};


#endif //LAB_9_REPO_IN_FILE_H
