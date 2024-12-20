#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class service //������
{
public:
    service(string fname = "����� �����", double fcost = 0); //�����������
    ~service(); //����������
    void set_name(string new_name);
    string get_name();
    void set_cost(double new_cost);
    double get_cost();
private:
    string name;
    double cost;
};

class resident //������
{
public:
    resident(string fsurname = "-", string fname = "-"); //�����������
    ~resident(); //����������
    void use_service(service*);
    double summ_service();
    void set_name(string new_name, string new_surname);
    string get_surname();
private:
    string name;
    string surname;
    vector <service*> consumption;
};

class ges
{
public:
    ges(string nd = "-", int nn = 0); //�����������
    ~ges(); //����������
    void add_service(service*);
    void add_resident(resident*);
    resident* find_res(string);
    service* find_service(string);
    void clean_services();
    void clean_residents();
    double total_cost();
    void print_info();
    void set_district(string newd);
    void set_number(int newn);
private:
    string district = "-";
    int number = 0;
    vector <resident*> residents;
    vector <service*> services;
};