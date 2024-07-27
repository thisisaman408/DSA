/*
anangram is basically permutation, like cat has anangram as tac, atc etc,
listen has silent, in coding if the word make sense or not, it doesn;t matter, so here just
;input two strings, and output whether those two strings are anangram of each other or not
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    string t;
    cout << "Enter first string : " << endl;
    getline(cin, s);
    cout << "Enter second string : " << endl;
    getline(cin, t);
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t)
    {
        cout << "Both strings are anangram" << endl;
    }
    else
        cout << "These are not anangrams" << endl;
}
// a simple code, i don't think there is a need to explain this