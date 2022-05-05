//
// Created by User on 5/5/2022.
//

#ifndef LAB8_BUN_SERVICE_H
#define LAB8_BUN_SERVICE_H


#include "../Repo/Repo.h"
#include <vector>

class Service {
private:
    Repo repo;
public:
    Service();

    Service(Repo &r);

    ~Service();

    void create(Expense ent);

    void update(Expense& old_ent, Expense& new_ent);

    void delete_ent(Expense ent);

    std::vector <Expense> get_all();

    Expense get_by_id(int id);

};


#endif //LAB8_BUN_SERVICE_H
