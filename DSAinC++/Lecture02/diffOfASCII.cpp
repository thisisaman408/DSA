#include <iostream>
using namespace std;
int main () {
    char a,b;
    cout <<"Enter first character : " <<endl;
    cin >> a;
    cout << "Enter second character : " <<endl;
    cin >> b;
    int x = (int)a;
    int y = (int)b;
    if (a > b){
        cout << a-b;
    }
    else {
        cout << b-a;
    }
}
