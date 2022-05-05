//
// Created by User on 5/5/2022.
//

#ifndef LAB8_BUN_REPO_H
#define LAB8_BUN_REPO_H



#include <vector>
#include "../Domain/Expense.h"
#include <vector>

class Repo {
private:
    Expense vector[10];
    int n;
public:
    Repo();

    ~Repo();

    void add_elem(Expense &entity);

    int get_size();

    Expense get_entity_from_pos(int pos);

    Expense get_by_id(int id);

    Expense get_by_type(char* type);

    std::vector<Expense> get_all();

    void delete_elem(Expense entity);

    void modify_elem(Expense& old_entity,Expense& new_entity);

    Repo& operator=(const Repo& repo);

};



#endif //LAB8_BUN_REPO_H
