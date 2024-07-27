#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s = "abcdef";
    cout << s.substr(2) << endl;
    cout << s.substr(2, 3);
    // this will give the substring which is at and after the index 2
    //s.substr(idx, len) this means the lenght of string after the index idx, thus if 
    //I say, s.substr(2,3), so here at index 2 there is c, and including c the next 3 lenght is cde, so cde
    //shall be get printed
}