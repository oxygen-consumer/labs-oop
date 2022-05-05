//
// Created by zaha on 5/4/22.
//

#include <fstream>
#include <nlohmann/json.hpp>
#include <string>
#include <utility>
#include "repo_interface.h"

#ifndef LAB_9_JSON_VECTOR_H
#define LAB_9_JSON_VECTOR_H


// TODO: this is a bad implementation, fix it

template<class T>
class json_repo : public repo_interface<T> {
private:
    std::string file_name;
    std::vector<T> data;
    nlohmann::json json_data;

    void load_data() {
        std::ifstream file(file_name);
        if (file.is_open()) {
            file >> json_data;
            file.close();
        }
        data = json_data.get<std::vector<T>>();
    }

    void save_data() {
        std::ofstream file(file_name);
        if (file.is_open()) {
            file << json_data;
            file.close();
        }
    }

    void update_json_data() {
        json_data = nlohmann::json::array();
        for (auto &i: data) {
            json_data.push_back(i);
        }
    }

public:
    explicit json_repo(std::string file_name) : file_name(
            std::move(file_name)) {
        load_data();
    }

    ~json_repo() = default;

    void add(T &obj) override {
        data.push_back(obj);
        update_json_data();
        save_data();
    }

    void remove(int id) override {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->get_id() == id) {
                data.erase(it);
                break;
            }
        }
        update_json_data();
        save_data();
    }

    void update(int id, T &obj) override {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (*it.get_id() == id) {
                *it = obj;
                break;
            }
        }
        update_json_data();
        save_data();
    }

    std::vector<T> get_all() override {
        return data;
    }

    T get_by_id(int id) override {
        for (auto &i: data) {
            if (i.get_id() == id) {
                return i;
            }
        }
        return T();
    }

    int size() override {
        return data.size();
    }
};


#endif //LAB_9_JSON_VECTOR_H
