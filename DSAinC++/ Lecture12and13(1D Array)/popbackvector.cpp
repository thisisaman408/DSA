#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(8);
    v.push_back(2);
    v.push_back(81);
    v.push_back(21);
    v.push_back(12);
    v.push_back(34);
    v.push_back(91);
    cout << "Capacaity is : " << v.capacity() << endl; // compare it with the final capacity after pop_back
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    v.pop_back();
    v.pop_back();
    v.pop_back();                      // it will delete last two added elements
    for (int i = 0; i < v.size(); i++) // size automatically gets updated but not capacity
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "Capacaity is : " << v.capacity() << endl; // still it's same as before
}
//vector<int> (5), this is an array of size 5