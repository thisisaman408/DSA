#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> m;
    // it accepts only pair
    pair<string, int> p;
    p.first = "Aman";
    p.second = 21;
    m.insert(p);
    pair<string, int> p1;
    p1.first = "Sunaina";
    p1.second = 21;
    m.insert(p1);
    pair<string, int> p2;
    p2.first = "kanha";
    p2.second = 108;
    m.insert(p2);
    pair<string, int> p3;
    p3.first = "Suru";
    p3.second = 22;
    m.insert(p3);

    // another method to insert elements in the map
    //  map[key] = value

    m["Physics"] = 90; // this will insert it
    m["Biology"] = -1;
    m["Madan"] = 1;
    for (auto ele : m)
    {
        cout << ele.first << " " << ele.second;
        cout << endl;
    }
    // printing like LIFO stack, but generally these things are printed randomly
}
