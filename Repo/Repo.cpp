
#include <stdexcept>
#include <cstring>
#include <algorithm>
#include "Repo.h"

Repo::Repo() {
    this->n = 0;
}

Repo::~Repo() {
}

void Repo::add_elem(Expense &entity) {
    this->vector[this->n++] = entity;
}

int Repo::get_size() {
    return this->n;
}

std::vector<Expense> Repo::get_all() {
    std::vector<Expense> vect;
    for (int i = 0; i < n; i++)
        vect.push_back(vector[i]);
    return vect;
}

Expense Repo::get_entity_from_pos(int pos) {
    return this->vector[pos];
}

Expense Repo::get_by_id(int id) {
    for (Expense &e: vector) {
        if (e.get_id() == id) {
            return e;
        }
    }
    throw std::runtime_error("No entity with specified id found");
}

Expense Repo::get_by_type(char *type) {
    for (Expense &e: vector) {
        if (strcmp(e.get_type(), type) == 0) {
            return e;
        }
    }
    throw std::runtime_error("No entity with specified type found");
}

void Repo::delete_elem(Expense entity) {
    int idDelete = entity.get_id();
    for (int i = 0; i < n; i++)
        if (vector[i].get_id() == idDelete) {
            for (int j = i; j < n - 1; j++)
                vector[j] = vector[j + 1];
            n--;
        }
}


void Repo::modify_elem(Expense &old_entity, Expense &new_entity) {
    for (int i = 0; i < n; i++)
        if (vector[i].get_id() == old_entity.get_id())
            vector[i] = new_entity;
}

Repo &Repo::operator=(const Repo &repo) {
    if(this != &repo)
    {
        this->n = repo.n;
        for(int i = 0; i < n; i++)
            this->vector[i] = repo.vector[i];
    }
    return *this;
}




