/* n stairs are given, and then a boy is allowed to climb 1 or 2 stairs at a time
then in how many ways cam he reach the top most stairs, this is the problem which is really easy
if we use recursion*/
#include <iostream>
using namespace std;
long long stair(long long n)
{
	if(n == 1){
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	return stair(n - 2) + stair(n - 1);
}
int main()
{
	long long n;
	cout << "Enter the no of stairs : ";
	cin >> n;
	long long ans = stair(n);
	cout <<ans;
}
// this is similar as fibbonacci, isn't it, fibbonacci is a pattern of nature, so ofcourse it will
// be observed at so many places