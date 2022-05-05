

#include "UI.h"
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

UI::UI() {

}


UI::~UI() {

}

UI::UI(Service &ser) {
    this->service = ser;
}

void UI::add_expense() {
    int id, number, sum;
    char type[50];
    cout << "Give id:";
    cin >> id;
    cout << "Give apartment number:";
    cin >> number;
    cout << "Give sum:";
    cin >> sum;
    cout << "Give type:";
    cin >> type;


    Expense expense(id, number, sum, type);
    service.create(expense);
}

void UI::show_all() {
    for (auto &exp: service.get_all())
        cout << exp.get_id() << " " << exp.get_number() << " " << exp.get_sum() << " " << exp.get_type() << endl;

}

void UI::delete_apartment(int ap) {
    for (auto &exp: service.get_all())
        if (ap == exp.get_number())
            service.delete_ent(exp);
}

void UI::delete_apartments(int start_ap, int end_ap) {
    for (auto &exp: service.get_all())
        if (start_ap <= exp.get_number() && end_ap >= exp.get_number())
            service.delete_ent(exp);
}

void UI::delete_apartment_type(const char *t) {
    for (auto &exp: service.get_all())
        if (strcmp(t, exp.get_type()) == 0)
            service.delete_ent(exp);
}

void UI::modify_sum(int ap, const char *t, int s) {
    Expense old_exp;
    for (auto &exp: service.get_all())
        if (strcmp(t, exp.get_type()) == 0 && exp.get_number() == ap)
            old_exp = exp;
    if (old_exp.get_number() != 0) {
        Expense new_exp(old_exp.get_id(), ap, s, t);
        service.update(old_exp, new_exp);
    }
}

void UI::show_all_apartment(int ap) {
    for (auto &exp: service.get_all())
        if (ap == exp.get_number())
            cout << exp.get_id() << " " << exp.get_number() << " " << exp.get_sum() << " " << exp.get_type() << endl;
}

void UI::show_all_grater_than_value(int value) {
    for (auto &exp: service.get_all())
        if (exp.get_sum() > value)
            cout << exp.get_id() << " " << exp.get_number() << " " << exp.get_sum() << " " << exp.get_type() << endl;
}

void UI::show_all_given_sum(int s) {
    for (auto &exp: service.get_all())
        if (exp.get_sum() == s)
            cout << exp.get_id() << " " << exp.get_number() << " " << exp.get_sum() << " " << exp.get_type() << endl;
}

int UI::show_sum(const char *t) {
    int s = 0;
    for (auto &exp: service.get_all())
        if (strcmp(t, exp.get_type()) == 0)
            s += exp.get_sum();
    return s;
}

Expense UI::show_biggest_apartment(int ap) {
    int maxi = 0;
    Expense e;
    for (auto &exp: service.get_all())
        if (ap == exp.get_number() && maxi < exp.get_sum()) {
            maxi = exp.get_sum();
            e = exp;
        }
    if (maxi != 0)
        return e;
}

std::vector<Expense> UI::sort_by_type(const char *t) {
    vector<Expense> v = {};
    for (auto &exp: service.get_all()){
        if (strcmp(exp.get_type(), t) == 0){
            v.push_back(exp);
        }
    }
    std::sort(v.begin(), v.end());
    return v;
}

void UI::filter_type(const char* t) {
    for (auto &exp: service.get_all())
        if (strcmp(t, exp.get_type()) == 0)
            service.delete_ent(exp);
}

void UI::filter_sum(int s) {
    for (auto &exp: service.get_all())
        if (s < exp.get_sum())
            service.delete_ent(exp);
}

std::vector<Expense> UI::UI_get_all() {
    return service.get_all();

}

Expense UI::get_entity(int id) {
    for (auto &exp: service.get_all())
        if(id == exp.get_id())
            return exp;
}
