//============================================================================
// Name        : gorillas.cpp
// Author      : Rushil Patel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

#ifndef MARMOSET_TESTING
int main();
#endif

double gravity();
double height;
double x;
double angle_deg(double x);
double velocity_initial;
double horizontal_velocity(double velocity_initial, double angle_deg);
double vertical_velocity(double velocity_intial, double angle_deg);
double computed_range(double velocity_initial, double angle_deg, double height);


//function definitions
double gravity(){
	return 9.80665;
}
double angle_deg(double x){
	return x;
}
double horizontal_velocity(double velocity_initial, double angle_deg){
	return (velocity_initial*cos(angle_deg/180*M_PI));
}
double vertical_velocity(double velocity_initial, double angle_deg){
	return (velocity_initial*sin(angle_deg/180*M_PI));
}
double computed_range(double velocity_initial, double angle_deg, double height){
	return ((velocity_initial*cos(angle_deg/180*M_PI)/gravity()) * (velocity_initial*sin(angle_deg/180*M_PI) + sqrt(velocity_initial*sin(angle_deg/180*M_PI)*velocity_initial*sin(angle_deg/180*M_PI) + 2*gravity()*height)));
}
//function definitions
#ifndef MARMOSET_TESTING
int main(){
	std::cout << "The range the banana reaches for the launch angle of " << angle_deg(10)   <<" degrees is "<<computed_range(600, 10, 10)  <<" m"<<std::endl;
	std::cout << "The range the banana reaches for the launch angle of " << angle_deg(20)   <<" degrees is "<<computed_range(600, 20, 10)  <<" m"<<std::endl;
	std::cout << "The range the banana reaches for the launch angle of " << angle_deg(25.5) <<" degrees is "<<computed_range(600, 25.5, 10)<<" m"<<std::endl;
	std::cout << "The range the banana reaches for the launch angle of " << angle_deg(30)   <<" degrees is "<<computed_range(600, 30, 10)  <<" m"<<std::endl;
	std::cout << "The range the banana reaches for the launch angle of " << angle_deg(40)   <<" degrees is "<<computed_range(600, 40, 10)  <<" m"<<std::endl;
	std::cout << "The range the banana reaches for the launch angle of " << angle_deg(50)   <<" degrees is "<<computed_range(600, 50, 10)  <<" m"<<std::endl;
	std::cout << "The range the banana reaches for the launch angle of " << angle_deg(55.5) <<" degrees is "<<computed_range(600, 55.5, 10)<<" m"<<std::endl;
	std::cout << "The range the banana reaches for the launch angle of " << angle_deg(60)   <<" degrees is "<<computed_range(600, 60, 10)  <<" m"<<std::endl;
	std::cout << "The range the banana reaches for the launch angle of " << angle_deg(70)   <<" degrees is "<<computed_range(600, 70, 10)  <<" m"<<std::endl;
	std::cout << "The range the banana reaches for the launch angle of " << angle_deg(75.5) <<" degrees is "<<computed_range(600, 75.5, 10)<<" m"<<std::endl;
	std::cout << "The range the banana reaches for the launch angle of " << angle_deg(80)   <<" degrees is "<<computed_range(600, 80, 10)  <<" m"<<std::endl;
	std::cout << "The range the banana reaches for the launch angle of " << angle_deg(90)   <<" degrees is "<<computed_range(600, 90, 10)  <<" m"<<std::endl;

	return 0;

}
#endif



