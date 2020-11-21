#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std ;
#define MAX 100

template<typename T>
class STACK{
    public:
    STACK()
    {
        this->index = 0;
        this->size = MAX;
        this->array = new T[size];
    }
    void push(T s){
        if(index < size)
            array[index++] = s;
        else
            cout << "STACK IS FULL" << endl ;
    }

    void pop (){
        if(index == 0)
            cout << "STACK IS EMPTY" << endl ;
        else
            index--;

    }

    T top (){
        if(index == 0)
        {
            cout << "STACK IS EMPTY" << endl;
            return -1;
        }
        return this->array[index-1];
    }
    bool empty()
    {
        return (index == 0);
    }
    private:
        int size ;
        int index ;
        T *array;

};