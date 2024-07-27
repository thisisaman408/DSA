#include <iostream>
using namespace std;
int main()
{
    int x1, y1, x2, y2, x3, y3;
    cout << "First co-ordinate : " << endl;
    cin >> x1 >> y1;
    cout << "Second co-ordinate : " << endl;
    cin >> x2 >> y2;
    cout << "Third co-ordinate : " << endl;
    cin >> x3 >> y3;
    float slope1 = float(y2 - y1) / (x2 - x1);
    float slope2 = float(y3 - y2) / (x3 - x2);
    if (slope1 == slope2)
    {
        cout << "Points are collinear" << endl;
    }
    else
    {
        cout << "Points are not collinear" << endl;
    }
    return 0;
}