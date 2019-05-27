#include "Menu.h"
#include "iostream"
#include "Circle.h"
#include "Ellipse.h"

using namespace std;

void Menu::circleRun(){
    double rad;
    bool backEnable = false;

    cout << "Enter circle radius: " << endl;
    cin >> rad;

    Circle circle(rad);

    while (!backEnable){
        int parser;

        cout << "Choose function: (Enter number)" << endl;
        cout << "1. Add section line" << endl << "2. Get sector area" << endl << "3. Get sector perimeter"
        << endl << "4. Delete section line" << endl << "5. Get section perimeter" << endl << "6. Get section area"
        << endl << "7. Check contains point" << endl << "8. Get area" << endl << "9. Get perimeter"<< endl << "10. Rotation"
        << endl << "11. Show points" << endl << "12. Back" << endl;

        cin >> parser;

            switch (parser){
                case 1: {
                    double k, b;
                    circle.deleteSectionLine();
                    cout << "Enter line parameters k  and b (line: y = kx + b)" << endl;
                    cin >> k >> b;
                    Line line(k, b);
                    circle.addSectionLine(line);
                    break;
                }
                case 2: {
                    double alpha;
                    cout << "Enter degrees of sector" << endl;
                    cin >> alpha;
                    cout << circle.getSectorArea(alpha) <<  endl;
                    break;
                }
                case 3:{
                    double alpha;
                    cout << "Enter degrees of sector" << endl;
                    cin >> alpha;
                    cout << circle.getSectorPer(alpha) <<  endl;
                    break;
                }
                case 4:{
                    circle.deleteSectionLine();
                    break;
                }
                case 5:{
                    if (circle.hasSectionLine_()){
                        cout << "circle hasn't got section line";
                    }
                    else{
                        cout << "Per of big part of section: "<< circle.countPerBySection() << endl
                        << "Per of small part of section: " << circle.getPer() - circle.countPerBySection()
                        << endl;
                    }
                    break;
                }
                case 6:{
                    if (circle.hasSectionLine_()){
                        cout << "circle hasn't got section line";
                    }
                    else{
                        cout << "Area of big part of section: "<< circle.countAreaBySection() << endl
                             << "Per of small part of section: " << circle.getArea() - circle.countAreaBySection()
                             << endl;
                    }
                    break;
                }
                case 7:{
                    break;
                }
                case 8:{
                    cout << circle.getArea() << endl;
                    break;
                }
                case 9:{
                    cout << circle.getPer() << endl;
                    break;
                }
                case 10:{
                    double degrees;
                    cout << "Enter rotation degrees" << endl;
                    cin >> degrees;
                    circle.rotateOn(degrees);
                    break;
                }
                case 11:{
                    int countPoints;
                    cout << "Enter count of basics points" << endl;
                    cin >> countPoints;
                    vector<Point> points = circle.getBasicsPoints(countPoints);

                    for (int i = 0 ; i < countPoints; i++){
                        cout << "(" << points.back().x << ", " << points.back().y << ")" << endl;
                        points.pop_back();
                    }
                    break;
                }
                case 12:{
                    backEnable = true;
                    break;
                }
            }
    }
}

void Menu::ellipseRun() {
    double a,b;
    bool backEnable = false;

    cout << "Ellipse: x^2/a^2 + y^2/b^2 = 1" << endl <<"Enter ellipse parameters: " << endl;
    cin >> a >> b;

    Ellipse ellipse(a,b);

    while(!backEnable){
        int parser;
        cout << "Choose function: (Enter number)" << endl;
        cout << "1. Get area" << endl << "2. Get perimeter" << "3. Rotation"  << endl << "4. Show points" << endl <<"5. Back" << endl;

        cin >> parser;

        switch (parser){
            case 1:{
                cout << ellipse.getArea() << endl;
                break;
            }
            case 2:{
                cout << ellipse.getPer() << endl;
                break;
            }
            case 3:{
                double degrees;

                cout << "Enter degrees rotation" << endl;
                cin >> degrees;
                ellipse.rotateOn(degrees);
                break;
            }
            case 4:{
                int countPoints;
                cout << "Enter count of basics points" << endl;
                cin >> countPoints;
                vector<Point> points = ellipse.getBasicsPoints(countPoints);

                for (int i = 0 ; i < countPoints; i++){
                    cout << "(" << points.back().x << ", " << points.back().y << ")" << endl;
                    points.pop_back();
                }
            }
            case 5:{
                backEnable = true;
                break;
            }
        }
    }
}

void Menu::firstLevel(){
    int parseComand;

    cout << "What do you want to use? (Enter number)" << endl;

    cout << "1. Ellipse" << endl << "2. Circle" << endl <<"3. Exit" << endl;

    cin >> parseComand;

    if (parseComand == 1) ellipseRun();
    else{
        if (parseComand == 2) circleRun();
        else closeEnable = true;
    }
}

void Menu::runProgram() {
    while (!closeEnable) firstLevel();
}