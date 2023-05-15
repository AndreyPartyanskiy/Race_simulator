#include "Broom.h"

double Broom::new_dist(int distance)
{
	int n = distance / 1000;
	double s = ((n-1) * ((n-1) + static_cast<double>(1)) / 2) / n;
	double new_dis = (n * 1000 * ((100 - s) / 100))+(((distance - n * 1000) * ((static_cast<double>(100) - n) / 100)));
	return new_dis;
}

Broom::Broom(double speed_fly) : Fly_object :: Fly_object (speed_fly)
{
	this->name = "Метла";
	this->speed_fly = speed_fly;
}
