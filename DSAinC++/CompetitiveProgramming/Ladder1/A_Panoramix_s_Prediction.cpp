#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;


void helper(vector<bool>& sieve) {
        int n = sieve.size() - 1;
        for (int i = 2; i <= sqrt(n); i++) {
            if (sieve[i]) { // Only consider `i` if it is marked as prime
                for (int j = i * i; j <= n; j += i) {
                    sieve[j] = false; // Mark all multiples of `i` as non-prime
                }
            }
        }
}
int main(){
    int a, b;
    cin>>a>>b;
    vector<bool>res(max(a,b)+1,1);
    res[0] = 0;
    res[1] = 0;
    helper(res);
    // for(int i= 0; i<res.size(); i++){
    //     cout<<i<<": "<<res[i]<<" ";
    // }
    // cout<<endl;
    bool flagg = true;
    if(res[a] and res[b]){
        flagg = false;
        bool flag = true;
        for(int i = a+1; i<=b-1;i++){
            if(res[i] != 0){
                cout<<"NO"<<endl;
                flag = false;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
    }
    if(flagg)cout<<"NO"<<endl;
}