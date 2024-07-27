#include <iostream>

using namespace std;

class MinHeap
{
public:
    int arr[50];
    int idx;
    MinHeap() : idx(1) {}

    // functions
    int top()
    {
        return arr[1];
    }

    void push(int val)
    {
        if (idx == 50)
        {
            cout << "Heap is Full Now" << endl;
            return;
        }
        arr[idx] = val;
        int i = idx;
        idx++;
        while (i != 1)
        {
            if (arr[i] < arr[i / 2])
            {
                swap(arr[i], arr[i / 2]);
            }
            else
                break;
            i = i / 2;
        }
    }

    void pop()
    {
        idx--;
        arr[1] = arr[idx];
        int i = 1;
        while (1)
        {
            int l = 2 * i, r = 2 * i + 1;
            if (l > idx - 1)
                break;
            if (r > idx - 1)
            {
                if (arr[i] > arr[l])
                {
                    swap(arr[i], arr[l]);
                    i = l;
                }
                break;
            }
            if (arr[l] < arr[r])
            {
                if (arr[i] > arr[l])
                {
                    swap(arr[i], arr[l]);
                    i = l;
                }
                else
                    break;
            }
            if (arr[l] > arr[r])
            {
                if (arr[i] > arr[r])
                {
                    swap(arr[i], arr[r]);
                    i = r;
                }
                else
                    break;
            }
        }
    }
    int size()
    {

        return idx - 1;
    }

    void display()
    {
        for (int i = 1; i <= idx - 1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
};

int main()
{
    MinHeap pq;
    pq.push(10);
    pq.push(2);
    pq.push(11);
    cout << pq.top() << " " << pq.size() << endl;
    pq.display();
    pq.push(23);
    pq.push(18);
    cout << pq.top() << " " << pq.size() << endl;
    pq.display();
    pq.pop();
    pq.pop();
    cout << pq.top() << " " << pq.size() << endl;
    pq.display();
}