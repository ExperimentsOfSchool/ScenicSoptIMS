//
// Created by Lawrence Lee on 14/11/2016.
//

#ifndef SCENICSPOTIMS_MAINVIEW_H
#define SCENICSPOTIMS_MAINVIEW_H


class MainView {
public:
    static MainView & getInstance() {
        static MainView instance;
        return instance;
    }
    void render();
private:
    MainView() {

    }
    MainView(MainView const &); // for cutting off.
    void operator = (MainView const &);
//
//public:
//    MainView(MainView const &) = delete;
//    void operator = (MainView const &) = delete;
//
};

#endif //SCENICSPOTIMS_MAINVIEW_H
