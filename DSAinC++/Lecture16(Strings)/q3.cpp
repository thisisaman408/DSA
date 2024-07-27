// return the most occuring word in a sentence
#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
#include <sstream>
using namespace std;
int main()
{

    string s;
    cout << "Enter your string : " << endl;
    getline(cin, s);
    stringstream str(s);
    string temp;
    vector <string> v;
    while (str >> temp)
    {
        v.push_back(temp);
    }
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << endl;
    // }
    sort(v.begin(), v.end());

    int maxcount = 1;
    int count = 1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        maxcount = max(maxcount, count);
    }

    count = 1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        if (count == maxcount)
        {
            cout << v[i] << " " << maxcount << endl;
        }
    }
    return 0;
}