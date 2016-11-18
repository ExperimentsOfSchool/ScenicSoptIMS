//
// Created by Lawrence Lee on 18/11/2016.
//

#include <iostream>
#include "ScenicSpot.h"
#include "Utilities.h"

void renderMenu();

int main() {
    int selection;
    ScenicSpot* (spotList)[100];
    int spotQty, roadQty;
    do {
        renderMenu();
        std::cin >> selection;
        switch(selection) {
            case 1:
                setSpotList(spotList, spotQty, roadQty);
                break;
            case 2:
                printSpotList(spotList, spotQty, roadQty);
                break;
            case 3:
                printTravelRoute(spotList, 0, spotQty);
            std::cout << std::endl;
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:;
        }
    } while(selection != 0);
}

void renderMenu() {
    std::cout << "请选择功能" << std::endl;
    std::cout << "1. 创建景区景点分布图" << std::endl;
    std::cout << "2. 输出景区景点分布图" << std::endl;
    std::cout << "3. 输出导游线路图" << std::endl;
    std::cout << "4. 输出导游线路图中的回路" << std::endl;
    std::cout << "5. 求两个景点的最短路径和最短距离" << std::endl;
    std::cout << "6. 输出道路修建规划图" << std::endl;
    std::cout << "7. 停车场车辆进出信息" << std::endl;
    std::cout << "0. 退出系统" << std::endl;
}