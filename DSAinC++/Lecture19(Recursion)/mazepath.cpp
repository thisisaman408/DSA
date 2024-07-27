#include <iostream>
using namespace std;
int mazepath(int sr, int sc, int er, int ec)
{
    if (sr > er || sc > ec)
    {
        return 0;
    }
    if (sr == er && sc == ec)
    {
        return 1;
    }

    int righpathways = mazepath(sr, sc + 1, er, ec);
    // this is basically if we move right, then our row remain same, but columns no changes,
    // imagine it like a matrix
    int downpathways = mazepath(sr + 1, sc, er, ec);
    // similarly when we move downways our column remain same but our row number increases
    int ans = righpathways + downpathways;
    return ans;
}
void printpath(int sr, int sc, int er, int ec, string s)
{
    if (sr > er || sc > ec)
    {
        return;
    }
    if (sr == er && sc == ec) // destination reached so simply print the path
    {
        cout << s << endl;
        return;
    }

    printpath(sr, sc + 1, er, ec, s + "R");
    // this is basically if we move right, then our row remain same, but columns no changes,
    // imagine it like a matrix
    printpath(sr + 1, sc, er, ec, s + "D");
    // similarly when we move downways our column remain same but our row number increases
}
int main()
{
    int sr = 1;
    int sc = 1;
    string s = "";
    // sr == starting row. sc == starting column, er == ending row (no of rows)
    // ec == ending columns (no of columns)
    int er, ec;
    cout << "Enter no of rows : ";
    cin >> er;
    cout << "Enter no columns: ";
    cin >> ec;
    int p = mazepath(sr, sc, er, ec);
    cout << p << endl;
    printpath(sr, sc, er, ec, s);
}