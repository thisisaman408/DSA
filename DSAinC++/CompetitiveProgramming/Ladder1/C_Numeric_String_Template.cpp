#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

bool matchesTemplate(const vector<int>& a, const string& s) {
    int n = a.size();
    if (s.size() != n) return false;

    unordered_map<int, char> numToChar;
    unordered_map<char, int> charToNum;

    for (int i = 0; i < n; ++i) {
        char c = s[i];
        int num = a[i];

        if (numToChar.find(num) != numToChar.end()) {
            if (numToChar[num] != c) return false;
        } else {
            numToChar[num] = c;
        }

        if (charToNum.find(c) != charToNum.end()) {
            if (charToNum[c] != num) return false;
        } else {
            charToNum[c] = num;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int m;
        cin >> m;

        while (m--) {
            string s;
            cin >> s;
            if (matchesTemplate(a, s)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
