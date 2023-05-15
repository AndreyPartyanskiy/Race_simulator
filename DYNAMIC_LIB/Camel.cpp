#include "Camel.h"
#include<iostream>
#include "Ground_object.h"

Camel::Camel(double speed_race, double time_to_recovery, double duration_recovery_1, double duration_recovery_2) : Ground_object :: Ground_object (speed_race, time_to_recovery, duration_recovery_1, duration_recovery_2, duration_recovery_3= duration_recovery_2)
{
    name = "Верблюд";
    this->speed_race = speed_race;
    this->time_to_recovery = time_to_recovery;
    this->duration_recovery_1 = duration_recovery_1;
    this->duration_recovery_2 = duration_recovery_2;
    this->duration_recovery_3 = duration_recovery_2;
}
