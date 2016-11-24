//
// Created by Lawrence Lee on 18/11/2016.
//

#ifndef SCENICSPOTIMS_SCENICSPOT_H
#define SCENICSPOTIMS_SCENICSPOT_H
#include <string>
#include <cstdlib>
#include <iostream>

class ScenicSpot {
private:
    std::string sceneName;
    std::string sceneInfo;
    int sceneID;
    int weights[100];
    bool visited;
    int welcomeRate;
public:
    ScenicSpot(std::string spotName, int id, int wRate, std::string spotInfo);
    ScenicSpot(const ScenicSpot * other);

    void setWeight(int index, int weight);

    const std::string &getSceneName() const;
    const std::string &getSceneInfo() const;

    const int *getWights() const;
    const bool isVisited() const;
    const int getWelcomeRate() const;

    void printSceneInfo();
    void visit();



};


#endif //SCENICSPOTIMS_SCENICSPOT_H
