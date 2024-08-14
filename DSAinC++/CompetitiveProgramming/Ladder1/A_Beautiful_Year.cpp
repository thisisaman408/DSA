#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n + 1; i <= 9876; i++) {
        int year = i;
        int d1, d2, d3, d4;

        d1 = year % 10; 
        year /= 10;
        d2 = year % 10; 
        year /= 10;
        d3 = year % 10; 
        year /= 10;
        d4 = year % 10;
        if (d1 != d2 && d1 != d3 && d1 != d4 && 
            d2 != d3 && d2 != d4 && 
            d3 != d4) {
            cout << i << endl; 
            break;
        }
    }

    return 0;
}
