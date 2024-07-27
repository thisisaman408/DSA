#include <iostream>
#include <unordered_set>

using namespace std;
int main()
{
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(5);
    s.insert(6);
    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(5);
    // s.insert(6);

    // s.find(a) != s.end() basically this checks that whether a exist till the end of s,
    int target = 2;
    if (s.find(target) != s.end())
        cout << "Exists";
    else
        cout << "Does not exists";
    cout << endl;
    cout << s.size() << endl;
    for (int ele : s)
    {
        cout << ele << " ";
    }
}
// set stores only unique elements