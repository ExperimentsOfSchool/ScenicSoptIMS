//
// Created by Lawrence Lee on 18/11/2016.
//

#include "ScenicSpot.h"

ScenicSpot::ScenicSpot(std::string spotName, int id) {
    sceneName = spotName;
    sceneID = id;
    visited = false;
    for(int i = 0; i < 100; i++) {
        weights[i] = 32767;
    }
}
ScenicSpot::ScenicSpot(const ScenicSpot &other) {
    sceneName = other.sceneName;
    sceneID = other.sceneID;
    for(int i = 0; i < 100; i++) {
        weights[i] = other.weights[i];
    }
    visited = false;
}

const std::string &ScenicSpot::getSceneName() const {
    return sceneName;
}

int ScenicSpot::getSceneID() const {
    return sceneID;
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