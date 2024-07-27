#include <iostream>
using namespace std;
int main()
{
    string s;
    cout << "Enter your string" << endl;
    getline(cin, s);
    int l = s.length();
    if (l > 5)
    {
        reverse(s.begin() + 2, s.begin() + 6);
        cout << s << endl;
    }
    else
    {
        cout << "please enter a string greater than the lenght 5" << endl;
    }
    return 0;
}
