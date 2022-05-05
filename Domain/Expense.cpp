
#include "Expense.h"
#include <cstring>
#include <iostream>
#include <vector>


Expense::Expense() {
    this->id = 0;
    this->number = 0;
    this->sum = 0;
    this->type = nullptr;
}

Expense::Expense(int id1 ,int number1, int sum1, const char *type1) {
    this->id = id1;
    this->number = number1;
    this->sum = sum1;
    this->type = new char[strlen(type1)+1];
    strcpy_s(this->type, sizeof(this->type), type1);
}

Expense::Expense(const Expense &n) {
    this->id=n.id;
    this->number=n.number;
    this->sum=n.sum;
    this->type= new char[strlen(n.type)+1];
    strcpy_s(this->type, sizeof(this->type), n.type);
}

void Expense::set_number(int number1) {
    this->number = number1;
}

void Expense::set_sum(int sum1) {
    this->sum = sum1;
}

void Expense::set_type(const char *type1) {
    if(this->type){
        delete[] this->type;
    }
    this->type = new char[strlen(type1) +1];
    strcpy(this->type, type1);
}

void Expense::set_id(int id) {
    this->id = id;

}
int Expense::get_number() {
    return number;
}

int Expense::get_sum() {
    return sum;
}

char *Expense::get_type() {
    return type;
}

int Expense::get_id() {
    return id;
}

Expense::~Expense() {
    if(this->type){
        delete[] this->type;
        this->type = nullptr;
    }
}

Expense &Expense::operator=(const Expense &n) {
    if(this->type != nullptr){
        delete[] this->type;
    }
    this->type = new char[strlen(n.type) +1];
    strcpy(this->type, n.type);
    //this->set_type(n.type);
    this->set_sum(n.sum);
    this->set_number(n.number);
    this->set_id(n.id);
    return *this;
}


bool Expense::operator==(const Expense &n) {
    return this->number == n.number && this->sum == n.sum && strcmp(this->type, n.type) == 0;
}

bool Expense::operator<=(const Expense &n) {
    return this->sum >= n.sum;
}

bool Expense::operator<(const Expense &n) {
    return this->sum > n.sum;
}

