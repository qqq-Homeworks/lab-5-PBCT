// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#ifndef CODE_MYVECTOR_HPP
#define CODE_MYVECTOR_HPP
//файл MyVector.h - описание класса MyVector

#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

class MyVector {
public:
    MyVector(char * = nullptr, int = MAX_SIZE); // Done

    MyVector(const MyVector &v); // Done

    ~MyVector(); // Done

    void add_element(char *el); // done

    bool delete_element(int i); // done

    char *operator[](int i); // done

    void sort(); //done

    int Size() { return size; } //Done

    int Maxsize() { return maxsize; } // Done

    int find(char *el); // Done

    MyVector &operator=(const MyVector &v); // Done

    friend ostream &operator<<(ostream &out, MyVector &v);// Done

protected:
    int maxsize;
    int size;
    char **pdata;
private:
    void resize(); // done
};

#endif

