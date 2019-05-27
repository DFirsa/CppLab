
#include "Circle.h"
#include <Math.h>
#include "iostream"

double getAlpha(Line line, double rad);

Circle::Circle(double a_) : Ellipse(a_,a_)
{
    hasSectionLine = false;
    sectionLine = Line(0,0);
}

double Circle::getSectorArea(double degrees) const{
    double area = getArea();
    double result = area * degrees/360;
    return result;
}

double Circle::getSectorPer(double degrees) const{
    double per = getPer();
    double result = per * degrees/360;
    return result;
}

void Circle::addSectionLine(Line line){
    hasSectionLine = true;
    sectionLine = line;
}

void Circle::deleteSectionLine(){
    hasSectionLine = false;
}

double Circle::getRad()const{
    return getPar();
}

double Circle::countPerBySection()const{
    double alpha = getAlpha(sectionLine,getRad());

    return (getPer()*(alpha/(2*M_PI)));
}

double Circle::countAreaBySection()const{
    double alpha = getAlpha(sectionLine,getRad());

    return (pow(getRad(),2) * (alpha - sin(alpha))/2);
}

Point getPoint(Line line, double x){
    double y = line.k * x + line.b;
    return Point(x,y);
}

double getDescr(Line line, double rad){
    double d = 4*(pow(line.k,2) * pow(line.b,2) - (pow(line.k,2) + 1) * (pow(line.b,2) - pow(rad,2)));
    return d;
}

bool Circle::hasSectionLine_() {
    return hasSectionLine;
}

double getAlpha(Line line, double rad){

    double descr = getDescr(line,rad);

    double x1 = ((-2*line.k * line.b) + (sqrt(descr)))/(2*(pow(line.k,2)+1));
    double x2 = ((-2*line.k * line.b) - (sqrt(descr)))/(2*(pow(line.k,2)+1));

    if (x1 == x2) return 0;

    Point a = getPoint(line,x1);
    Point b = getPoint(line,x2);

    double ab = getDistance(a,b);

    double alpha = 2*asin(ab/(2*rad));

    return alpha;
}