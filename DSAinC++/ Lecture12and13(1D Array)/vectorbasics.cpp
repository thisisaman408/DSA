#include <iostream>
#include <vector> //header file for vector
using namespace std;
int main()
{
    vector<int> v; // initialisation of vector of size 0
    // do not use [] for insertion of elements it will give segmentation fault
    v.push_back(9); // pushback first check the capactity of vector, if it is full
    // then it makes the vector of double size and start inserting elements
    v.push_back(8);
    v.push_back(7);
    v.push_back(34);
    // now for printing or updating the vector we can use [] with i, as now there is no need of allocating new memory
    for (int i = 0; i <= 3; i++)
    {
        cout << v[i] << " ";
    }
}