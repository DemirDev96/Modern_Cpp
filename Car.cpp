#include "Car.h"
#include <algorithm> // std::clamp
#include <ostream>   // std::ostream

double Car::refuel(double liters)
{
    if (liters <= 0.0) return 0.0;

    const double before = fuel_liters_;
    fuel_liters_ = std::clamp(fuel_liters_ + liters, 0.0, kFuelCapacityLiters);
    return fuel_liters_ - before; // how much actually got in
}

int Car::accelerate(int delta_kmph)
{
    if (delta_kmph <= 0) return speed_kmph_;

    const int old = speed_kmph_;
    speed_kmph_ = std::clamp(speed_kmph_ + delta_kmph, 0, kMaxSpeedKmph);

    consume_fuel_for_speed_change(speed_kmph_ - old);

    // If we ran out of fuel, you might want to force speed down.
    if (fuel_liters_ <= 0.0) {
        fuel_liters_ = 0.0;
        speed_kmph_ = 0;
    }
    return speed_kmph_;
}

int Car::brake(int delta_kmph)
{
    if (delta_kmph <= 0) return speed_kmph_;
    speed_kmph_ = std::clamp(speed_kmph_ - delta_kmph, 0, kMaxSpeedKmph);
    return speed_kmph_;
}

int Car::set_passengers(int count)
{
    passengers_ = std::clamp(count, 0, kSeatCapacity);
    return passengers_;
}

void Car::print_dashboard(std::ostream& os) const
{
    os << "Speed: "      << speed_kmph_   << " km/h\n"
       << "Fuel: "       << fuel_liters_  << " L\n"
       << "Passengers: " << passengers_   << '\n';
}

void Car::consume_fuel_for_speed_change(int delta_kmph)
{
    // Simple model: accelerating costs fuel; braking doesn't.
    if (delta_kmph <= 0) return;

    // Rough consumption: 0.005 L per +1 km/h change (tunable).
    const double consumption = 0.005 * static_cast<double>(delta_kmph);

    fuel_liters_ = std::clamp(fuel_liters_ - consumption, 0.0, kFuelCapacityLiters);
}
