#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    sort(s.begin(), s.end());
    cout << s;
    // here the sorting takes place as per, ASCII values, so if there are spaces, so
    // spaces will be get written first,
}
