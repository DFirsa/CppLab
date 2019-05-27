//
// Created by Denis on 02/20/2019.
//  1,  5

#include <iostream>
#include "stdio.h"
#include "types.h"

using namespace std;

int main() {

    cout << " === COMPLEX === " << endl;

    complex com, com_, sum, mult, multC;
    int num;
    double length;

    inputComplex(com);
    cout << "Enter number for multiply: ";
    cin >> num;
    cout << endl;

    multC = com * num;
    cout << "Result of multiply first complex on const: ";
    complexPrint(multC);

    length = complLength(com);
    cout << "Length of complex number is " << length << endl;

    inputComplex(com_);

    sum = com + com_;
    cout << "Result of addition first and second complex numbers: ";
    complexPrint(sum);

    mult = com * com_;
    cout << "Result of multiply first and second complex numbers: ";
    complexPrint(mult);

    cout << " === STACK === " << endl;

    stack stack1;

    string cmd;
    bool debugMod = false;
    int data;

    while (true) {
        cin >> cmd;
        cout << endl;

        if (!cmd.compare("debugMod_ON"))debugMod = true;
        if (!cmd.compare("debugMod_OFF"))debugMod = false;

        if (!cmd.compare("STOP"))break;

        if (!cmd.compare("<<")) {
            cin >> data;
            stack1 << data;
        }

        if (!cmd.compare(">>")) {
            if (!stack1.isEmpty()) stack1 >> debugMod;
            else cout << "STACK IS EMPTY";
            cout << endl;
        }
    }


}