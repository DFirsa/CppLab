#ifndef CPPLABS_SPRING_CONTAINER_H
#define CPPLABS_SPRING_CONTAINER_H

template <class T>
struct Container
{
    T value;
    Container<T> *left;
    Container<T> *right;

    int height;
};

#endif //CPPLABS_SPRING_CONTAINER_H
