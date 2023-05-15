#pragma once
#include "Race_object.h"

class Ground_object : public Race_object
{
public:
   
    Ground_object(double speed_race, double time_to_recovery, double duration_recovery_1, double duration_recovery_2, double duration_recovery_3);

    double race_time(int distance) override;
};

