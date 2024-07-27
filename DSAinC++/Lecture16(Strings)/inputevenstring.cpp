#include <iostream>
using namespace std;
int main()
{
    string s;
    cout << "Enter your string" << endl;
    getline(cin, s);
    int l = s.size();
    if (l % 2 == 0)// reverse first half of string
    {
        reverse(s.begin(), s.begin() + l / 2);
        cout << s << endl;
    }
    else
    {
        cout << "Enter the even lenght string " << endl;
    }
    return 0;
}