#include <iostream>
using namespace std;
int main()
{
    char a;
    cout << "Enter your character " << endl;
    cin >> a;
    if (int(a) > 64 && int(a) < 91)
    {
        if (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
        {
            cout << a << " is a vowel in capital alphabet" << endl;
        }
        else
        {
            cout << a << " is a conconant" << endl;
        }
    }
    else if (int(a) > 96 && int(a) < 123)
    {
        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        {
            cout << a << " is a vowel in small alphabet" << endl;
        }
        else
        {
            cout << a << " is a consonant" << endl;
        }
    }
    else
    {
        cout << a << " is not an alphabet" << endl;
    }
    return 0;
}