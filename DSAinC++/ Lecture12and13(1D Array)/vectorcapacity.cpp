#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;

    v.push_back(9);
    cout << v.capacity() << endl; // v.capacity gives the.capacity of the vector, in how many slots elements can be stored
    v.push_back(8);
    cout << v.capacity() << endl;
    v.push_back(12);
    cout << v.capacity() << endl;
    v.push_back(45);
    cout << v.capacity() << endl;
    //as we know that the capacity of vector gets doubled if it is full
}
