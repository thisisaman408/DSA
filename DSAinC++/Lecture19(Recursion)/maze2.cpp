// same questin in a better way
#include <iostream>
using namespace std;
int mazepath(int row, int col)
{
    if (row < 1 || col < 1)
    {
        return 0;
    }
    else if (row == 1 && col == 1)
    {
        return 1;
    }
    int i = mazepath(row, col - 1);
    int j = mazepath(row - 1, col);
    return (i + j);
}
void printpath(int row, int col, string s)
{
    if (row < 1 || col < 1)
    {
        return;
    }
    else if (row == 1 && col == 1)
    {
        cout << s << endl;
        return;
    }
    printpath(row, col - 1, s + "R");
    printpath(row - 1, col, s + "D");
}
int main()
{
    int row, col;
    cout << "Enter no of rows : ";
    cin >> row;
    cout << "Enter no columns: ";
    cin >> col;
    int p = mazepath(row, col);
    cout << p << endl;
    printpath(row, col, "");
    // here what we have done, see if we write the index of the maze in reverse, then
    // the last cell will always be 1,1 and initially we can give anything to our initial cell
    // that will be our input, so we will need just two parameters
}