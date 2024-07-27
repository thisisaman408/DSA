#include <iostream>
using namespace std;
void towerofhanoi(int n, char a, char b, char c)
{
    if (n == 0)
    {
        return;
    }
    towerofhanoi(n - 1, a, c, b);
    cout << a << "->" << c << endl;
    towerofhanoi(n - 1, b, a, c);
}
int main()
{
    int n;
    int source;
    int help;
    int destination;
    cout << "Enter the no of discs : ";
    cin >> n;
    towerofhanoi(n, 'A', 'B', 'C');
}
/*
3
3 == ? NO,
2,A,C,B
2 == 0?, No,
1,A,B,C
1 == 0?, No
0,A,C,B

*/