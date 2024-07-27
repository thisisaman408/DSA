#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of string : " << endl;
    cin >> n;
    char s[n];
    cout << "Enter string" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
