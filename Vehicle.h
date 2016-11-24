//
// Created by Lawrence Lee on 24/11/2016.
//

#ifndef SCENICSPOTIMS_CAR_H
#define SCENICSPOTIMS_CAR_H

#include <string>
#include <ctime>

class Vehicle {
private:
    std::string vehicleName;
    time_t timeStamp;
    int vehicleType;
    const double fee1perMin = 0.1;
    const double fee2perMin = 0.2;
public:
    Vehicle(const std::string &vehicleName, time_t timeStamp, int vehicleType);
    Vehicle(const Vehicle & V);

    Vehicle();

    Vehicle & operator= (const Vehicle & V);
    const std::string &getVehicleName() const;

    time_t getTimeStamp() const;

    int getVehicleType() const;

    void setTimeStamp(time_t timeStamp);

    const double countFee();
};


#endif //SCENICSPOTIMS_CAR_H
