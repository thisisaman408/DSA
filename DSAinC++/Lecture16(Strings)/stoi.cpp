// stoi means string to integer converstion,
/*
as we use to_string(), function to convert integer to string, here we use stoi function to
convert string to integer and stoll to convert string to long long data type, so that we
can store the large numbers
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "123425326";
    int x = stoi(str);
    cout << x << endl;
    // or if number is large
    string str2 = "141251351535";
    long long u = stoll(str2);
    cout << u << endl;
}