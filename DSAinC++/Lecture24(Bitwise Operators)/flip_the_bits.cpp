#include <iostream>
using namespace std;
string decimal_to_binary(unsigned int n)
{
    string result = "";
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            result = "0" + result;
        }
        else
        {
            result = "1" + result;
        }
        n = n >> 1;
    }
    return result;
}
string flip_the_bits(unsigned int n)
{
    n = ~n;
    string s = decimal_to_binary(n);
    return s;
}
int main()
{
    cout << flip_the_bits(16) << endl;
}
