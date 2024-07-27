#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr[] = {2, -3, 4, 4, -7, -1, 4, -2, 6};
    vector<int> v;
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int prevNeg = 0;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            v.push_back(arr[i]);
            prevNeg = i;
            break;
        }
    }
    int i = 1;
    int j = k;
    while (j < n)
    {
        if (prevNeg >= i)
            v.push_back(arr[prevNeg]);
        else
        {
            prevNeg = -1;
            for (int x = i; x <= j; x++)
            {
                if (arr[x] < 0)
                {
                    prevNeg = x;
                    break;
                }
            }
            
            if(prevNeg != -1)v.push_back(arr[prevNeg]);
        }

        i++;
        j++;
    }
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
/*
easy question
*/