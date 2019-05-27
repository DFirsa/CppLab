#include <iostream>
#include "functions.h"
using namespace std;

int main() {

//    third task
    int a,b,a_copy, b_copy;

    cout << " __Third task__" << endl << endl;
    cout << "Enter two value:" << endl;

    cin >> a >> b;

    a_copy = a;
    b_copy = b;

    changeValue_pointer(&a, &b);
    cout << "New values (pointer version): " << a << " " << b << endl;
    a = a_copy;
    b = b_copy;
    changeValue_link(a,b);
    cout << "New values (link version): " << a << " " << b << endl << endl;

//    sixth task
    double value, copy;

    cout << " __Sixth task__" << endl << endl;
    cout << "Enter float value:" << endl;

    cin >> value;

    copy = value;
    round_pointer(&value);
    cout << "Rounded value (pointer version): " << value << endl;

    value = copy;
    round_link(value);
    cout << "Rounded value (link version): " << value << endl << endl;

    //    eleventh task
    circle circle;
    int decrease;

    cout << " __Eleventh task__" << endl << endl;
    cout << "Enter circle radius and decrease value:" << endl;

    cin >> circle.r >> decrease;

    copy = circle.r;
    decreaseRad_pointer(&circle, decrease);
    cout << endl << "New radius (pointer version): " << circle.r << endl;

    circle.r = copy;
    decreaseRad_link(circle, decrease);
    cout << "New radius (link version): " << circle.r << endl << endl;

    //    fourteenth task
    int matrix[9];
    int matrix_l[9];

    cout << " __Fourteenth task__" << endl << endl;
    cout << "Enter matrix:" << endl;

    for (int i = 0; i < 9; i++){
        cin >> matrix[i];
        matrix_l[i] = matrix[i];
    }

    trans_pointer(matrix);
    cout << "Transposed matrix (pointer version): " << endl;
    for (int i = 0; i < 9; i++){
        cout << matrix[i] << " ";
        if ((i + 1) % 3 == 0) cout << endl;
    }
    cout << endl;

    trans_link(*matrix_l);
    cout << "Transposed matrix (link version): " << endl;
    for (int i = 0; i < 9; i++){
        cout << matrix_l[i] << " ";
        if ((i + 1) % 3 == 0) cout << endl;
    }

    return 0;
}