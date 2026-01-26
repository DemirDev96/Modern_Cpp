#include "Car.h"
#include <iostream>

Car::Car() {
    fuel = 0;
    speed = 0;
    passengers = 0;
}
Car::Car(float amount) {
	fuel = amount;

}
void Car::FillFuel(float amount) {
	fuel = amount;
}

void Car::Accelerate() {
	speed++;
	fuel -= 0.5f;
}

void Car::Brake() {
	speed = 0;
}

void Car::AddPassengers(int count) {
	passengers = count;
}

void Car::Dashboard() {
	std::cout << "Fuel level : " << fuel << std::endl;
	std::cout << "Speed : " << speed << std::endl;
	std::cout << "Passengers : " << passengers << std::endl; 
}

Car::~Car() {
}

int main(){
    Car car;
    car.FillFuel(60);
    car.Accelerate();
    car.Dashboard();
}
