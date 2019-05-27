//
// Created by Denis on 25.03.2019.
//

#ifndef CPPLABS_SPRING_ELLIPSE_H
#define CPPLABS_SPRING_ELLIPSE_H

#include "vector"

struct Point{
    double x;
    double y;

    Point(double x_, double y_)
    :x(x_),
    y(y_)
    {
    }
};

double getDistance(Point first, Point second);

class Ellipse {
public:

    Ellipse(double a, double b);

    bool contains(Point &point) const ;

    double getPer() const ;

    double getArea() const ;

    void rotateOn(double degrees);

    std::vector<Point> getBasicsPoints(int n) const;

    double getPar()const;

private:

    double a;
    double b;

    double rotation;
};


#endif //CPPLABS_SPRING_ELLIPSE_H
