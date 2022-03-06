// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#ifndef CODE_MYSET_HPP
#define CODE_MYSET_HPP

#include <iostream>
#include "MyVector.hpp"

using namespace std;

template <typename T>
class MySet : public MyVector<T> {
public:
    MySet() : MyVector<T>() {};

    MySet(T el) : MyVector<T>(el, MAX_SIZE) {};

    template <typename T1>
    friend ostream &operator<<(ostream &out, MySet<T1> &s); //DONE

    template <typename T1>
    friend MySet<T1> operator+(MySet<T1> &s1, MySet<T1> &s2); // DONE

    template <typename T1>
    friend MySet<T1> operator-(MySet<T1> &s1, MySet<T1> &s2);

    template <typename T1>
    friend MySet<T1> operator*(MySet<T1> &s1, MySet<T1> &s2);

    bool operator==(MySet &s);

    MySet &operator+=(MySet &s);

    MySet &operator-=(MySet &s);

    MySet &operator*=(MySet &s);

    void add_element(T el); //DONE

    void delete_element(T el); // DONE

    bool is_element(T el); //DONE

private:
    int q_find(T el);
};


#endif //CODE_MYVECTOR_HPP
