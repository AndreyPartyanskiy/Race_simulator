#include "Magic_carpet.h"

double Magic_carpet::new_dist(int distance)
{
	if (distance < 1000) return distance;
	if (distance >= 1000 && distance < 5000) return distance * 0.97;
	if (distance >= 5000 && distance < 100000) return distance * 0.9;
	if (distance >= 1000) return distance * 0.95;
	return distance;
}

Magic_carpet::Magic_carpet(double speed_fly) : Fly_object :: Fly_object (speed_fly)
{
	this->name = "Ковёр-самолет";
	this->speed_fly = speed_fly;
}
