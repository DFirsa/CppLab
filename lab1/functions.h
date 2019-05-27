

#ifndef CPPLABS_SPRING_FUNCTIONS_H
#define CPPLABS_SPRING_FUNCTIONS_H

struct point{
    int x;
    int y;
};

struct circle{
    point o;
    double r;
};

void changeValue_pointer(int *first, int *second);

void round_pointer(double *number);

void decreaseRad_pointer(circle *circle, int delta);

void trans_pointer(int *matrix);

void changeValue_link(int &first, int &second);

void round_link(double &number);

void decreaseRad_link(circle &circle, int delta);

void trans_link(int &matrix);



#endif //CPPLABS_SPRING_FUNCTIONS_H
