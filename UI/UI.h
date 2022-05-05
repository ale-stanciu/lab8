//
// Created by User on 5/5/2022.
//

#ifndef LAB8_BUN_UI_H
#define LAB8_BUN_UI_H



#include "../Service/Service.h"

class UI {
private:
    Service service;
public:
    UI();

    UI(Service &ser);

    ~UI();

    void add_expense();

    void show_all();

    void delete_apartment(int ap);

    void delete_apartments(int start_ap, int end_ap);

    void delete_apartment_type(const char* t);

    void modify_sum(int ap, const char*t, int s);

    void show_all_apartment(int ap);

    void show_all_grater_than_value(int value);

    void show_all_given_sum(int s);

    int show_sum(const char* t);

    Expense show_biggest_apartment(int ap);

    std::vector<Expense> sort_by_type(const char* t);

    void filter_type(const char* t);

    void filter_sum(int s);

    std::vector<Expense> UI_get_all();

    Expense get_entity(int id);


};



#endif //LAB8_BUN_UI_H
