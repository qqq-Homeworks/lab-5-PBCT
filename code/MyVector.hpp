// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#ifndef CODE_MYVECTOR_HPP
#define CODE_MYVECTOR_HPP
//файл MyVector.h - описание класса MyVector

#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

template<typename T>
class MyVector {
public:
    MyVector(); // Done
    MyVector(T, int = MAX_SIZE); // Done

    MyVector(const MyVector &v); // Done

    ~MyVector(); // Done

    void add_element(T); // done

    bool delete_element(int i); // done

    T operator[](int i); // done

    void sort(); //done

    int Size() { return size; } //Done

    int Maxsize() { return maxsize; } // Done

    int find(T); // Done

    MyVector<T>& operator=(const MyVector<T> &v); // Done

    template<typename T1>
    friend ostream &operator<<(ostream &out, MyVector<T1> &v);// Done

protected:
    int maxsize;
    int size;
    T *pdata;
private:
    void resize(); // done
};

#endif

