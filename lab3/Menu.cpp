#include "Complex.h"
#include "string"
#include "Menu.h"
#include "iostream"

using namespace std;

void Menu::showNumbers(Complex &complex1, Complex &complex2) {
    cout << "first : ";
    complex1.print();
    cout << endl << "second : ";
    complex2.print();
    cout << endl;
}

Complex Menu::enterOperand(bool isFirst) {
    string name;
    if (isFirst) name = "first";
    else name = "second";

    float re, im;

    cout << "Enter real part of " << name << " operand :" << endl;
    cin >> re;
    cout << "Enter imagine part of " << name << " operand :" << endl;
    cin >> im;
    cout << endl;

    Complex result(re,im);
    return result;
}

void Menu::run() {
    string cmd;

    while (true){
        if (cmd.compare("new"))cin >> cmd;

        if(!cmd.compare("new")){

            Complex first = enterOperand(true);
            Complex second = enterOperand(false);

            while (true){

                showNumbers(first,second);

                cin >> cmd;
                bool isFind = false;

                if (!cmd.compare("length")){
                    isFind = true;
                    cout << endl << "Length of first: " << first.getLength() << endl;
                    cout << "Length of second: "<< second.getLength() << endl << endl;
                }

                if (!cmd.compare("Sum")){
                    isFind = true;
                    Complex result = first.sum(second);
                    cout << "= ";
                    result.print();
                    cout << endl;
                }

                if (!cmd.compare("Mult")){
                    isFind = true;
                    Complex result = first.multiply(second);
                    cout << "= ";
                    result.print();
                    cout << endl;
                }

                if (!cmd.compare("Mult_Const")){
                    isFind = true;
                    float const_;
                    cout << "Enter const" << endl;
                    cin >> const_;

                    Complex res = first.multConst(const_);
                    cout << "Result of multiplying first complex on constant = ";
                    res.print();
                    cout << endl;

                    res = second.multConst(const_);
                    cout << "Result of multiplying second complex on constant = ";
                    res.print();
                    cout << endl;
                }

                if (!isFind)break;
            }
            if (!cmd.compare("STOP"))break;
        }

    }
}