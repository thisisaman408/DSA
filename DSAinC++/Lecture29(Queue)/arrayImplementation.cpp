#include <iostream>

using namespace std;

class Queue
{
public:
    int f;
    int b;
    int arr[5];
    
    Queue() : f(0), b(0) {}

    void push(int val)
    {
        if ((b - f) == 5)
        {
            cout << "Queue is full" << endl;
            return;
        }
        else
        {
            arr[b] = val;
            b++;
        }
    }

    void pop()
    {
        if (b - f == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            f++;
        }
    }

    int front()
    {
        if (f - b == 0)
            return -1;
        else
            return arr[f];
    }

    int back()
    {
        if (f - b == 0)
            return -1;
        else if (b == f)
            return -1;
        else
            return arr[b];
    }

    int size()
    {
        return b - f;
    }

    bool empty()
    {
        if (f - b == 0)
            return true;
        else
            false;
    }
    void display()
    {
        for (int i = f; i < b; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
    q.pop();
    q.display();
    q.push(60);
    q.display();
}
