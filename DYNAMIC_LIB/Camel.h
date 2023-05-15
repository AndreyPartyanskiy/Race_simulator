#pragma once
#include "Ground_object.h"

class Camel : public Ground_object
{
public:
	Camel(double speed_race, double time_to_recovery, double duration_recovery_1, double duration_recovery_2);
};

