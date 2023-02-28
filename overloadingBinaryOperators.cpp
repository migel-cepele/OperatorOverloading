//overloading binary operators
//ne mund te perdorim non static class define functions to overload operators with one parameter or non class functions with two parameters, where one of them is an object
//of the class where the operator will be used
//overloaded functions mund te jene class members vetem atehere kur operandi i majte eshte nje objekt i klases ku ben pjese funksioni

//ne shembullin me poshte do te shikojme overloading e Binary stream insertion and extraction operators
#include <iostream>
#include <string>
#include <iomanip>
#include "BinaryOverloading.h"
using namespace std;

ostream& operator<<(ostream& output, const PhoneNumber& number ) {
    output << "Area code: " <<number.areacode << "\n Exchange: " << number.exchange << "\n Line: " << number.line<<endl
    <<"(" << number.areacode << ")" << number.exchange << "-" << number.line <<"\n";
    return output;
}

istream& operator>>(istream& input, PhoneNumber& number) {
    //input.ignore(); //skip (
    input >> setw(3) >> number.areacode;
    input.ignore(); //skip ) dhe space
    input >> setw(3) >> number.exchange;
    input.ignore(); //skip -
    input >> setw(4) >> number.line;
    return input;

}

int main() {

    PhoneNumber number;

    cout << "Vendosni numrin ne formatin (555) 555-5555: " << endl;

    cin >> number; //kur compileri shikon kete shprehje, ne menyre implicite e interpreton si "overload>>(cin, number)"
    cout << "Nr i futur eshte: \n\n";
    cout << number;//ne menyre te ngjashme funksionon dhe keshtu

}

