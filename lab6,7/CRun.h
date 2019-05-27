#pragma once
#ifndef CPPLABS_SPRING_EXCEPTION_H
#define CPPLABS_SPRING_EXCEPTION_H

#include "CQueue.h"
#include "string"
#include "iostream"

using namespace std;

template <class T>
void swap_(T &a, T &b){
    T c = a;
    a = b;
    b = c;
}

template <class T, int max>
void run(CQueue<T, max>& queue){

    string parser;

    while (true){

        cin >> parser;

        if (parser.compare("exit") == 0)break;

        if (parser.compare("<<") == 0){
            T in;
            cin >> in;

            try {
                queue.push(in);
            }

            catch (outOfRange& err){
                cout << err.what() << endl;
            }
        }

        if (parser.compare(">>") == 0){
            try {
                T result = queue.poll();

                cout << "= " << result << endl;
            }

            catch (outOfRange& err){
                cout << err.what() << endl;
            }
        }

        if (parser.compare("show") == 0){
            try {
                T result = queue.pop();

                cout << "= " << result << endl;

            }

            catch (outOfRange& err){
                cout << err.what() << endl;
            }
        }

    }

    cout << "Do you want to swap something? (yes/no)" << endl;
    string pars;

    cin >> pars;

    if (pars.compare("yes") == 0){
        cout << "Enter values to swap" << endl;

        T first, second;

        cin >> first >> second;

        swap_(first, second);

        cout << "first: " << first << endl << "second: " << second << endl;
    }
}

#endif //CPPLABS_SPRING_EXCEPTION_H
