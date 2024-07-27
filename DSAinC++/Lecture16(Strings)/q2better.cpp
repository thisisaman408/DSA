/*
given a strings, consisting of lowercase English Alphabets. Print the character that is occuring most of the times
here we will create an array, of 26 letters starting from 0-25, and we will update the index
each time we get the letter, as for "leetcode", l comes, then we will update the index of l from 0
to 1, then e, so the 4th index will become 1, then again e, so again 4th index will become 2, and so on
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> v(26, 0);
    string s;
    cout << "Enter the string : " << endl;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        int a = (int)s[i] - 97;
        v[a]++;
    }
    int max = 0;
    for (int i = 0; i < 26; i++)
    {
        if (max < v[i])
        {
            max = v[i];
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (v[i] == max)
        {
            cout << ((char)(i + 97)) << " : " << v[i] << endl;
        }
    }
    return 0;
}