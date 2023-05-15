#include "Ground_object.h"
#include <iostream>
#include <string>

Ground_object::Ground_object(double speed_race, double time_to_recovery, double duration_recovery_1, double duration_recovery_2, double duration_recovery_3) : Race_object::Race_object () //(speed_race, time_to_recovery, duration_recovery_1, duration_recovery_2, duration_recovery_3, speed_fly)
{
    this->speed_race = speed_race;
    this->time_to_recovery = time_to_recovery;
    this->duration_recovery_1 = duration_recovery_1;
    this->duration_recovery_2 = duration_recovery_2;
    this->duration_recovery_3 = duration_recovery_3;
    this->speed_fly = 0;
}

    double Ground_object::race_time(int distance)
    {
        int a = static_cast <int> (distance / (speed_race * time_to_recovery));
        int temp_dis = distance;
        double temp_time = 0;

        if (a == 0)
        {
            temp_time = static_cast <double> (distance) / speed_race;
            return (temp_time);
        }
        if (a == 1)
        {
            double s = distance % static_cast <int> (speed_race * time_to_recovery);
            if (s)
                temp_time = time_to_recovery + duration_recovery_1 + ((distance - (speed_race * time_to_recovery)) / speed_race);
            else
                temp_time = time_to_recovery;

            return (temp_time);
        }
        if (a == 2)
        {
            double s = distance % static_cast <int> (speed_race * time_to_recovery);
            if (s)
                temp_time = time_to_recovery + duration_recovery_1
                + time_to_recovery + duration_recovery_2
                + ((distance - (speed_race * time_to_recovery)) / speed_race);
            else
                temp_time = time_to_recovery * a + duration_recovery_1;

            return (temp_time);
        }
        if (a >= 3)
        {
            double s = distance % static_cast <int> (speed_race * time_to_recovery);
            if (s)
            {
                temp_time = time_to_recovery + duration_recovery_1 + time_to_recovery + duration_recovery_2;
                double k =  static_cast <double> (distance - (speed_race * time_to_recovery * 2)) / static_cast <double> (speed_race * time_to_recovery);
                temp_time = temp_time + static_cast <int> (k) * (time_to_recovery + duration_recovery_3);
                temp_time = temp_time + (k- static_cast <int> (k)) * time_to_recovery ;
            }
            else
            {
                temp_time = time_to_recovery + duration_recovery_1
                + time_to_recovery + duration_recovery_2
                + ((distance - (speed_race * time_to_recovery * 2)) / speed_race)
                + duration_recovery_3 * (a - 2)
                - duration_recovery_3;
            }
        }
        return (temp_time);
    };


