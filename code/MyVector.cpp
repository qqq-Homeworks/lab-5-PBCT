// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#include "MyVector.hpp"

MyVector::MyVector(char *el, int maxsz) : maxsize(maxsz) {
    *pdata = el;
}

void MyVector::sort() {
    std::sort(this->pdata, this->pdata + size, [](const char *first, const char *second) {
        return strcmp(first, second);
    });
}

void MyVector::resize() {
    if (size >= maxsize)
        maxsize = (maxsize / 2) * 3;
    else if (size <= size / 2)
        maxsize = (maxsize / 3) * 2;
    else return;
    char **newMemory = new char *[maxsize];
    for (size_t i = 0; i < size; ++i) {
        newMemory[i] = pdata[i];
    }
    for (size_t i = 0; i < size; ++i) {
        delete[] pdata[i];
    }
    delete[] pdata;
    pdata = newMemory;
}

MyVector::MyVector(const MyVector &v) : maxsize(v.maxsize), size(v.size) {
    pdata = new char *[v.maxsize];
    for (size_t i = 0; i < size; ++i) {
        strcpy(pdata[i], v.pdata[i]);
    }
}

void MyVector::add_element(char *el) {
    size++;
    resize();
    strcpy(pdata[size], el);
    sort();
}

MyVector::~MyVector() {
    for (size_t i = 0; i < size; ++i) {
        delete[] pdata[i];
    }
    delete[] pdata;
}

bool MyVector::delete_element(int i) {
    if (i > -1 && i < size) {
        delete[] pdata[i];
        for (size_t j = i; j < size - 1; ++j) {
            pdata[j] = pdata[j + 1];
        }
        size--;
        resize();
        sort();
        return true;
    } else
        return false;
}

char *MyVector::operator[](int i) {
    return pdata[i];
}

int MyVector::find(char *el) {
    int q = std::find_if(pdata, pdata + size, [el](char *q) { return strcmp(q, el); }) - pdata;
    if (q == size) q = -1;
    return q;
}

MyVector &MyVector::operator=(const MyVector &v) {
    if (this != &v) {
        maxsize = v.maxsize;
        size = v.size;
        pdata = new char *[v.maxsize];
        for (size_t i = 0; i < size; ++i) {
            strcpy(pdata[i], v.pdata[i]);
        }
    }
    return *this;
}

ostream &operator<<(ostream &out, MyVector &v) {
    for (size_t i = 0; i < v.size; ++i) {
        out << '[' << i << ']' << " : " << v.pdata[i] << '\n';
    }
    return out;
}


