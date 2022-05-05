
#include "Menu.h"
#include "../Repo/Repo.h"
#include "../Service/Service.h"
#include "../UI/UI.h"

void menu() {
    bool ok = true;
    UI ui;
    Service service;

    while (ok) {
        cout << endl;
        cout << "s. Show expenses." << endl;
        cout << "1. Add an expense." << endl;
        cout << "2. Delete the expenses from an apartment" << endl;
        cout << "3. Delete all expenses from apartments between 2 values" << endl;
        cout << "4. Delete all expenses which contain a given type." << endl;
        cout << "5. Modify the sum of an expense" << endl;
        cout << "6. Show all expenses of a given apartment" << endl;
        cout << "7. Show all expenses with sum grater than a given value" << endl;
        cout << "8. Show all expense with a given sum" << endl;
        cout << "9. Calculates the sum of expenses for a given type" << endl;
        cout << "a. Show the most valuable expense of an apartment" << endl;
        cout << "b. Sort expenses with contain a certain type." << endl;
        cout << "c. Type filter:" << endl;
        cout << "d. Sum filter (expenses below a given sum):" << endl;
        cout << "e. Undo" << endl;
        cout << "x. Close" << std::endl;
        char option;
        cout << "Give option: ";
        cin >> option;
        cout << endl;
        switch (option) {
            case '1': {
                ui.add_expense();
                break;
            }
            case 's': {
                ui.show_all();
                break;
            }
            case '2': {
                int ap;
                cout << "Give apartment number:";
                cin >> ap;
                ui.delete_apartment(ap);
                break;
            }
            case '3': {
                int start_ap, end_ap;
                cout << "Give apartment 1:";
                cin >> start_ap;
                cout << "Give apartment 2:";
                cin >> end_ap;
                ui.delete_apartments(start_ap, end_ap);
                break;
            }
            case '4': {
                char t[50];
                cout << "Give type:";
                cin >> t;
                ui.delete_apartment_type(t);
                break;
            }
            case '5': {
                char t[50];
                int ap, s;
                cout << "Give apartment:";
                cin >> ap;
                cout << "Give type:";
                cin >> t;
                cout << "Give the new sum:";
                cin >> s;
                ui.modify_sum(ap, t, s);
                break;
            }
            case '6': {
                int ap;
                cout << "Give apartment number:";
                cin >> ap;
                ui.show_all_apartment(ap);
                break;
            }
            case '7': {
                int value;
                cout << "Give value:";
                cin >> value;
                ui.show_all_grater_than_value(value);
                break;
            }
            case '8': {
                int s1;
                cout << "Give sum:";
                cin >> s1;
                ui.show_all_given_sum(s1);
                break;
            }
            case '9': {
                char t[50];
                cout << "Give type:";
                cin >> t;
                cout << ui.show_sum(t);
                break;
            }
            case 'a': {
                int ap;
                cout << "Give apartment number:";
                cin >> ap;
                Expense e;
                e = ui.show_biggest_apartment(ap);
                cout << e.get_id() << " " << e.get_number() << " " << e.get_sum() << " " << e.get_type();
                break;
            }
            case 'b': {
                char t[50];
                cout << "Give type:";
                cin >> t;
                vector<Expense> vect = ui.sort_by_type(t);
                for (auto &e: vect)
                    cout << e.get_id() << " " << e.get_number() << " " << e.get_sum() << " " << e.get_type() << endl;
                break;
            }
            case 'c':{
                char t[50];
                cout << "Give type:";
                cin >> t;
                ui.filter_type(t);
                break;
            }
            case 'd':{
                int s2;
                cout << "Give sum:";
                cin >> s2;
                ui.filter_sum(s2);
                break;
            }
            case 'x':
                ok = false;
                break;
            default:
                cout << "Wrong! Try again!" << endl;
        }
    }
}
