#include <iostream>
using namespace std;
int main()
{
    int i = (4 + 7 / 5 * 6 * 6 + 9) % 100;
    cout << i;
}
// it's all about the precedene , / and * has higher precedence than the + and - 