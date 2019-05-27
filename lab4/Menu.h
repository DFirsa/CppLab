//
// Created by Denis on 08.04.2019.
//

#ifndef CPPLABS_SPRING_MENU_H
#define CPPLABS_SPRING_MENU_H


class Menu {
private:
    bool closeEnable;

    void firstLevel();

    void circleRun();

    void ellipseRun();

public:
    Menu(){
        closeEnable = false;
    }

    void runProgram();
};


#endif //CPPLABS_SPRING_MENU_H
