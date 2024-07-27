#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v(5, 7); // this means a vector of initial size 5 with all the values as 7
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";//all values are 7
    }
}