#include <iostream>
using namespace std;

#ifndef ARRAY_H
#define ARRAY_H

class Array{
    friend ostream& operator<<(ostream&, const Array&);
    friend istream& operator>>(istream&, Array&);

    public:
    explicit Array(int = 10); //default constructor. Konstruktoret qe marrin nje argument dhe nuk deklarohen explicit(jo ne rastin e copy constructor), trajtohen nga
    //kompilatori ne menyre implicite si conversion constructors(konvertojne nje tip te dhene cfaredo te dhene si argument ne nje objekt te klases ku eshte deklaruar konstruktori).
    Array(const Array&); //copy constructor
    ~Array();
    size_t getSize() const;

//overloading operators
    const Array& operator=(const Array&);
    bool operator==(const Array&) const;

    bool operator!=(const Array& right) const{
        return !(*this == right); //return the opposite of ==
    }

    int& operator[](int); //subscript operator for non-const objects return modifiable lvalue
    int operator[](int) const; //subscript operator for const objects returns rvalue
    
    private:
    size_t size;
    int* ptr; //pointer per array

};
#endif