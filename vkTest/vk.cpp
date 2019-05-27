#include "iostream"
#include "math.h"
#include "unordered_set"
#include "vector"

using namespace std;

int testNum = 0;

int getCommonElementsNumber(const vector<int>& first,
                            const vector<int>& second){

    const vector<int>& shortest = first.size() >  second.size() ? second : first;
    const vector<int>& longest  = first.size() <= second.size() ? second : first;

    unordered_set<int> uniqueElements;

    for (const auto& el : shortest){
        uniqueElements.insert(el);
    }

    int result = 0;
    for (const auto& el : longest){
        if (uniqueElements.empty()) break;
        if (uniqueElements.find(el) != uniqueElements.end()){
            result++;
            uniqueElements.erase(el);
        }
    }

    return result;
}

void executeTest(const vector<int>& v1,
                 const vector<int>& v2,
                 const int expectedOutput) {

    testNum++;

    cout << "Test " << testNum;
    int result = getCommonElementsNumber(v1, v2);
    if (expectedOutput != result) {
        cout << " Failed" << endl;
        cout << "expected: " << expectedOutput << ", fact: " << result << endl;
    }
    else
        cout << " Passed" << endl;
}


void tests() {
    executeTest({},              {1,2,3,4,5}, 0);
    executeTest({1,2,3,4,5},     {1,2,3,4,5}, 5);
    executeTest({1,2,2},         {1,2,3},     2);
    executeTest({1,2,3,2,3,2,3}, {3,3,3,0},   1);
    executeTest({1,2,3,2,3},     {2,3,3,3,2}, 2);
}

int main(){
    tests();
}