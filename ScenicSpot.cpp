//
// Created by Lawrence Lee on 18/11/2016.
//

#include "ScenicSpot.h"

ScenicSpot::ScenicSpot(std::string spotName, int id, int wRate, std::string spotInfo) {
    sceneName = spotName;
    sceneInfo = spotInfo;
    sceneID = id;
    visited = false;
    for(int i = 0; i < 100; i++) {
        weights[i] = 32767;
    }
    welcomeRate = wRate;
}
ScenicSpot::ScenicSpot(const ScenicSpot * other) {
    sceneName = other->sceneName;
    sceneID = other->sceneID;
    for(int i = 0; i < 100; i++) {
        weights[i] = other->weights[i];
    }
    visited = false;
    welcomeRate = other->welcomeRate;
}

const std::string &ScenicSpot::getSceneName() const {
    return sceneName;
}

const std::string &ScenicSpot::getSceneInfo() const {
    return sceneInfo;
}

const int *ScenicSpot::getWights() const {
    return weights;
}

void ScenicSpot::setWeight(int index, int weight) {
    weights[index] = weight;
}

const bool ScenicSpot::isVisited() const {
    return visited;
}
void ScenicSpot::visit() {
    visited = true;
}

const int ScenicSpot::getWelcomeRate() const {
    return welcomeRate;
}

void ScenicSpot::printSceneInfo() {
    std::cout << "景点名称：" << sceneName << std::endl;
    std::cout << "景点欢迎度：" << welcomeRate << std::endl;
    std::cout << "景点简介:" << sceneInfo << std::endl;
}