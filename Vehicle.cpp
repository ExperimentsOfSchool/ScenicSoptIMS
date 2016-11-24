//
// Created by Lawrence Lee on 24/11/2016.
//

#include "Vehicle.h"

Vehicle::Vehicle(const std::string &vehicleName, time_t timeStamp, int vehicleType) : vehicleName(vehicleName),
                                                                                      timeStamp(timeStamp),
                                                                                      vehicleType(vehicleType) {}

Vehicle::Vehicle() {}

Vehicle::Vehicle(const Vehicle & V) {
    vehicleName = V.vehicleName;
    vehicleType = V.vehicleType;
    timeStamp = V.timeStamp;
}

Vehicle &Vehicle::operator= (const Vehicle & V) {
    vehicleName = V.vehicleName;
    vehicleType = V.vehicleType;
    timeStamp = V.timeStamp;
    return *this;
}

const std::string &Vehicle::getVehicleName() const {
    return vehicleName;
}

time_t Vehicle::getTimeStamp() const {
    return timeStamp;
}

int Vehicle::getVehicleType() const {
    return vehicleType;
}

void Vehicle::setTimeStamp(time_t timeStamp) {
    Vehicle::timeStamp = timeStamp;
}

const double Vehicle::countFee() {
    time_t currentTime = time(nullptr);
    time_t countTime = currentTime - timeStamp;
    if (vehicleType == 1) {
        return (countTime / 1000 / 60) * fee1perMin;
    } else {
        return (countTime / 1000 / 60) * fee2perMin;
    }
}