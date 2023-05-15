#include "Eagle.h"

Eagle::Eagle(double speed_fly) : Fly_object::Fly_object(speed_fly)
{
	this->name = "Îğ¸ë";
	this->speed_fly = speed_fly;
}

double Eagle::new_dist(int distance)
{
	return distance * 0.94;
}
