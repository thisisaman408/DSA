/*
Given two strings s and t, return true if t is an anongram of s, and false otherwise
s = physicswallah, t = wallahphysics , output = true
anagrams are basically permutations of letters or anything
leetcode 242
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    string t;
    cout << "Enter first string " << endl;
    getline(cin, s);
    cout << "Enter second string " << endl;
    getline(cin, t);
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t)
    {
        cout << "true";
    }
    else
    {
        cout << "false" << endl;
    }
}