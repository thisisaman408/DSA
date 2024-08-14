#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

bool ele(unordered_set<int>& uset, int element) {
    return uset.find(element) != uset.end();
}

int main(){
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> seats(n);
        unordered_set<int> occupied;
        bool valid = true;

        for (int i = 0; i < n; ++i) {
            cin >> seats[i];
        }

        for (int i = 0; i < n; ++i) {
            int seat = seats[i];
            if (i == 0) occupied.insert(seat);
            else {
                if (!(ele(occupied, seat - 1) || ele(occupied, seat + 1))) {
                    valid = false;
                    break;
                }
                occupied.insert(seat);
            }
        }

        cout << (valid ? "YES" : "NO") << endl;
    }

    return 0;
}
