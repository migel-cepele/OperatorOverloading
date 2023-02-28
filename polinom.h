//ne nje array te deklaruar private do te ruajme polinomin, ku indekset paraqesin fuqite e termave te polinomit dhe vete array permban koeficientet
#include <iostream>
using namespace std;

#ifndef POLINOM_H
#define POLINOM_H

class Polinom{

    friend ostream& operator<<(ostream&, const Polinom&);
    friend Polinom& operator+=( Polinom&, Polinom);
    friend Polinom& operator*=( Polinom&, const Polinom);
    friend Polinom& operator-=( Polinom&, Polinom);

    public:
    explicit Polinom(int = 10); //default constructor
    ~Polinom();

    size_t getSize() const; // kthen nr e elementeve te array

    //operator overloading
    Polinom operator+(const Polinom&);
    Polinom operator-(const Polinom&);
    const Polinom& operator=(const Polinom&);
    Polinom operator*(const Polinom&);

    

    void setPol(int); //krijon polinomin
    

    private:
    size_t size;
    int* ptr; //pointeri per te identifikuar elementin e pare te array
}; 
#endif