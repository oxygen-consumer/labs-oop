//
// Created by zaha on 4/3/22.
//

#include <iostream>
#include <string>
#include "../Service/transaction_service.h"

#ifndef LAB_7_MENU_H
#define LAB_7_MENU_H

// TODO: reformat with cxxopts

class menu {
private:
    transaction_service serv;

    /**
     * @brief Prints the help menu
     */
    static void print_menu();

    /**
     * @brief Prints the available arguments for the property argument
     */
    static void print_property_arguments();

    /**
     * @brief Parses the add command
     * @param command The command to parse
     */
    void add_command(const std::string &command);

    /**
     * @brief Parses the remove command
     * @param command The command to parse
     */
    void remove_command(const std::string &command);

    /**
     * @brief Parses the get command
     * @param command The command to parse
     */
    void get_command(const std::string &command);

    /**
     * @brief Parses the lst command
     * @param command The command to parse
     */
    void list_command(const std::string &command);

    /**
     * @brief Parses the update command
     * @param command The command to parse
     */
    void update_command(const std::string &command);

    /**
     * @brief Parses the filter command
     * @param command The command to parse
     */
    void filter_command(const std::string &command);

    /**
     * @brief Parses the sol command
     * @param command The command to parse
     */
    void sol_command(const std::string &command);

    /**
     * @brief Parses the undo command
     * @param command The command to parse
     */
    void undo_command();

    /**
     * @brief Parses the redo command
     * @param command The command to parse
     */
    void redo_command();

    /**
     * @brief Parses the min command
     * @param command The command to parse
     */
    void min_command(const std::string &command);

    /**
     * @brief Parses the max command
     * @param command The command to parse
     */
    void max_command(const std::string &command);

    /**
     * @brief Parses the sum command
     * @param command The command to parse
     */
    void sum_command(const std::string &command);

    /**
     * @brief Parses the clear command
     * @param command The command to parse
     */
    void clear_command(const std::string &command);

public:
    /**
     * @brief Constructs a menu object
     */
    menu();

    /**
     * @brief Destructs a menu object
     */
    ~menu();

    /**
     * @brief Runs the menu
     */
    void start();

};


#endif //LAB_7_MENU_H
