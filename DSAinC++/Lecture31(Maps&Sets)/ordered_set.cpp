#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(2);
    s.insert(7);
    s.insert(10);
    s.insert(-1);
    for (auto ch : s)
    {
        cout << ch << " ";
    }
}