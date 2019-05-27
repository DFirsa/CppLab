#pragma once
#ifndef CPPLABS_SPRING_CQUEUE_H
#define CPPLABS_SPRING_CQUEUE_H

#include "vector"
#include "iostream"
#include "string"

class outOfRange: std::exception{
public:

    outOfRange(char* exception)
            :error(exception)
    {}

    virtual const char *what() const throw(){
        return error;
    }

private:
    char* error;
};

template <class T, int max>
class CQueue{
public:

    CQueue()
    :maxSize(max),
    size(0)
    {
    }

    void push(T& val){
        if (size == maxSize){
            throw outOfRange("QUEUE IS FULL");
        }

        queue.push_back(val);
        size++;
    }

    T pop(){
        if (size == 0){
            throw outOfRange("QUEUE IS EMPTY");
        }

        return queue.front();
    }

    T poll(){
        if (size == 0){
            throw outOfRange("QUEUE IS EMPTY");
        }

        size--;
        T res = queue.front();
        queue.erase(queue.begin());
        return res;
    }

private:
    std::vector<T> queue;
    const int maxSize;
    int size;
};

#endif //CPPLABS_SPRING_CQUEUE_H
