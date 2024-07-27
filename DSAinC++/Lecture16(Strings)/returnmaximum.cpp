/*
Given a sentence ‘str’, return the word that is lexicographically maximum.
Input : str = "proud to be pwians"
Output : pwians
Input : str = "decode dsa with pw"
Output : with
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    string s;
    cout << "Enter string : " << endl;
    getline(cin, s);
    stringstream aman(s);
    string temp;
    vector<string> v;
    while (aman >> temp)
    {
        v.push_back(temp);
    }
    sort(v.begin(), v.end()); // vector sort lexographically
    cout << v[(v.size() - 1)];
}