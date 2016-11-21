//
// Created by Lawrence Lee on 18/11/2016.
//

#ifndef SCENICSPOTIMS_SCENICSPOT_H
#define SCENICSPOTIMS_SCENICSPOT_H
#include <string>

class ScenicSpot {
private:
    std::string sceneName;
    int sceneID;
    int weights[100];
    bool visited;
public:
    ScenicSpot(std::string spotName, int id);
    ScenicSpot(const ScenicSpot &other);

    void setWeight(int index, int weight);

    const std::string &getSceneName() const;

    int getSceneID() const;

    const int *getWights() const;
    const bool isVisited() const;
    void visit();

};


#endif //SCENICSPOTIMS_SCENICSPOT_H
