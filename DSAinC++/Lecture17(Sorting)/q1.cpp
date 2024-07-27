/*
sort a string in decreasing order, of values associated after removal of values smaller than x
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;
void swap(char *m, char *n)
{
    char temp;
    temp = *m;
    *m = *n;
    *n = temp;
}

void bubblesort(int n, vector<char> &arr)//array passes by reference not vector, so in vector, if  you want to work on the same vector, then use & to pass it by reference
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = false;
            }
        }
        if (flag == true)
        {
            break;
        }
    }
}
void printarray(int n, vector<char> arr)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    string s;
    cout << "Enter your string (without spaces and in small letters): ";
    cin >> s;
    vector<char> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'x' || s[i] == 'y' || s[i] == 'z')
        {
            v.push_back(s[i]);
        }
    }
    bubblesort(v.size(), v);
    printarray(v.size(), v);
}