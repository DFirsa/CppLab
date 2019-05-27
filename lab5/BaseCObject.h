//
// Created by Denis on 20.04.2019.
//
#pragma once
#ifndef CPPLABS_SPRING_BASECOBJECT_H
#define CPPLABS_SPRING_BASECOBJECT_H

class BaseCObject{
public:
    virtual const char* classname() = 0; //Имя класса
    virtual unsigned int size() = 0;     //Размер занимаемой памяти
};

#endif //CPPLABS_SPRING_BASECOBJECT_H
