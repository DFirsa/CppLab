#include "Ellipse.h"
#include <Math.h>
#include "iostream"
#include "vector"

double getDistance(Point first, Point second){
    double distance = sqrt(pow(first.x - second.x,2) + pow(first.y - second.y,2));
    return distance;
}

Ellipse::Ellipse(double a_, double b_)
    :a(a_),
    b(b_)
{
    rotation = 0;
}

bool Ellipse::contains(Point &point) const{
     double toCheck = pow(point.x,2)/pow(a,2) + pow(point.y,2)/pow(b,2);
     if (toCheck == 1)return true;
     else return false;
}

double Ellipse::getPer() const{
    double result = M_PI*(3*(a+b) - sqrt((3*a + b)*(a + 3*b)));
    return result;
}

double Ellipse::getArea() const{
    double result = M_PI * a * b;
    return result;
}

void Ellipse::rotateOn(double degrees){
    rotation += degrees;

    while (rotation >= 360) rotation-= 360;
}

double Ellipse::getPar()const{
    double rad;
    rad = a;
    return rad;
}

std::vector<Point> Ellipse::getBasicsPoints(int n) const{
    std::vector<Point> points;

    double x = a;
    double step = 2*a/n;
    double y;

    for (int i = 0; i < n; i++){
        y = sqrt((pow(b,2)*pow(x,2))/pow(a,2) +  pow(b,2));
        if (i >= n/2) y = -y;

        double x_ = x * cos(rotation * (M_PI/180)) - y * sin(rotation * (M_PI/180));
        double y_ = x * sin(rotation * (M_PI/180)) + y * cos(rotation * (M_PI/180));

        Point point(x_,y_);

        points.push_back(point);

        x -= step;
        if (x < -a){
            x = -a + abs(x + a);
            step = -step;
        }
    }

    return points;
}
