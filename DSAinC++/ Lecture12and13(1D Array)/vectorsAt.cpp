#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(2);
    v.push_back(12);
    v.push_back(942);
    v.push_back(956);
    v.push_back(21);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
    // v.at(i) is same as v[i]
    // to update
    cout << "Updated Array is as follows" << endl;
    v.at(3) = 100;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;

    // to sort your dynamic array
    sort(v.begin(), v.end()); // this has sorted your dynamic array
    cout << "Sorted Array is as follows" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
}