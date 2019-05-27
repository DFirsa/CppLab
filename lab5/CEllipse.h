//
// Created by Denis on 20.04.2019.
//
#pragma once
#ifndef CPPLABS_SPRING_CELLIPSE_H
#define CPPLABS_SPRING_CELLIPSE_H

#include "IGeoFig.h"
#include "IPhysObject.h"
#include "IPrintable.h"
#include "BaseCObject.h"
#include "IDialogInitiable.h"

#include "iostream"
#include <math.h>

class CEllipse: public IGeoFig, public IPrintable, public IPhysObject, public BaseCObject, public IDialogInitable{
private:
    double a;
    double b;
    double density;
    CVector2D position;

public:

    CEllipse()
    :a(1),
    b(1),
    density(0),
    position(CVector2D(0,0))
    {
    }

    CEllipse(double a_, double b_, double density_, const CVector2D& vectorPos)
    :a(a_),
    b(b_),
    density(density_),
    position(vectorPos)
    {
    }

    void initFromDialog(){
        double a, b, density;
        std::cout << "Enter parameters of ellipse: " << std::endl;
        std::cin >> a >> b;
        std::cout << "Enter density of this object: " << std::endl;
        std::cin >> density;

        this->a = a;
        this->b = b;
        this->density = density;
    }

    double perimeter() {
        return (2*M_PI*sqrt((pow(a,2) + pow(b,2))/2));
    }

    double square(){
        return (M_PI*a*b);
    }

    void draw(){
        std::cout << "Ellipse:" << std::endl;
        std::cout << "Parameter a : " << a << std::endl;
        std::cout << "Parameter b : " << b << std::endl;
    }

    double mass(){
        return square()*density;
    }

    CVector2D Position(){
        return position;
    }

    const char* classname(){
        return "CEllipse";
    }

    unsigned int size(){
        return sizeof(CEllipse);
    }

    bool operator==(IPhysObject& ob){
        if (this->mass() != ob.mass())return false;

        return (this->Position().x == ob.Position().x
                    && this->Position().y == ob.Position().y);
    }

    bool operator<(IPhysObject& ob){
        return (this->mass() < ob.mass());
    }

};

#endif //CPPLABS_SPRING_CELLIPSE_H
