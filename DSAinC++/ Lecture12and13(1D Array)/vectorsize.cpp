#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(9);
    cout << v.size() << endl; // v.size gives the size of the vector, in how many slots elements are stored
    v.push_back(8);
    cout << v.size() << endl;
    v.push_back(12);
    cout << v.size() << endl;
    v.push_back(45);
    cout << v.size() << endl;
}