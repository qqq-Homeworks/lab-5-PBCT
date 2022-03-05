// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#ifndef CODE_MYSET_HPP
#define CODE_MYSET_HPP

#include <iostream>
#include "MyVector.hpp"

using namespace std;

class MySet : public MyVector {
public:
    MySet(char *el = nullptr) : MyVector(el) {};

    friend ostream &operator<<(ostream &out, MySet &s); //DONE

    friend MySet operator+(MySet &s1, MySet &s2); // DONE

    friend MySet operator-(MySet &s1, MySet &s2);

    friend MySet operator*(MySet &s1, MySet &s2);

    bool operator==(MySet &s);

    MySet &operator+=(MySet &s);

    MySet &operator-=(MySet &s);

    MySet &operator*=(MySet &s);

    void add_element(char *el); //DONE

    void delete_element(char *el); // DONE

    bool is_element(char *el); //DONE

private:
    int q_find(char* el);
};


#endif //CODE_MYVECTOR_HPP
