#include <iostream>
#include <string>
using namespace std;

#define ll long long int
int main() {
    ll n;
    cin>>n;
    int count = 0;
    while(n){
        if(n%10 == 4 or n%10 == 7)count++;
        n /=10;
    }
    if(count == 4 or count == 7) cout<<"YES";
    else cout <<"NO";
}
