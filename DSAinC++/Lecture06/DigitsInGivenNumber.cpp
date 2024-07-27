#include <iostream>
using namespace std;
int main()
{
    int x;
    cout << "Enter a number :" << endl;
    cin >> x;
    int count = 0;
    int a = x;
    while (x /= 10)
    {
        count++;
    }
    cout << "The no of digits in the number are " << count + 1 << endl;
    return 0;
}
/*
if hum while (x >0) {
    x /= 10 ye wala code likhte hai to fir isme ek dkkt hai, hame x ko pehle 
    a ya kisi v variable m store karwana hoga. Taki loop ke end mai 
    x ki original value ka use karke x = 0 wala case solve kr sake..x = 0 par 
    0 ans aaega is case mei
}*/