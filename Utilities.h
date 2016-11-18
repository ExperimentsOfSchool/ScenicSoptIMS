//
// Created by Lawrence Lee on 18/11/2016.
//

#ifndef SCENICSPOTIMS_UTILITIES_H
#define SCENICSPOTIMS_UTILITIES_H

#include <iostream>
#include <string>

#include "ScenicSpot.h"

void setSpotList(ScenicSpot * spotList[], int &spotQty, int &roadQty);
void printSpotList(ScenicSpot * spotList[], const int spotQty, const int roadQty);
int find(ScenicSpot * spotList[], std::string spotName, const int spotQty);
void printTravelRoute(ScenicSpot * spotList[], const int index, const int spotQty);
int generateNearestRoute(ScenicSpot * spotList[], const int spotQty);

#endif //SCENICSPOTIMS_UTILITIES_H
