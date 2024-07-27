/*
given a strings, consisting of lowercase English Alphabets. Print the character that is occuring most of the times
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cout << "Enter the string : " << endl;
    getline(cin, s);
    int l = s.size();
    int maxcount = 0;
    char a;
    for (int i = 0; i < l; i++)
    {
        int count = 1;
        for (int j = i + 1; j < l; j++)
        {
            if (s[i] == s[j])
            {
                count++;
            }
            else
            {
                continue;
            }
        }
        if (maxcount < count)
        {
            maxcount = count;
        }
    }
    for (int i = 0; i < l; i++)
    {
        char ch = s[i];
        int count = 1;
        for (int j = i + 1; j < l; j++)
        {
            if (s[i] == s[j])
            {
                count++;
            }
            else
            {
                continue;
            }
        }
        if (maxcount == count)
        {
            cout << ch << " : " << maxcount << endl;
        }
    }
}

//this is ofcourse one of the worst meythod to solve it, 