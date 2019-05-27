#include "CEllipse.h"
#include "IDialogInitiable.h"
#include "IPhysObject.h"
#include "CTriangle.h"
#include "BaseCObject.h"

#include "iostream"
#include "vector"
#include "stdlib.h"
#include <algorithm>

using namespace std;

class CSystem{
private:
    vector<BaseCObject*> data;

public:

    void run(){
        int parser;

        while (true){
            cout << "Choose, what do you want to do" << endl;
            cout << "1. Add ellipse" << endl << "2. Add triangle" << endl << "3. Show all objects"
            << endl << "4. Get total area" << endl << "5. Get total perimeter" << endl << "6. Get center mass of system"
            << endl << "7. Get info about system" << endl << "8. Sort objects" << endl << "9. Exit" << endl;

            cin >> parser;
            bool cont = false;

            switch (parser){
                case 1:{
                    BaseCObject *ellipse = new CEllipse;

                    dynamic_cast<IDialogInitable *>(ellipse)->initFromDialog();
                    data.push_back(ellipse);

                    cont = true;
                    break;
                }

                case 2:{
                    BaseCObject *triangle = new CTriangle;
                    dynamic_cast<IDialogInitable *>(triangle)->initFromDialog();

                    data.push_back(triangle);

                    cont = true;
                    break;
                }

                case 3:{
                    drawAll();
                    cont = true;
                    break;
                }

                case 4:{
                    cout << "Total area: " << sumOfAreas() << endl;
                    cont = true;
                    break;
                }

                case 5:{
                    cout << "Total perimeter: " << sumOfPer() << endl;
                    cont = true;
                    break;
                }

                case 6:{
                    cout << "vector: {" << position().x << ";" << position().y << "}" << endl;
                    cont = true;
                    break;
                }

                case 7:{
                    listInfo();
                    cont = true;
                    break;
                }

                case 8:{
                    sort(data.begin(), data.end());
                    cont = true;
                    break;
                }

                case 9:{
                    return;
                }
            }

            if (!cont)return;
        }
    }

    CVector2D position(){
        CVector2D systemCenter(0,0);

        int count  = 0;

        for (auto it = data.begin(); it != data.end(); it++){
            systemCenter.x = dynamic_cast<IPhysObject *>(*it)->Position().x;
            systemCenter.y = dynamic_cast<IPhysObject *>(*it)->Position().y;

            count++;
        }

        if (count != 0){
            systemCenter.x /= count;
            systemCenter.y /= count;
        }

        return systemCenter;
    }

    long double sumOfAreas(){

        long double area = 0;

        for (auto it = data.begin(); it != data.end(); it++){
            area += dynamic_cast<IGeoFig *>(*it)->square();
        }

        return area;
    }

    long double sumOfPer(){
        long double per = 0;

        for (auto it = data.begin(); it != data.end(); it++){
            per += dynamic_cast<IGeoFig *>(*it)->perimeter();
        }

        return per;
    }

    void drawAll(){
        int counter = 0;

        for (auto it = data.begin(); it != data.end(); it++){
            cout << counter + 1 << ")" << endl;
            dynamic_cast<IPrintable *>(*it)->draw();
            counter++;
        }
    }

    void listInfo(){
        long unsigned long sumMemory = 0;

        if (data.empty()){
            cout << "I hasn't got data" << endl;
            return;
        }

        cout << "List data: " << endl;
        for (auto it = data.begin(); it != data.end(); it++) {

            cout << "Name: " << dynamic_cast<BaseCObject *>(*it)->classname()
                << " Size: " << dynamic_cast<BaseCObject *>(*it)->size() << endl;
            sumMemory += dynamic_cast<BaseCObject *>(*it)->size();
        }

        cout << "TOTAL MEMORY: " << sumMemory << endl;
    }

};

int main(){
    CSystem system;
    system.run();
}
