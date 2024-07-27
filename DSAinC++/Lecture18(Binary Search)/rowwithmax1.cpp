#include <iostream>
#include <vector>
using namespace std;
int maximum1(vector<vector<int>> &v)
{
    int rows = v.size();
    int cols = v[0].size();
    int maxrow = -1;
    int maxcount = 0;
    for (int i = 0; i < rows; ++i)
    {
        int left = 0;
        int right = cols - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (v[i][mid] == 1)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        int count = left;
        if (cols - count > maxcount)
        {
            maxcount = cols - count;
            maxrow = i;
        }
    }
    return (maxrow + 1);
}
int main()
{
    int rows, columns;
    cout << "Enter no of rows : ";
    cin >> rows;
    cout << "Enter no of columns : ";
    cin >> columns;
    vector<vector<int>> v(rows, vector<int>(columns, 0));
    cout << "Enter the elements : ";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> v[i][j];
        }
    }
    int x = maximum1(v);
    cout << x;
}
