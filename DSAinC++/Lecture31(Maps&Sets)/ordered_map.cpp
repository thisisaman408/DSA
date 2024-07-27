#include <iostream>
#include <map>

using namespace std;
int main()
{
    map<int, int> m;
    m[20] = 20;
    m[2] = 30;
    m[3] = 40;
    m[10] = 1;
    m[30] = 2;
    for (auto ch : m)
    {
        cout << ch.first << " ";
    }
}