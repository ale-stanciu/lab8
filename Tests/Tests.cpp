
#include <iostream>
#include <cassert>
#include "Tests.h"
#include <cstring>
#include "../Domain/Expense.h"
#include "../Repo/Repo.h"
#include "../Service/Service.h"
#include "../UI/UI.h"

void test_constructor_entity(){
    Expense entity;
    assert(entity.get_id() == 0);
    assert(entity.get_number() == 0);
    assert(entity.get_sum() == 0);
    assert(entity.get_type() == nullptr);
}

void test_constructor2_entity2(){
    const char*s = "curent";
    Expense entity(1,1, 10, s);
    assert(strcmp(entity.get_type(),s) == 0);
}

void test_setters_getters(){
    const char*s = "curent";
    Expense entity;
    entity.set_type(s);
    entity.set_number(10);
    entity.set_sum(60);
    entity.set_id(1);
    assert(strcmp(entity.get_type(),s) == 0);
    assert(entity.get_sum() == 60);
    assert(entity.get_number() == 10);
    assert(entity.get_id() == 1);
}

void test_operator(){
    const char*s = "curent";
    Expense entity(1, 1, 10, s);
    Expense entity1;
    entity1 = entity;
    assert(entity1.get_number() == 1);
    assert(entity1.get_sum() == 10);
    assert(strcmp(entity.get_type(),s) == 0);
}

void test_repo_add_elem(){
    Repo repo;
    const char*s = "curent";
    Expense entity(1, 1, 10, s);
    repo.add_elem(entity);
    assert(repo.get_size() == 1);

    const char*s3 = "caldura";
    Expense entity2(3, 21, 111, s3);
    repo.add_elem(entity2);
    assert(repo.get_size() == 2);


    const char*s2 = "apa";
    Expense entity1(2, 2, 11, s2);
    repo.add_elem(entity1);
    assert(repo.get_size() == 3);

    const char*s4 = "gaz";
    Expense entity3(2, 2, 11, s4);
    repo.add_elem(entity1);
    assert(repo.get_size() == 4);
}

void test_delete(){
    Repo repo;
    const char*s = "curent";
    Expense entity(0, 1, 10, s);
    repo.add_elem(entity);
    //assert(repo.get_size() == 1);

    const char*s2 = "caldura";
    Expense entity2(2, 21, 111, s2);
    repo.add_elem(entity2);

    repo.delete_elem(entity);
    assert(repo.get_size() == 1);
}


void test_modify(){
    Repo repo1;
    const char*s = "curent";
    Expense entity1(0, 1, 10, s);


    const char*s2 = "caldura";
    Expense entity2(1, 21, 111, s2);


    const char*s3 = "apa";
    Expense entity3(0, 2, 11, s3);

    repo1.add_elem(entity1);
    repo1.add_elem(entity2);
    repo1.modify_elem(entity1, entity3);

    assert(repo1.get_by_id(0) == entity3);
}

void test_create(){
    Repo repo1;
    Service service(repo1);
    const char*s = "curent";
    Expense entity1(0, 1, 10, s);

    service.create(entity1);
    //service.update_repo(repo1);
    assert(service.get_all().size() == 1);
}

void test_update(){
    Repo repo1;
    Service service(repo1);
    const char*s = "curent";
    Expense entity1(0, 1, 10, s);

    service.create(entity1);
    const char*s2 = "caldura";
    Expense entity2(1, 21, 111, s2);
    service.update(entity1, entity2);
    assert(service.get_all().size() == 1);
    assert(service.get_by_id(1) == entity2);
}

void test_delete_service(){
    Repo repo1;
    Service service(repo1);
    const char*s = "curent";
    Expense entity1(0, 1, 10, s);

    service.create(entity1);
    const char*s2 = "caldura";
    Expense entity2(1, 21, 111, s2);
    service.create(entity2);
    assert(service.get_all().size() == 2);

    service.delete_ent(entity1);
    assert(service.get_all().size() == 1);
}

void test_ui_delete_apartments(){
    Service servicee;
    const char*s = "curent";
    Expense entity1(0, 1, 10, s);

    servicee.create(entity1);
    const char*s2 = "caldura";
    Expense entity2(1, 21, 111, s2);
    servicee.create(entity2);

    const char*s3 = "apa";
    Expense entity3(0, 24, 11, s3);
    servicee.create(entity3);

    UI ui(servicee);
    ui.delete_apartments(15, 44);
    assert(ui.UI_get_all().size() == 1);
}

void test_ui_delete_apartment(){
    Service servicee;
    const char*s = "curent";
    Expense entity1(0, 1, 10, s);

    servicee.create(entity1);
    const char*s2 = "caldura";
    Expense entity2(1, 21, 111, s2);
    servicee.create(entity2);
    UI ui(servicee);
    ui.delete_apartment(1);
    assert(ui.UI_get_all().size() == 1);
}

void test_ui_delete_apartment_type(){
    Service servicee;
    const char*s = "curent";
    Expense entity1(0, 1, 10, s);

    servicee.create(entity1);
    const char*s2 = "caldura";
    Expense entity2(1, 21, 111, s2);
    servicee.create(entity2);

    UI ui(servicee);
    ui.delete_apartment_type(s);

    assert(ui.UI_get_all().size() == 1);
}

void test_modify_sum(){
    Service servicee;
    const char*s = "curent";
    Expense entity1(1, 1, 10, s);

    servicee.create(entity1);
    const char*s2 = "caldura";
    Expense entity2(2, 21, 111, s2);
    servicee.create(entity2);

    UI ui(servicee);
    ui.modify_sum(1, s, 100);
    assert(ui.get_entity(1).get_sum() == 100);
}

void test_show_sum(){
    Service servicee;
    const char*s = "curent";
    Expense entity1(1, 1, 10, s);

    servicee.create(entity1);
    const char*s2 = "curent";
    Expense entity2(2, 21, 111, s2);
    servicee.create(entity2);

    const char*s3 = "curent";

    UI ui(servicee);
    int sum = ui.show_sum(s3);
    assert(sum == 121);
}

void test_filters(){
    Service servicee;
    const char*s = "curent";
    Expense entity1(0, 1, 10, s);

    servicee.create(entity1);
    const char*s2 = "caldura";
    Expense entity2(1, 21, 111, s2);
    servicee.create(entity2);
    UI ui(servicee);

    const char*s3 = "curent";

    ui.filter_type(s3);
    assert(ui.UI_get_all().size() == 1);

    ui.filter_sum(80);
    assert(ui.UI_get_all().empty());
}



void tests() {
    test_constructor_entity();
    test_constructor2_entity2();
    test_setters_getters();
    test_operator();
    test_repo_add_elem();
    test_delete();
    test_modify();
    test_create();
    test_update();
    test_delete_service();
}

void test_ui(){
    test_ui_delete_apartment();
    test_ui_delete_apartments();
    test_ui_delete_apartment_type();
    test_modify_sum();
    test_show_sum();
    test_filters();
}