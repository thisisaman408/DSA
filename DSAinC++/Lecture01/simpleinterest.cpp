#include <iostream>
using namespace std;
int main () {
    cout << "Enter principal amount : " <<endl;
    float p;
    cin >>p;
    cout << "Enter interest rate : " << endl;
    float r;
    cin >> r;
    cout << "Enter time period : " << endl;
    float t; 
    cin >>t;
    int si;
    si = (p*r*t)/100;
    cout << "Simple Interest is : " << si << endl;
    cout <<"Total amount to pay after " << t << " years : " << p + si << endl;
    return 0;
}