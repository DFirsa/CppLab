#include <vector>
#include <iostream>
#include <cmath>
#include <sstream>
#include <forward_list>

using namespace std;

class Vector{

private:
    double x,y;

public:
    Vector(double _x, double _y): x(_x), y(_y){}

    double len(){
        return sqrt(x * x + y * y);
    }

    bool operator==(const Vector& b){
        return x == b.x && y == b.y;
    }

    string to_string(){
        ostringstream ss;
        ss << "Vector[" << x << ", " << y << "]";
        return ss.str();
    }

};

template <class T, class Condition>
bool all_of(T &collection, Condition test){
    for(typename T::iterator it = collection.begin(); it != collection.end(); it++){
        if(!test(*it))
            return false;
    }

    return true;
}

template <class T, class Comparator>
bool is_sorted(T &collection, Comparator comparator){
    for(typename T::iterator it = collection.begin(); it + 1 != collection.end(); it++){
        if(comparator(*it, *(it + 1)) > 0)
            return false;
    }

    return true;
}


template <class T>
typename T::iterator find_backward(T &collection, typename T::value_type val){
    for(typename T::iterator it = collection.end() - 1; it+1 != collection.begin(); it--){
        if(*it == val)
            return it;
    }

    return collection.end();
}

int main(){
    vector<int> v;

    v.push_back(3);
    v.push_back(6);
    v.push_back(12);
    v.push_back(9);

    cout << " == STANDART TYPES ===" << endl;
    cout << all_of(v, [](int i){ return i % 3 == 0; }) << endl;
    cout << is_sorted(v, [](int a, int b){ return a - b; }) << endl;
    cout << *find_backward(v, 12) << endl;

    vector<Vector> p;

    p.push_back(Vector(1, 3));
    p.push_back(Vector(3, 1));
    p.push_back(Vector(sqrt(10), 1));

    cout << "=== CUSTOM TYPES ===" << endl;
    cout << all_of(p, [](Vector vec){ return vec.len() == sqrt(10); }) << endl;
    cout << is_sorted(p, [](Vector a, Vector b){ return a.len() - b.len(); }) << endl;
    cout << find_backward(p, Vector(3, 1))->to_string() << endl;

    return 0;
}
