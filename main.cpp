#include <iostream>
#include <cstdio>
#include "MainView.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    MainView & mainView = MainView::getInstance();
    mainView.render();
    return 0;
}