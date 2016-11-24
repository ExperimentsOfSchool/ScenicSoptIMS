//
// Created by Lawrence Lee on 24/11/2016.
//

#ifndef SCENICSPOTIMS_PARKINGLOT_H
#define SCENICSPOTIMS_PARKINGLOT_H


#include <string>
#include <stack>
#include <queue>
#include <iostream>
#include "Vehicle.h"

using namespace std;

class ParkingLot {
private:
    string name;
    const int maxSpace;
    stack<Vehicle> parkingSpace;
    stack<Vehicle> tempStack;
    queue<Vehicle> waitingLine;
    queue<Vehicle> tempQueue;
    Vehicle currentVehicle = Vehicle((string)"123", 0, 0);

    void parkVehicle();
    void fetchVehicle();
    void checkVehicleStatus();
    void countFee(string & vehicleID);

public:

    ParkingLot(const string &name, const int maxSpace);

    void run();
    int searchVehicle(const string & vehicleID);
};

#endif //SCENICSPOTIMS_PARKINGLOT_H
