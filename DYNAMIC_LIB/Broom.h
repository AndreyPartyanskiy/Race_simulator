#pragma once
#include "Fly_object.h"

class Broom : public Fly_object
{
protected:

	double new_dist(int distance)override;
public:

	Broom(double speed_fly);
};

