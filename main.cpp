#include <iostream>
#include "MainView.h"
#include "Functions.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    MainView & mainView = MainView::getInstance();
    mainView.render();
    Functions::setScenes(5, 5);
    return 0;
}