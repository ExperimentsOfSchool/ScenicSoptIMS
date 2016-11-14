//
// Created by QQ596 on 2016/11/14.
//

#ifndef SCENICSPOTIMS_FUNCTIONS_H
#define SCENICSPOTIMS_FUNCTIONS_H
#include <string>
using namespace std;
class Functions {
private:
    static string * scenes;
    static int vertices;
    static int edges;
public:
    static void setScenes(int v, int e);
};


#endif //SCENICSPOTIMS_FUNCTIONS_H
