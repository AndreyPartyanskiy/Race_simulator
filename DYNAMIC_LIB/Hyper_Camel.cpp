#include "Hyper_Camel.h"
#include "Ground_object.h"

Hyper_Camel::Hyper_Camel(double speed_race, double time_to_recovery, double duration_recovery_1, double duration_recovery_2, double duration_recovery_3) : Ground_object::Ground_object(speed_race, time_to_recovery, duration_recovery_1, duration_recovery_2, duration_recovery_3)
{
    name = "Верблюд-быстроход";
    this->speed_race = speed_race;
    this->time_to_recovery = time_to_recovery;
    this->duration_recovery_1 = duration_recovery_1;
    this->duration_recovery_2 = duration_recovery_2;
    this->duration_recovery_3 = duration_recovery_3;
}
