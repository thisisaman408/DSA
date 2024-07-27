#include <iostream>
#include <vector>
using namespace std;
void change(vector<int> &a) // pass by reference by using &
{

    a.at(0) = 100;
}
int main()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(2);
    v.push_back(3);
    v.push_back(12);
    v.push_back(12);
    v.push_back(11);
    v.push_back(34);
    v.push_back(56);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
    change(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl; // value has updated
}