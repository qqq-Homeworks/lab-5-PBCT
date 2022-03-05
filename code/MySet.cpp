// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#include "MySet.hpp"

void MySet::add_element(char *el) {
    MyVector::add_element(el);
    sort();
}

void MySet::delete_element(char *el) {
    int q = q_find(el);
    if (q != -1) {
        MyVector::delete_element(q);
        sort();
    }
}

int MySet::q_find(char *el) {
    int left = 0;
    int right = size - 1;
    int mid = 0;
    while (true) {
        mid = (left + right) / 2;
        if (strcmp(el, pdata[mid]) < 0)
            right = mid - 1;
        else if (strcmp(el, pdata[mid]) > 0)
            left = mid + 1;
        else
            return mid;
        if (left > right)
            return -1;
    }
}

bool MySet::is_element(char *el) {
    if (q_find(el) != -1) return true;
    return false;
}

ostream &operator<<(ostream &out, MySet &s) {
    for (size_t i = 0; i < s.size; ++i) {
        out << '[' << i << ']' << " : " << "{\"" << s.pdata[i] << "\"}" << '\n';
    }
    return out;
}

MySet operator+(MySet &s1, MySet &s2) {
    MySet newSet;
    for (size_t i = 0; i < s1.size; ++i) {
        if (!s2.q_find(s1[i])) {
            newSet.add_element(s1[i]);
        }
    }
    for (size_t i = 0; i < s2.size; ++i) {
        if (!newSet.q_find(s2[i])) {
            newSet.add_element(s2[i]);
        }
    }
    return newSet;
}

MySet operator-(MySet &s1, MySet &s2) {
    MySet newSet;
    for (size_t i = 0; i < s1.size; ++i) {
        if (!s2.q_find(s1[i])) {
            newSet.add_element(s1[i]);
        }
    }
    return newSet;
}

MySet operator*(MySet &s1, MySet &s2) {
    MySet newSet;
    for (size_t i = 0; i < s1.size; ++i) {
        if (s2.q_find(s1[i])) {
            newSet.add_element(s1[i]);
        }
    }
    return newSet;
}

bool MySet::operator==(MySet &s) {
    if (size == s.size) {
        for (size_t i = 0; i < size; ++i) {
            if (this->pdata[i] != s[i])
                return false;
        }
        return true;
    }
    return false;
}

MySet &MySet::operator+=(MySet &s) {
    //return <#initializer#>;
}

//{1, 4, 5, 6} * {1, 2, 3, 4} => {1, 4}
