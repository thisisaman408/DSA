#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include<cstring>
#include<string.h>
#include<queue>

using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

#define ll long long
#define lli long long int

priority_queue<int> maxHeap;
priority_queue<int,vector<int>, greater <int> > minHeap;
void solve() {
    int n;
    cin>>n;
    int ans = 0;
    int i=0;
    while(n--){
        i++;
        int x;
        cin>>x;
        if(i ==1){
            maxHeap.push(x);
            minHeap.push(x);
            continue;
        }
        if(x > maxHeap.top() or x <minHeap.top()) ans++;
        maxHeap.push(x);
        minHeap.push(x);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}