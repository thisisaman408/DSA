#include <iostream>
using namespace std;
int n = 3;
void binaryString(string s)
{
    if (s.length() == n)
    {
        cout << s << endl;
        return;
    }
     binaryString(s + '0');
    if(s == "" || s[s.size() - 1] == '0'){
        binaryString(s + '1');
    }
}
int main()
{

    binaryString("");
}