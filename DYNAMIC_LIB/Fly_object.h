#pragma once
#include"Race_object.h"

class Fly_object : public Race_object
{
protected:

	virtual double new_dist(int distance);
public:

	Fly_object(double speed_fly);
	double race_time(int distance) override;
};

