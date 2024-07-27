#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int prod = 1;
    for (int i = 0; i <= 4; i++)
    {
        prod *= arr[i];
    }
    cout << prod << endl;
}