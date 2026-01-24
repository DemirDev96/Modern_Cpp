#include "Car.h"
#include <iostream>

int main() {
    Car c;
    c.refuel(30);
    c.set_passengers();          // defaults to 4
    c.accelerate(20);
    c.brake(5);

    c.print_dashboard(std::cout);
}
