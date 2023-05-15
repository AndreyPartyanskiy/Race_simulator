#pragma once
#include "Fly_object.h"

class Eagle : public Fly_object
{
protected:

	double new_dist(int distance) override;
public:

	Eagle(double speed_fly);
};


