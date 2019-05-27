//
// Created by Denis on 25.02.2019.
//

#ifndef CPPLABS_SPRING_TYPES_H
#define CPPLABS_SPRING_TYPES_H

#include "string"

struct complex {
    double real;
    double imagine;
};

struct stack {
    int top = -1;
    int arr[100];

    bool isEmpty();
};

typedef struct complex complex;
typedef struct stack stack;

complex multConst(complex &complex_, int const_);

complex complSum(complex &complex1, complex &complex2);

complex complMult(complex &complex1, complex &complex2);

void complexPrint(complex &complex_);

void inputComplex(complex &complex_);

double complLength(complex &complex_);

complex operator +(complex &complex_, complex &complex1);

complex operator *(complex &complex_, complex &complex1);

complex operator *(complex &complex_, int num);

void operator <<(stack &stack_, int value);

int operator >>(stack &stack_, bool debugMod);

//int operator>>()

#endif //CPPLABS_SPRING_TYPES_H

