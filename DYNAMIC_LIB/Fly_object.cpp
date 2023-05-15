#include "Fly_object.h"
#include "Race_object.h"

Fly_object::Fly_object(double speed_fly) : Race_object :: Race_object () 
{
	this->speed_fly = speed_fly;
}

double Fly_object::new_dist(int distance)
{
	return distance;
}

double Fly_object::race_time(int distance)
{
	return new_dist(distance)/speed_fly;
}
