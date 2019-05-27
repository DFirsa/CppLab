#include "vector"
#include "iostream"
#include "string"

#include "CQueue.h"
#include "CRun.h"

using namespace std;

int main(){

    int parser = 0;
    const int max = 3;

    while (parser < 1 || parser > 6){
        cout << "Choose data type for data structure" << endl << "1. int" << endl << "2. double"
            << endl << "3. float" << endl << "4. string" << endl << "5. bool" << endl
            << "6. char" << endl;

        cin >> parser;
    }

    cout << "Console: " << endl;

    switch (parser){
        case 1:{
            CQueue<int, max> queueInt;
            run(queueInt);
            break;
        }

        case 2:{
            CQueue<double, max> queueDouble;
            run(queueDouble);
            break;
        }

        case 3:{
            CQueue<float, max> queueFloat;
            run(queueFloat);
            break;
        }

        case 4:{
            CQueue<string, max> queueString;
            run(queueString);
            break;
        }

        case 5:{
            CQueue<bool, max> queueBool;
            run(queueBool);
            break;
        }

        case 6:{
            CQueue<char, max> queueChar;
            run(queueChar);
            break;
        }
    }
}

