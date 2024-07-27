#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cout << "Enter string with spaces : ";
    getline(cin, s);
    cout << s;
    return 0;
}
/*here, if we use cin, then cin has a propert, that after either space or enter
the written thing is considered as another object, hence we use getline for strings*/