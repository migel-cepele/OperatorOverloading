#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <array>
using namespace std;

class Date{
    friend std::ostream& operator<<(std::ostream&, const Date&);
    public:
    Date(int m = 1, int d = 1, int y = 1900);
    void setDate(int, int, int);
    Date& operator++(); //prefix increment operator
    Date operator++(int); //postfix increment operator. Argumenti i perdorur eshte dummy per te ndihmuar compilerin te dalloj kete operator nga ai me lart
    Date& operator+=(unsigned int); //mbledh ditet
    static bool leapYear(int);
    bool endMonth(int) const;

    private:
    int year;
    int month;
    int day;

    void helpIncrement();
    static const std::array<unsigned int, 13> days; // days per month
}; 


#endif
