//
// Created by Denis on 20.04.2019.
//
#pragma once
#ifndef CPPLABS_SPRING_CVECTOR2D_H
#define CPPLABS_SPRING_CVECTOR2D_H

#include <math.h>

class CVector2D{
public:
    double x, y;

    CVector2D(double x, double y){
        this->x = x;
        this->y = y;
    }
};

#endif //CPPLABS_SPRING_CVECTOR2D_H
