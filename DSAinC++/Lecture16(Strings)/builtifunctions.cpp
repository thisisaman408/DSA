#include <iostream>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    int u = 0;
    u = s.size();      // string_name.size() - to calculate the size of the string it do not count null character
    cout << u << endl; // string from - to string.length () - 1
    s.push_back('e');  // to push_back one single character element, cannot insert a string like this here
    cout << s << endl;
    s.pop_back(); // to remove the s.length () - 1, indexed element from the string
    cout << s << endl;
    string p;
    getline(cin, p);
    string t = s + p;
    cout << s << " " << p << " " << t << endl; // this "+" operator is used to add any two strings , even s + "abc", will work
    cout << s + "abc" << endl;
    // so basically + operator is used to append the string, we CANNOT append any number to the string, but we can append the numbers in ""
    // example
    cout << s + "123" << endl; // "123" is now a string, we cannot do  cout << s + 123, this is prohibited
    reverse(s.begin(), s.end());//to reverse the string
    cout << s << endl;
    reverse(s.begin() + 2, s.begin() + 4);// consider s.begin() as 0 index, we can even reverse a certain part of the string,
    //as here, only 2 to 4th indexes has been reversed, we can also write it as, s.begin() + 2, s.end() -1, if there are 5 indexes
    cout << s << endl;// if we want to reverse only 2 to 4 index, then I will write, s.begin () + 2, s.begin() + 5, one index is 
    //more has to be written in after one
    
}