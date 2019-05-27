#ifndef CPPLABS_SPRING_CIRCLE_H
#define CPPLABS_SPRING_CIRCLE_H

#include "Ellipse.h"

struct Line{

    double k;
    double b;

    Line(double k_, double b_)
    :k(k_),
    b(b_)
    {
    }

    Line() {}
};

class Circle: public Ellipse{
public:
   Circle(double halfShet);

    double getSectorArea(double degrees) const;

    double getSectorPer(double degrees) const;

    void addSectionLine(Line line);

    void deleteSectionLine();

    double countPerBySection()const ;

    double countAreaBySection()const ;

    double getRad()const;

    bool hasSectionLine_();

private:

    bool hasSectionLine;
    Line sectionLine;
};


#endif //CPPLABS_SPRING_CIRCLE_H
