#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> pq; // by default it is max heap
    pq.push(10);
    pq.push(100);
    pq.push(5);
    pq.push(4);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    priority_queue<int, vector<int>, greater<int>> p; // for min headp
    p.push(10);
    p.push(100);
    p.push(5);
    p.push(4);
    cout << p.top() << endl;
    p.pop();
    cout << p.top() << endl;
}