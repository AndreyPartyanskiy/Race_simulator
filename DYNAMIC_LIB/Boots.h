#pragma once
#include "Ground_object.h"

class Boots : public Ground_object
{
public:
	Boots(double speed_race, double time_to_recovery, double duration_recovery_1, double duration_recovery_2);
};

