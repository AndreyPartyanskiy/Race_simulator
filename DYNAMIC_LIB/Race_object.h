#pragma once
#include <iostream>

class Race_object
{
public:
    std::string name = "";
    double speed_race;
    double time_to_recovery;
    double duration_recovery_1;
    double duration_recovery_2;
    double duration_recovery_3;
    double speed_fly;
    
    Race_object();

   virtual double race_time(int distance);
    
};

