#ifndef CPPLABS_SPRING_MYITERATOR_H
#define CPPLABS_SPRING_MYITERATOR_H

#include "Container.h"
#include "stack"


template <class T>
class MyIterator {
private:
    Container<T> *containerPtr;

public:
    MyIterator(Container<T> *p)
    :containerPtr(p){};

    bool operator == (const MyIterator& other) const{
        return other.containerPtr == this->containerPtr;
    };
    bool operator != (const MyIterator& other) const{
        return other.containerPtr != this->containerPtr;
    };
    T& operator* () const{
        return this->containerPtr->value;
    };
    std::stack< Container<T> > containerStack;
    MyIterator& operator++ (){
        if (containerPtr != nullptr){
            if (containerPtr->right != nullptr) containerStack.push(*containerPtr->right);
            if (containerPtr->left != nullptr) containerPtr = containerPtr->left;
            else{
                containerPtr = containerStack.top();
                containerStack.pop();
            }
        }

        return *this;
    };
    MyIterator operator++(int){
        if (containerPtr != nullptr){
            if (containerPtr->right != nullptr) containerStack.push(*containerPtr->right);
            if (containerPtr->left != nullptr) containerPtr = containerPtr->left;
            else{
                containerPtr = &containerStack.top();
                containerStack.pop();
            }
        }

        return *this;
    };
};


#endif //CPPLABS_SPRING_MYITERATOR_H
