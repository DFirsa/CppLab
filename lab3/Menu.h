#pragma once

#ifndef CPPLABS_SPRING_MENU_H
#define CPPLABS_SPRING_MENU_H

#include "string"
#include "Complex.h"

class Menu{
public:

    void showNumbers(Complex &complex1, Complex &complex2);

    Complex enterOperand(bool isFirst);

    void run();
};

#endif //CPPLABS_SPRING_MENU_H
