#include <iostream>
using namespace std;
int binary_to_decimal(string &s)
{
    int n = s.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int num = s[i] - '0';
        sum += num * (1 << (n - i - 1));
    }
    return sum;
}
string decimal_to_binary(int num)
{
    string result = "";
    while (num > 0)
    {
        if (num % 2 == 0)
        {
            result = '0' + result;
        }
        else
        {
            result = '1' + result;
        }
        num = num >> 1; //(num /2, right shift)
    }
    return result;
}
int main()
{
    string s = "10110";
    cout << binary_to_decimal(s) << endl;
    cout << decimal_to_binary(10110) << endl;
}