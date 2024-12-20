#include "Class.h"
#include "Function.h"

//������ ������ service
//service::service(string fname = "����� �����", double fcost = 0) //�����������
service::service(string fname, double fcost) //�����������
{
    name = fname;
    cost = fcost;
}
service::~service() //����������
{
    cout << rus("����� �����") << endl;
}
void service::set_name(string new_name)
{
    name = new_name;
}
string service::get_name()
{
    return name;
}
void service::set_cost(double new_cost)
{
    cost = new_cost;
}
double service::get_cost()
{
    return cost;
}
//������ ������ resident
//resident::resident(string fsurname = "-", string fname = "-") //�����������
resident::resident(string fsurname, string fname) //�����������
{
    name = fname;
    surname = fsurname;
}
resident::~resident() //����������
{
    cout << rus("����� �����") << endl;
}
void resident::set_name(string new_name, string new_surname)
{
    name = new_name;
    surname = new_surname;
}
string resident::get_surname()
{
    return surname;
}
void resident::use_service(service* cur_service)
{
    consumption.push_back(cur_service);
}
double resident::summ_service()
{
    double res_cost = 0;
    for (unsigned int i = 0; i < consumption.size(); i++)
    {
        res_cost += (*consumption[i]).get_cost();
    }
    return res_cost;
}

//������ ������ ges
//ges::ges(string nd = "-", int nn = 0) //�����������
ges::ges(string nd, int nn) //�����������
{
    district = nd;
    number = nn;
}
ges::~ges() //����������
{
    cout << rus("��� �������") << endl;
}
void ges::set_district(string newd)
{
    district = newd;
}
void ges::set_number(int newn)
{
    number = newn;
}
void ges::add_service(service* new_service)
{
    services.push_back(new_service);
}
void ges::add_resident(resident* new_resident)
{
    residents.push_back(new_resident);
}
resident* ges::find_res(string f_surname)
{
    resident* res_to_find = nullptr;
    for (int i = 0; i < residents.size(); i++)
    {
        if (f_surname == (*residents[i]).get_surname())
        {
            res_to_find = residents[i];
        }
    }
    if (res_to_find != nullptr)
    {
        return res_to_find;
    }
    throw string("Error: ");
}
service* ges::find_service(string f_service)
{
    service* service_to_find = nullptr;
    for (int j = 0; j < services.size(); j++)
    {
        if (f_service == (*services[j]).get_name())
        {
            service_to_find = services[j];
        }
    }
    if (service_to_find != nullptr)
    {
        return service_to_find;
    }
    throw string("Error: ");
}
void ges::clean_services()
{
    for (int i = 0; i < services.size(); i++)
    {
        delete services[i];
    }
}
void ges::clean_residents()
{
    for (int j = 0; j < residents.size(); j++)
    {
        delete residents[j];
    }
}
double ges::total_cost()
{
    double total = 0;
    for (unsigned int i = 0; i < residents.size(); i++)
    {
        total += (*residents[i]).summ_service();
    }
    return total;
}
void ges::print_info()
{
    cout << endl << rus("����� ������: ") << district << endl;
    cout << rus("����� ���: ") << number << endl;
}