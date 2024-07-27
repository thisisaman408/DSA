#include <iostream>
using namespace std;
class Node // user defined data type
{
public:
    int value;
    Node *next;
    Node(int val) : value(val), next(NULL) {}
};

class Queue // user defined data structure(as we used to create array etc)
{
public:
    Node *head; // will point at the first node
    Node *tail; // will point at the last node
    int size;
    // these head and tail has their value and their next, ofcourse as their data type is Node, which we have initialised before
    // now we have to make both of them as NULL, as in starting there is no linked list or there is empty linked list

    Queue() : head(NULL), tail(NULL), size(0) {}
    // size is 0 initially as there is no linked list at the moment

    // function to enter the value at the tail of the linked list
    void push(int val)
    {
        // first we will create a new node "temp" dynamically
        Node *temp = new Node(val); // we have created a single new node which now has a value "val" and it's next is pointing towards NULL, see Node class
        if (size == 0)              // linked list is empty, thus head == tail == NULL
        {
            head = tail = temp;
        }
        else // when size is not zero
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    // function to insert element at the beginning of the linked list

    // function to insert at the index

    // function to delete at head
    void pop()
    {
        if (size == 0)
            cout << "Queue is empty" << endl;
        else
        {
            Node *temp = head;
            head = head->next;
            size--;
            delete (temp);
        }
    }
    int front()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return head->value;
    }
    int back()
    {
        return tail->value;
    }
    // function to display the linked list
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
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