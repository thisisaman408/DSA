// you are given n strings, and you have to find the largest strings, example, 341, 012,001, so here
// ofcourse 341 is the largest, so we convert string to integer for comparison
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string arr[] = {"0123", "0023", "456", "00182", "940", "002901"};
    int max = stoi(arr[0]);
    string maxS;
    // we'll store the numbers in long long, as in long long initial zeroes are not counted (MSB)

    for (int i = 1; i <= 5; i++)
    {
        int x = stoi(arr[i]);
        if (x > max)
        {
            max = x;
            maxS = arr[i];
        }
    }
    cout << maxS << endl;
}