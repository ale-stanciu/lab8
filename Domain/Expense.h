//
// Created by User on 5/5/2022.
//

#ifndef LAB8_BUN_EXPENSE_H
#define LAB8_BUN_EXPENSE_H



class Expense {
private:
    char* type;
    int number;
    int sum;
    int id;
public:
    Expense();

    Expense(int id1, int number1, int sum1, const char* type1);

    Expense(const Expense &n);

    ~Expense();

    void set_id(int id);

    void set_number(int number);

    void set_sum(int sum);

    void set_type(const char* type);

    int get_number();

    int get_sum();

    char* get_type();

    int get_id();


    Expense& operator=(const Expense& n);

    bool operator==(const Expense& n);

    bool operator<=(const Expense& n);

    bool operator<(const Expense& n);

};


#endif //LAB8_BUN_EXPENSE_H
