/*
in this question here, we have given an array say, 19 18 23 12, having n elements
now we have to create another array with 0 to n - 1 elements, thus here 0 1 2 3 ( n -1 = 4 - 1 = 3)
and the smallest element should be zero, thus the final array should give,
2 1 3 0, 12 is smallest

here, our algo will be, we will make a copy of this array, and will sort that array, from there we
will get the mapping, and then we will use index of that new array to insert in our first array
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of vector : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> r = v;
    sort(r.begin(), r.end());
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i] == r[j])
            {
                v[i] = j;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}