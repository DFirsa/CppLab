//
// Created by Denis on 20.04.2019.
//
#pragma once
#ifndef CPPLABS_SPRING_IPHYSOBJECT_H
#define CPPLABS_SPRING_IPHYSOBJECT_H

#include "CVector2D.h"

class IPhysObject{
public:
    virtual double mass() =0;           //Масса, кг
    virtual CVector2D Position() =0;    //Координаты центра масс, м

    virtual bool operator==(IPhysObject& ob) = 0;
    virtual bool operator<(IPhysObject& ob)  = 0;    //сравнение по массе
};

#endif //CPPLABS_SPRING_IPHYSOBJECT_H
