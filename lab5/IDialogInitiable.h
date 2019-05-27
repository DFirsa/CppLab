//
// Created by Denis on 20.04.2019.
//
#pragma once
#ifndef CPPLABS_SPRING_IDIALOGINITIABLE_H
#define CPPLABS_SPRING_IDIALOGINITIABLE_H

class IDialogInitable{
public:
    // Задать параметры объекта с помощью диалога с пользователем.
    virtual void initFromDialog() = 0;
};

#endif //CPPLABS_SPRING_IDIALOGINITIABLE_H
