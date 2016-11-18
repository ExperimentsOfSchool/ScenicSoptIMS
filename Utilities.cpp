//
// Created by Lawrence Lee on 18/11/2016.
//


#include "Utilities.h"

void setSpotList(ScenicSpot * spotList[], int &spotQty, int &roadQty) {
    std::cout << "请输入景点的个数与道路的个数" << std::endl;
    std::cin >> spotQty >> roadQty;
    std::string spotName;
    std::cout << "请输入景点的名称" << std::endl;
    for(int i = 0; i < spotQty; i++) {
        std::cin >> spotName;
        spotList[i] = new ScenicSpot(spotName, i);
    }
    for(int i = 0; i < roadQty; i++) {
        std::cout << "请输入第 " << i+1 << " 条道路的起点终点和距离" << std::endl;
        std::string spotA, spotB;
        int indexA, indexB, weight;
        std::cin >> spotA >> spotB >> weight;
        if((indexA = find(spotList, spotA, spotQty)) == -1)
            { std::cout << "找不到景点！" << std:: endl; i--; continue; }
        if((indexB = find(spotList, spotB, spotQty)) == -1)
            { std::cout << "找不到景点！" << std:: endl; i--; continue; }
        spotList[indexA] -> setWeight(indexB, weight);
        spotList[indexB] -> setWeight(indexA, weight);
    }
}

void printSpotList(ScenicSpot * spotList[], const int spotQty, const int roadQty) {

    std::cout.width(7);
    std::cout << "";
    const int * weights;
    for(int i = 0; i < spotQty; i++) {
        std::cout.setf(std::ios::left);
        std::cout.width(7);
        std::cout << spotList[i]->getSceneName();
    }
    std::cout << std::endl;
    for(int i = 0; i < spotQty; i++) {
        std::cout.width(7);
        std::cout << spotList[i]->getSceneName();
        weights = spotList[i] -> getWights();
        for(int j = 0; j < spotQty; j++) {
            std::cout.setf(std::ios::left);
            std::cout.width(7);
            std::cout << weights[j];
        }
        std::cout << std::endl;
    }

}

int find(ScenicSpot * spotList[], std::string spotName, const int spotQty) {
    for(int i = 0; i < spotQty; i++) {
        if(spotList[i]->getSceneName() == spotName) return i;
    }
    return -1;
}

void printTravelRoute(ScenicSpot * spotList[], const int index, const int spotQty) {
    const int * weights = spotList[index]->getWights();
    for(int i = index + 1; i < spotQty; i++) {
        if(weights[i]) {
            std::cout << spotList[index]->getSceneName() << "\t";
            printTravelRoute(spotList, i, spotQty);
        }
    }
    std::cout << spotList[index]->getSceneName() << "\t";
}