//
// Created by Denis on 20.04.2019.
//
#pragma once
#ifndef CPPLABS_SPRING_CTRIANGLE_H
#define CPPLABS_SPRING_CTRIANGLE_H

#include "BaseCObject.h"
#include "IPrintable.h"
#include "IPhysObject.h"
#include "IGeoFig.h"
#include "IDialogInitiable.h"

#include "iostream"
#include <math.h>
#include "stdlib.h"

class CTriangle: public IGeoFig, public  IPrintable, public IPhysObject, public BaseCObject, public IDialogInitable{
private:

    double density;
    double sideLength;
    CVector2D position;

public:

   CTriangle()
   :sideLength(0),
   position(CVector2D(0,0)),
   density(0)
   {
   }

   CTriangle(double sideLength_, const CVector2D& vectorPosition, double density_)
   :sideLength(sideLength_),
   position(vectorPosition),
   density(density_)
   {
   }

   void initFromDialog(){
       double x, y, density, length;
       std::cout << "Enter parameters of position vector: " << std::endl;
       std::cin >> x >> y;
       std::cout << "Enter length of sides: " << std::endl;
       std::cin >> length;
       std::cout << "Enter density of this object: " << std::endl;
       std::cin >> density;

       this->sideLength = length;
       this->position.x = x;
       this->position.y = y;
       this->density = density;
   }

    double square() {
        return (pow(sideLength,2)*(sqrt(3)/4));
    }

    double perimeter() {
        return (3*sideLength);
    }

    void draw(){
        std::cout << "Triangle:" << std::endl;
        std::cout << "Length of side is " << sideLength << std::endl;
        std::cout << "Vector of position is (" << position.x << ";" << position.y << ")" << std::endl;
    }

    double mass(){
        return square()*density;
   }

    CVector2D Position(){
        return this->position;
   }

   unsigned int size(){
        return sizeof(CTriangle);
   }

   const char* classname(){
       return "CTriangle";
   }

   bool operator== (IPhysObject& ob){
       if (this->mass() != ob.mass())return false;
       return (this->Position().x == ob.Position().x
                && this->Position().y == ob.Position().y);
   }

   bool operator< (IPhysObject& ob){
       return (this->mass() < ob.mass());
   }

};

#endif //CPPLABS_SPRING_CTRIANGLE_H
