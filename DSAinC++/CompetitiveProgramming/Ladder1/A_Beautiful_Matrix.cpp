#include<iostream>
#include<vector>

using namespace std;
int main() {
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            int a;
            cin >> a;
            if(a == 1) {
                sum = abs(2 - i) + abs(2 - j);
                break;
            }
        }
    }
    cout << sum <<endl;
}
