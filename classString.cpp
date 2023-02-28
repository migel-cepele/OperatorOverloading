#include <iostream>
#include <string>
using namespace std;

int main() {

    string s1{"happy"};
    string s2{"birthday"};
    string s3; //empty

    /*cout << "s1 is \"" <<s1 << "\"; s2 is \"" << s2 << "\"; s3 is \"" << s3 <<"\" ";

    cout <<"\n\n The result of comparing s1 and s2 is: " << boolalpha//formaton outputin 0 ne "false" dhe 1 ne "true" << "\n s1 == s2 yeilds: " << (s1==s2)
    << "\n s1 != s2 yeilds: " << (s1!= s2)
    << "\n s1 > s2 yeilds: " << (s1 > s2); // dhe krahasime te tjera si keto...

    //testimi i funksionit empty:

    if(s3.empty()) {
        cout << "\n s3 is empty!";
        s3 = s1;
        cout<< "\n s3 now is: " << s3;
    }*/

    cout << "\n\n s1 += s2 yeilds: " << (s1+=s2);

    //testin substring function:

    cout << "\n\n substring from index 0 to 5 is: " << (s1.substr(0,5));

    cout <<"\n\n substring starting at index 13 is: " <<(s1.substr(13));

    //test of copy constructor:

    string s4{s1};

    cout <<"\n\n s4 is: " << s4;
    cout <<"\n\n testin s4 = s4 operator: " << (s4=s4) <<s4;

    s1[0] = 'H';
    s1[5] = 'B';
    cout << "\n\n s1 pas ndryshimeve: s1[0] = 'H' s1[6] = 'B' eshte :  " << s1;

    //test substring out of range with function "at":

    try
    {
        cout << "\n Atempting to assign s1.at(100) = 'd': ";
        s1.at(100) = 'd';


    }
    catch(out_of_range& ex)
    {
        cout <<"\nAn exeption ocurred: " <<ex.what() << '\n';
    }
    




}