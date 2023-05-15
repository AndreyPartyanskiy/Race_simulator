#pragma once
#include "Fly_object.h"

class Magic_carpet : public Fly_object
{
protected:

	double new_dist(int distance) override;
public:

	Magic_carpet(double speed_fly);
};

