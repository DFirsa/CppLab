#include <iostream>
#include "types.h"
#include "math.h"

using namespace std;

complex multConst(complex &complex_, int const_) {
    complex res;
    res.real = complex_.real * const_;
    res.imagine = complex_.imagine * const_;
    return res;
}

complex complSum(complex &complex1, complex &complex2) {
    complex res;
    res.imagine = complex1.imagine + complex2.imagine;
    res.real = complex1.real + complex2.real;
    return res;
}

complex complMult(complex &complex1, complex &complex2) {
    complex res;
    res.imagine = (complex2.real * complex1.imagine) + (complex1.real * complex2.imagine);
    res.real = (complex1.real * complex2.real) - (complex1.imagine * complex2.imagine);
    return res;
}

void complexPrint(complex &complex_){
    cout << complex_.real;
    if(complex_.imagine > 0)cout << "+";
    cout << complex_.imagine << "i" << endl;
}

void inputComplex(complex &complex_){
    cout << "Enter real part of complex number:" << endl;
    cin >> complex_.real;
    cout << endl << "Enter imagine part of complex number:" << endl;
    cin >> complex_.imagine;
}

double complLength(complex &complex_) {
    double length;
    length = sqrt(complex_.imagine * complex_.imagine + complex_.real * complex_.real);
    return length;
}

complex operator +(complex &complex_, complex &complex1){
    complex result = complSum(complex_,complex1);
    return result;
}

complex operator *(complex &complex_, complex &complex1){
    complex result = complMult(complex1, complex_);
    return result;
}

complex operator *(complex &complex_, int num){
    complex result = multConst(complex_, num);
    return result;
}



void operator <<(stack &stack_, int value) {
    stack_.top++;
    if (stack_.top >= sizeof(stack_.arr)){
        cout << endl << "Stack overflow error" << endl;
        return;
    }
    stack_.arr[stack_.top] = value;
}

int operator >>(stack &stack_, bool debugMod) {
    int val = stack_.arr[stack_.top];
    stack_.top--;
    if (debugMod)cout << val << endl;
    return val;
}

bool stack::isEmpty() {
    if (top < 0)return true;
    else return false;
}