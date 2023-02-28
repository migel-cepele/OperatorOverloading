#include <iostream>
#include <array>
#include <string>
#include "unaryOperator.h"
using namespace std;

const array<unsigned int,13> Date::days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(int month, int day, int year) {
    setDate(month, day, year);
}

void Date::setDate(int mm, int dd, int yy) {
    if (mm>= 1 && mm <= 12) {
        month = mm;
    } else {
        throw invalid_argument{"Month must be 1-12"};
    }

    if(yy >= 1900 && yy <= 2100) {
        year = yy;
    } else {
        throw invalid_argument{"Year must be 1900-2100"};
    }

    if((mm == 2 && leapYear(year) && dd>=1 && dd <= 29) || (dd >= 1 && dd <= days[mm])) {
        day = dd;
    } else {
        throw invalid_argument{"Day is out of range for the current month or year"};

    }
}

//overloaded prefix increment operator

Date& Date::operator++() {
    helpIncrement();
    return *this; //reference return to create an lvalue
}

//overloaded postfix increment operator, parametri nuk ka nje emer
Date Date::operator++(int) {
    Date temp{*this}; //ruan gjendje aktuale te objektit
    helpIncrement();
    return temp; //value return, not a reference return

}

Date& Date::operator+=(unsigned int additionalDays) {
    for(unsigned int i = 0; i< additionalDays; ++i) {
        helpIncrement();
    }
    return *this; //enables cascading
}

bool Date::leapYear(int testYear) {
    return ((testYear % 400 == 0) || (testYear % 100 != 0 && testYear % 4 == 0));
}

bool Date::endMonth(int testDay) const {
    if (month == 2 && leapYear(year)) {
        return testDay == 29;
    } else {
        return testDay == days[month];
    }
}

void Date::helpIncrement() {
    if(!endMonth(day)) {
        ++day;
    } else {
        if(month < 12) {
            ++month;
            day = 1;
        } else {
            ++year;
            month = 1;
            day = 1;
        }
    }
}


//overloaded output operator
ostream& operator<<(ostream& output, const Date& d) {
   static string monthName[13]{"", "January", "February",
   "March", "April", "May", "June", "July", "August",
   "September", "October", "November", "December"};
   output << monthName[d.month] << ' ' << d.day << ", " << d.year;
   return output; // enables cascading
}


int main() {
    Date d1{12, 27, 2010};
    Date d2;

    cout << "d1 is: " << d1 << "\n d2 is: " << d2;
    cout << "\n\n d1+=7 is " << (d1+=7);


    d2.setDate(2,28,2008);
    cout << "\n\n d2 is: " << d2;
    cout << "\n ++d2 is " << ++d2;

    Date d3{7, 13, 2010};
    cout << "\n\n Testing postfix increment operator: ";
    cout << "\nd3++ is " << d3++;
    cout << "\nd3 is " << d3;
}
