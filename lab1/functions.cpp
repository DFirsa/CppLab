#include <iostream>
#include "functions.h"
#include "math.h"
#include "stdio.h"


void changeValue_pointer(int *first, int *second){
    if (*first > *second) *first %= *second;
    else *second %= *first;
};

void round_pointer(double *number){
    *number = round(*number);
};

void decreaseRad_pointer(circle *circle, int delta){
    if (circle->r > delta) circle->r -= delta;
    else circle->r = 0;
};

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
};

void trans_pointer(int *matrix){
    swap(&matrix[3],&matrix[1]);
    swap(&matrix[2],&matrix[6]);
    swap(&matrix[5],&matrix[7]);
};

void changeValue_link(int &first, int &second){
    if (first > second) first %= second;
    else second %= first;
};

void round_link(double &number){
    number = round(number);
};

void decreaseRad_link(circle &circle, int delta){
    if (circle.r > delta) circle.r -= delta;
    else circle.r = 0;
};

void trans_link(int &matrix){
    int *i = &matrix + 1;
    int *j = &matrix + 3;
    swap(i,j);

    i = &matrix + 2;
    j = &matrix + 6;
    swap(i,j);

    i = &matrix + 5;
    j = &matrix + 7;
    swap(i,j);
};