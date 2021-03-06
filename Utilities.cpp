//
// Created by Lawrence Lee on 18/11/2016.
//


#include "Utilities.h"

void setSpotList(ScenicSpot * spotList[], int &spotQty, int &roadQty) {
    std::cout << "请输入景点的个数与道路的个数" << std::endl;
    std::cin >> spotQty >> roadQty;
    std::string spotName;
    std::string spotInfo;
    std::cout << "请输入景点的名称和简介" << std::endl;
    srand((unsigned)time(0));
    for(int i = 0; i < spotQty; i++) {
        std::cin >> spotName;
        std::cin >> spotInfo;
        spotList[i] = new ScenicSpot(spotName, i, rand() % 11, spotInfo);
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

    std::cout.width(8);
    std::cout << "";
    const int * weights;
    for(int i = 0; i < spotQty; i++) {
        std::cout.setf(std::ios::left);
        std::cout.width(12);
        std::cout << spotList[i]->getSceneName();
    }
    std::cout << std::endl;
    for(int i = 0; i < spotQty; i++) {
        std::cout.width(12);
        std::cout << spotList[i]->getSceneName();
        weights = spotList[i] -> getWights();
        for(int j = 0; j < spotQty; j++) {
            std::cout.setf(std::ios::left);
            std::cout.width(8);
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
            if(!spotList[index]->isVisited()) {
                spotList[index]->visit();
                std::cout << spotList[index]->getSceneName() << "\t";
            }
            printTravelRoute(spotList, i, spotQty);
        }
    }
    if(!spotList[index]->isVisited()) {
        std::cout << spotList[index]->getSceneName() << "\t";
        spotList[index]->visit();
    }
}

void getShortestPath(ScenicSpot * spotList[], const int spotQty, const int roadQty) {
    std::string spotA, spotB;
    int indexA = -1, indexB = -1;
    std::cout << "请输入要查询的两个景点的名称" << std::endl;
    std::cin >> spotA >> spotB;
    for(int i = 0; i < spotQty; i++) {
        if(spotList[i]->getSceneName() == spotA) indexA = i;
        if(spotList[i]->getSceneName() == spotB) indexB = i;
    }
    if(indexA == -1 || indexB == -1) {
        std::cout << "找不到景点！" << std::endl;
        return;
    }

    // Initialization

    int S[20] = {0};
    int dist[20] = {0};
    int path[20] = {0};
    int minDist = 32767;
    int minIndex = -1;
    for(int i = 0; i < spotQty; i++) {
        const int * weight = spotList[indexA]->getWights();
        if(i != indexA) {
            if (weight[i] == 0) dist[i] = 32767;
            else dist[i] = weight[i];
            S[i] = 0;
            path[i] = indexA;
        } else {
            dist[i] = 0;
            S[i] = 1;
            path[i] = i;
        }
//        std::cout << dist[i] << std::endl;
    }

    // Dijkstra

    for(int i = 0; i < spotQty; i++) {
        for(int j = 0; j < spotQty; j++) {
            if(!S[j]) {
                if(dist[j] < minDist) {
                    minDist = dist[j];
                    minIndex = j;
                }
            }
        }
        for(int j = 0; j < spotQty; j++) {
            if(!S[j]) {
                for(int k = 0; k < spotQty; k++) {
                    if(j == k || S[j]) continue;
                    if(dist[j] + spotList[j]->getWights()[k] < minDist) {
                        minDist = dist[j] + spotList[j]->getWights()[k];
                        minIndex = j;
                    }
                }
            }
            S[minIndex] = 1;
        }
        for(int k = 0; k < spotQty; k++) {
            if(S[k]) continue;
            if(dist[k] > dist[minIndex] + spotList[minIndex]->getWights()[k]) {
                dist[k] = dist[minIndex] + spotList[minIndex]->getWights()[k];
                path[k] = minIndex;
            }
        }
        minDist = 32767;
        minIndex = -1;
//        for(int j = 0; j < spotQty; j++) {
//            std::cout << dist[j] << ", ";
//            std::cout << path[j] << ", ";
//        }
//        std::cout << std::endl;
    }
    std::cout << "最短路径为：" << std::endl;
    std::cout << spotA << " ";
    int way[20], j = 0;
    for(int i = indexB; path[i] != indexA; j++) {
        way[j] = path[i];
        i = path[path[i]];
    }
    for(int i = j; i >= 0 && j != 0; i--) {
        std::cout << spotList[way[i]]->getSceneName() << " ";
    }
    std::cout << spotB << std::endl;
    std::cout << "最短路径长度：" << dist[indexB] << std::endl;
}

void findScenicSpot(ScenicSpot * spotList[], const int spotQty) {
    std::string input;
    std::cout << "请输入要查找的景点：" << std::endl;
    std::cin >> input;
    for(int i = 0; i < spotQty; i++) {
        if(spotList[i]->getSceneName().find(input, 0) != std::string::npos || spotList[i]->getSceneInfo().find(input, 0) != std::string::npos) {
            std::cout << "找到景点！" << std::endl;
            spotList[i]->printSceneInfo();
            return;
        }
    }
    std::cout << "未找到相关景点信息！" << std::endl;

}

int compare(const void *a, const void *b) {
    int result = ((ScenicSpot*)b)->getWelcomeRate() - ((ScenicSpot*)a)->getWelcomeRate();
    return result;
}
void getRankedList(ScenicSpot * spotList[], const int spotQty) {
    // TODO: Generate Ranked List
    ScenicSpot * (rankedSpotList)[100];
    for(int i = 0; i < spotQty; i++) {
        rankedSpotList[i] = new ScenicSpot(spotList[i]);
    }
    qsort(rankedSpotList, spotQty, sizeof(rankedSpotList[0]), compare);
    for(int i = 0; i < spotQty; i++) {
        std::cout << i + 1 << ". " << rankedSpotList[i]->getSceneName() << std::endl;
    }
}

