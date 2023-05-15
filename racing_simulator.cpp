// racing_simulator.cpp 

#include <iostream>
#include <Windows.h>
#include "Race_object.h"
#include "Ground_object.h"
#include "Camel.h"
#include "Hyper_Camel.h"
#include "Centaur.h"
#include "Boots.h"
#include "Fly_object.h"
#include "Eagle.h"
#include "Magic_carpet.h"
#include "Broom.h"



int welcome_game()
{
    int temp;
    std::cout << "1. Гонка для наземного транспорта" << std::endl;
    std::cout << "2. Гонка для воздушного транспорта" << std::endl;
    std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
    std::cout << "Выберите тип гонки: ";
    std::cin >> temp;
    system("cls");
    return temp;
}

int dis_game()
{
    int dis_temp;
    std::cout << "Укажите длину дистанции (должна быть положительна): ";
    std::cin >> dis_temp;
    if (dis_temp < 0) dis_game();
    system("cls");
    return dis_temp;
}

int check_type_member(Race_object* temp)
{
    int type = 0;
    if (temp->speed_fly == 0)
        return (1);
    else
        return (2);
}

bool check_record_member_race(Race_object* member_race[], Race_object* temp)
{
    int count = 0;
    if (member_race[0] == NULL)
    {
        member_race[0] = temp;   
    }
    else 
    {
        while (member_race[count]!=NULL)
        {
            if (temp->name == member_race[count]->name) return true;
            count++;
        } ;
        std::cout << "count = " << count << std::endl;
        member_race[count] = temp;
    }
    
    return false;
}

void print_reg(Race_object* member_race[], int t_g, int dis)
{
    
    std::string str;
    if (t_g == 1) str = "наземного транспорта. ";
    if (t_g == 2) str = "воздушного транспорта. ";
    if (t_g == 3) str = "наземного и воздушного транспорта. ";
    std::cout << "Гонка для " << str << "Расстояние:" << dis <<  std::endl;

    if (member_race[0] != NULL)
    {
        int count=0;
        std::cout << "Зарегистрированные транспортные средства: ";
        while (member_race[count] != NULL)
        {
            std::cout << member_race[count]->name << " ";
            count++;
        }
        std::cout << std::endl;
    }
    std::cout << "1. Ботинки-вездеходы " << std::endl;
    std::cout << "2. Метла " << std::endl;
    std::cout << "3. Верблюд " << std::endl;
    std::cout << "4. Кентавр " << std::endl;
    std::cout << "5. Орёл " << std::endl;
    std::cout << "6. Верблюд-быстроход " << std::endl;
    std::cout << "7. Ковер-самолет " << std::endl;
    std::cout << "0. Закончить регистрацию " << std::endl;
}


void  result_race(Race_object* member_race[], int dist)
{ 
    struct result
    {
        std::string str;
        double time = 0.0;
    };
    result res[8]{};
    
    int count = 0;
    while (member_race[count]!=NULL)
    {
        res[count].str = member_race[count]->name;
        res[count].time = member_race[count]->race_time(dist);
        count++;
    };
   
    result temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int y = 0; y < count - 1; y++)
        {
            if (res[y].time > res[y + 1].time)
            {
                temp = res[y];
                res[y] = res[y + 1];
                res[y + 1] = temp;

            }
        }
    }
    std::cout << "Результаты гонки: " << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << i+1 << ". " << res[i].str << ". " << " Время: " << res[i].time << std::endl;
    }
    std::cout << std::endl;
}

void reg_play_race(Race_object* member_race[], int t_g, int dis)
{
    int d=0;
    int choice_object = 100;
    int n = 0;
    Race_object* temp =NULL;
    Camel cam(10, 30, 5, 8);
    Centaur cent(15, 8, 2);  
    Boots boots(6, 60, 10, 5);
    Eagle eag(8);
    Magic_carpet mc(10);
    Broom br(20);
    Hyper_Camel hc(40,10,5,6.5,8);
    while (d != 1)
    {
       
        while (d != 1)
        {
            choice_object = 100;
            std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
            std::cout << "1. Зарегистрировать транспорт" << std::endl;
            std::cout << "Выберите действие: ";
            std::cin >> d;
            system("cls");
        }
        
        if (d == 1)
        {
            while (choice_object != 0)
            {
                print_reg(member_race, t_g, dis);

                std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
                std::cin >> choice_object;
                switch (choice_object)
                {
                case 1:
                    temp = &boots;
                    break;
                case 2:
                    temp = &br;
                    break;
                case 3:
                    temp = &cam;
                    break;
                case 4:
                    temp = &cent;
                    break;
                case 5:
                    temp = &eag;
                    break;
                case 6:
                    temp = &hc;
                    break;
                case 7:
                    temp = &mc;
                    break;
                case 0:
                    break;
                default:
                    break;
                }


                if (choice_object == 0)
                {
                    int action = 0;
                    system("cls");
                    while (action != 1 && action != 2 && member_race[1]!=NULL)
                    {
                        std::cout << "1. Зарегистрировать транспорт" << std::endl;
                        std::cout << "2. Начать гонку" << std::endl;
                        std::cout << "Выберите действие: ";
                        std::cin >> action;
                        system("cls");
                    }


                    if (action == 1) choice_object = 100;
                    if (action == 2 && member_race[1] == NULL)  choice_object = 100;
                    if (action == 0) 
                    { 
                        d = 0; 
                        choice_object = 0; 
                    };
                }
                else
                {

                    if (t_g == check_type_member(temp) || t_g == 3)
                    {
                        if (!check_record_member_race(member_race, temp))
                        {
                            system("cls");
                            std::cout << temp->name << " успешно зарегистрирован!" << std::endl;
                        }
                        else
                        {
                            system("cls");
                            std::cout << temp->name << " уже зарегистрирован!" << std::endl;
                        }

                    }
                    else
                    {
                        system("cls");
                        std::cout << "Попытка зарегистрировать неправильный тип транспортного средства! \n " << std::endl;
                    }

                }
            }

        }
    }
    system("cls");
    result_race(member_race, dis);  
}



int main()
{
    system("chcp 1251");
    system("cls"); 
    std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
    
    int abc=1;
    while (abc == 1)
    {
        int type_game = welcome_game();
        int distance = dis_game();
        Race_object** member_race = new Race_object * [8]();

        reg_play_race(member_race, type_game, distance);

        delete[] member_race;
        abc = 3;
        while (abc != 1 && abc != 2)
        {
            std::cout << "1.Провести ещё одну гонку " << std::endl;
            std::cout << "2.Выйти " << std::endl;
            std::cout << "Выберите действие: ";
            std::cin >> abc;
            system("cls");
        }
    }
}
