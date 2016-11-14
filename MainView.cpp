//
// Created by Lawrence Lee on 14/11/2016.
//

#include "MainView.h"
//#include <stdio.h>
#include <iostream>
using namespace std;
//MainView *MainView::getInstance() {
//    if(mainView == nullptr)
//        mainView = new MainView();
//    return mainView;
//}

void MainView::render() {
    cout << "1. 创建景区景点分布图" << endl;
    cout << "2. 输出景区景点分布图" << endl;
    cout << "3. 输出导游线路图" << endl;
    cout << "4. 输出导游线路图中的回路" << endl;
    cout << "5. 求两个景点间的最短路径和最短距离" << endl;
    cout << "6. 输出道路修建规划图" << endl;
    cout << "7. 停车场车辆进出记录信息" << endl;
    cout << "0. 退出系统" << endl;
}