#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "array.h"
using namespace std;


Array::Array(int arraySize) //default constructor
: size{(arraySize > 0 ? static_cast<size_t>(arraySize):
throw invalid_argument{"Madhesia e array duhet te jete me e madhe se 0"})},
 ptr{new int[size]{}} {
}

Array::Array(const Array& arraytoCopy)
: size{arraytoCopy.size}, ptr{new int[size]} {
    for(size_t i{0}; i<size; ++i) {
        ptr[i] = arraytoCopy.ptr[i];
    }

}

Array::~Array(){
    delete[] ptr; //release pointer-based array space

}

size_t Array::getSize() const{
    return size;
}

//const return avoids: (a1=a2)=a3
const Array& Array::operator=(const Array& right) {
    if(&right != this) {//avoid self assignment
       if(size != right.size) {
        delete[] ptr; //release space
        size = right.size; //resize this object
        ptr = new int[size]; //create space for array copy
       }

       for(size_t i{0}; i < size; ++i) {
        ptr[i] = right.ptr[i]; //copy array into object
       }

    }

    return *this; //enables x = y = z for example
}

bool Array::operator==(const Array& right) const {
    if(size != right.size) {
        return false;
    }
    for(size_t i{0}; i < size; ++i) {
        if(ptr[i] != right.ptr[i]) {
            return false;
        }
    }
    return true;
}
//reference return creates a modifiable lvalue
int& Array::operator[] (int subscript) {
    if(subscript < 0 || subscript >= size) {
        throw out_of_range{"Indeksi jashte range"};
    }

    return ptr[subscript]; //reference return
}

//const reference return creates an rvalue
int Array::operator[](int subscript) const{
    if(subscript < 0 || subscript >= size) {
        throw out_of_range{"Indeksi jashte range"};
    }
    return ptr[subscript]; //return copy of this element
}

istream& operator>>(istream& input, Array& a) {
    for (size_t i{0}; i < a.size; ++i) {
        input >> a.ptr[i];
    }
  
    return input; // enables cin >> x >> y;
}

ostream& operator<<(ostream& output, const Array& a) {
// output private ptr-based array
    for (size_t i{0}; i < a.size; ++i) {
        output << a.ptr[i] << " ";
    }

    output << endl;
    return output; // enables cout << x << y;
}

int main() {
    Array integers1{7};
    Array integers2{};

    cout << "Size of Array integers1 is: " << integers1.getSize()
    << "\nArray after initialization: " << integers1;

    cout << "\nSize of array integeres2 is: " << integers2.getSize()
    <<"\narray after initialization: " << integers2;

    cout << "\nEnter 17 integers:" <<endl;
    cin >> integers1 >> integers2;

    cout <<"\nAfter input, the arrays contain: " 
    <<"\n integers1:" << integers1
    <<"\n integers2:" << integers2;

    cout <<"\nEvaluating: integers1 != integers2: " << endl;
    if (integers1 != integers2) {
        cout << "Integers1 and integers2 are not equal" << endl;

    }

    Array integers3{integers1};

    cout << "\n integers 3 size is: " << integers3.getSize();

    cout << "\nAssigning integers2 to integers1: " <<endl;
    integers1 = integers2;

    cout << "integers 1: " <<integers1 << "\n integers2: " <<integers2;

    cout <<"\n evaluating integers1 == integers2";
    if(integers1==integers2) {
        cout << "integers1 and integers2 are equal: " << endl;
    }

    cout << "\nAssigning 1255 to integers1[5]" <<endl;
    integers1[5] = 1255;
    cout << "integers1: " << integers1;

    try{
        cout << "\nAttempt to assign 12 to integers[17]" <<endl;
        integers1[15] = 5235;
    } catch(out_of_range& ex) {
        cout << "An exeption occurred: " <<ex.what() << endl;

    }
}