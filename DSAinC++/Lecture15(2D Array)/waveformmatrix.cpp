#include <iostream>
#include <vector>
using namespace std;
void wavematrix(vector<vector<int> > &v)
{
    int m = v.size();
    int n = v[0].size();
    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
}
void reversewavematrix(vector<vector<int> > &v)
{
    int m = v.size();
    int n = v[0].size();
    for (int i = m - 1; i >= 0; i--)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
}
void spiralmatrix(vector<vector<int> > &v)
{
    int m = v.size();
    int n = v[0].size();
    int minr = 0;
    int maxr = m - 1;
    int minc = 0;
    int maxc = n - 1;
    while (minc <= maxc && minr <= maxr)
    {
        // right
        for (int j = minc; j <= maxc; j++)
        {
            cout << v[minr][j] << " ";
        }
        minr++;
        // down
        if (minc > maxc || minr > maxc)
            break;
        for (int i = minr; i <= maxr; i++)
        {
            cout << v[i][maxc] << " ";
        }

        maxc--;
        // left
        if (minc > maxc || minr > maxc)
            break;
        for (int j = maxc; j >= minc; j--)
        {
            cout << v[maxr][j] << " ";
        }
        maxr--;
        // up
        if (minc > maxc || minr > maxc)
            break;
        for (int i = maxr; i >= minr; i--)
        {
            cout << v[i][minc] << " ";
        }
        minc++;
    }
}

int main()
{
    int m;
    cout << "Enter rows : " << endl;
    cin >> m;
    int n;
    cout << "Enter columns : " << endl;
    cin >> n;
    vector<vector<int> > a(m, vector<int>(n));
    cout
        << "Enter elements : " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Matrix given by looks like this" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Your matrix in wave form is as follows" << endl;
    wavematrix(a);
    cout << endl;
    cout << "Your matrix in reverse wave form is as follows" << endl;
    reversewavematrix(a);
    cout << endl;
    cout << "Your matrix in spiral form is as follows" << endl;
    spiralmatrix(a);
}