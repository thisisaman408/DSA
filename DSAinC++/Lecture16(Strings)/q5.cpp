/*
we are given n strings, and now we have to find the longest common prefix, which is as
we have "racer", 'racing, "racer", so here rac is the longest common prefix among this string
leetcode 14
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string s;
    int x;
    vector<string> v;
    cout << "Enter no of strings : " << endl;
    cin >> x;
    cout << "Enter your strings" << endl;
    for (int i = 0; i < x; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    int n = v.size();
    sort(v.begin(), v.end());
    string first = v[0];
    string last = v[n - 1];
    string temp = "";
    for (int i = 0; i < (min(first.size(), last.size())); i++)
    {
        if (first[i] == last[i])
        {
            temp += first[i];
        }
        else
        {
            break;
        }
    }
    cout << temp;
}

/*
here, we sort the vector, as we know that when we sort the vector, we get order lexographically,
which means, each letter is sorted as per their ASCII value, and if two words are same, and another is
larger than the one, then the smaller one is placed before than the larger one, example
flow flower, here till flow , word is same, so order will be flow > flower
*/