#include <iostream>
using namespace std;
int main()
{
    char ch;
    cout << "Enter your character value : " << endl;
    cin >> ch;
    if ((int(ch) > 64 && int(ch) < 90))
    {
        cout << "This is a capital alphabet" << endl;
    }
    else if (int(ch) > 96 && int(ch) < 123)
    {
        cout << "This is a small alphabet" << endl;
    }
    else
    {
        cout << "This is not an alphabet" << endl;
    }
    return 0;
}