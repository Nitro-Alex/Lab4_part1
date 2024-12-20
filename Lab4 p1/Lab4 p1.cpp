#include <memory>

#include "Function.h"
#include "Class.h"

enum menu
{
    input_service_info = 1,
    input_res_info,
    output_res_cost,
    output_total_cost,
    consume_a_service,
    end = 0
};

int main()
{
    ges ges1;
    //меню
    int menu_flag = 1;
    while (1 == 1)
    {
        cout << rus("Введите") << endl;
        cout << rus("1 для ввода информации о тарифе") << endl;
        cout << rus("2 для ввода информации о жильце") << endl;
        cout << rus("3 для вывода стоимости оказанных жильцу услуг") << endl;
        cout << rus("4 для вывода стоимости всех оказанных услуг") << endl;
        cout << rus("5 для записи информации о потреблении жильцом услуги") << endl;
        cout << rus("0 для завершения работы программы") << endl;
        int action;
        cin >> action;
        cout << endl;
        switch (action)
        {
        case menu::input_service_info: //ввод информации о тарифе
        {
            cout << rus("Введите название тарифа") << endl;
            string service_name;
            cin >> service_name;
            cin.get();
            string sprice;
            int flag1;
            do {
                flag1 = 1;
                cout << rus("Введите цену") << endl;
                getline(cin, sprice);
                if (sprice.size() == 0)
                {
                    flag1 = 0;
                }
                else
                {
                    for (int i = 0; i < sprice.size(); i++)
                    {
                        if ((isdigit(sprice[i]) == 0) && (sprice[i] != '.'))
                        {
                            flag1 = 0;
                            cout << rus("Число отрицательное, или же введены недопустимые символы") << endl;
                            break;
                        }
                    }
                    if (stod(sprice) > 10000)
                    {
                        flag1 = 0;
                        cout << rus("Введённое значение слишком большое") << endl;
                    }
                }
            } while (flag1 == 0);
            double price = stod(sprice);
            ges1.add_service(new service(service_name, price));
            cout << endl;
        }
        break;
        case menu::input_res_info: //ввод информации о жильце
        {
            cout << rus("Введите фамилию нового жильца") << endl;
            string res_surname;
            cin >> res_surname;
            cin.get();
            cout << rus("Введите имя нового жильца") << endl;
            string res_name;
            cin >> res_name;
            cin.get();
            ges1.add_resident(new resident(res_surname, res_name));
            cout << endl;
        }
        break;
        case menu::output_res_cost: //вывод стоимости оказанных жильцу услуг
        {
            cout << rus("Введите фамилию жильца, информацию о потреблённых услугах которого вы хотите получить") << endl;
            string res_sur;
            cin >> res_sur;
            cin.get();
            resident* cur_res = nullptr;
            try
            {
                cur_res = ges1.find_res(res_sur);
                if (cur_res != nullptr)
                {
                    cout << rus("Стоимость услуг, потреблённых жильцом: ") << (*cur_res).summ_service();
                    cout << rus(" рублей") << endl;
                    cout << endl;
                }
                else
                {
                    throw string("Error: ");
                }
            }
            catch (string error_message)
            {
                cout << error_message << rus("В системе не зарегистрирован жилец с такой фамилией") << endl;
            }
            cout << endl;
        }
        break;
        case menu::output_total_cost: //вывод стоимости всех оказанных услуг
        {
            cout << rus("Общая стоимость всех оказанных жильцам услуг: ") << ges1.total_cost();
            cout << rus(" рублей") << endl;
            cout << endl;
        }
        break;
        case menu::consume_a_service: //запись информации об оказании жильцу услуги
        {
            cout << rus("Введите фамилию жильца, потребившего услугу") << endl;
            string res_sur, service_to_reg;
            resident* cur_res = nullptr;
            service* cur_ser = nullptr;
            cin >> res_sur;
            cout << rus("Введите название потреблённой услуги") << endl;
            cin >> service_to_reg;
            int exception_flag = 1;
            try
            {
                cur_res = ges1.find_res(res_sur);
            }
            catch (string error_message)
            {
                cout << error_message << rus("В системе не зарегистрирован жилец с такой фамилией") << endl;
                exception_flag = 0;
            }
            try
            {
                cur_ser = ges1.find_service(service_to_reg);
            }
            catch (string error_message)
            {
                cout << error_message << rus("В системе нет тарифа с таким названием") << endl;
                exception_flag = 0;
            }
            if (exception_flag == 1)
            {
                (*cur_res).use_service(cur_ser);
            }
            cout << endl;
        }
        break;
        case menu::end: //завершение работы
        {
            menu_flag = 0;
        }
        break;
        }

        if (menu_flag == 0) //удаление объектов
        {
            ges1.clean_services();
            ges1.clean_residents();
            break;
        }
    }
    return 0;
}
