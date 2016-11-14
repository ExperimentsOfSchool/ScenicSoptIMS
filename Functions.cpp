//
// Created by QQ596 on 2016/11/14.
//

#include "Functions.h"
#include <iostream>
//using namespace std;

void Functions::setScenes(int v, int e) {
    vertices = v;
    edges = e;

    // set vertices
    std::cout << "请输入各个景点的名字:" << std::endl;
    scenes = new std::string[v];
    for(int i = 0; i < v; i++) {
        std::cin >> scenes[i];
    }
    for(int i = 0; i < v; i++) {
        std::cout << scenes[i] << std::endl;
    }
}
