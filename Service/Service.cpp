
#include "Service.h"
#include <vector>

Service::Service() {
}

Service::Service(Repo &r) {
    this->repo = r;
}

void Service::create(Expense ent) {
    repo.add_elem(ent);
}

void Service::update(Expense& old_ent, Expense& new_ent) {
    repo.modify_elem(old_ent, new_ent);

}

void Service::delete_ent(Expense ent) {
    repo.delete_elem(ent);
}

std::vector <Expense> Service::get_all() {
    std::vector<Expense> v = this->repo.get_all();
    return v;
}

Expense Service::get_by_id(int id) {
    return repo.get_by_id(id);
}


Service::~Service() = default;


