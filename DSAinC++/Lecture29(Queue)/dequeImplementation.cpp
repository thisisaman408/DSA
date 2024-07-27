#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int val) : value(val), next(NULL), prev(NULL) {}
};

class Dequeue
{
public:
    Node *head;
    Node *tail;
    int size;
    Dequeue() : head(NULL), tail(NULL), size(0) {}

    void pushBack(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        {
            head = tail = temp;
        }
        else
        {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void pushFront(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        {
            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void popFront()
    {
        if (size == 0)
        {
            cout << "Linked List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            if (size == 1)
            {
                head = tail = NULL;
            }
            else
            {
                head = head->next;
                head->prev = NULL;
            }
            delete temp;
            size--;
        }
    }

    void popBack()
    {
        if (size == 0)
        {
            cout << "Linked List is empty" << endl;
        }
        else if (size == 1)
        {
            delete head;
            head = tail = NULL;
            size = 0;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
            size--;
        }
    }

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
    Dequeue q;
    q.pushBack(10);
    q.pushBack(20);
    q.pushBack(30);
    q.pushBack(40);
    q.pushBack(50);
    q.display();
    q.popFront();
    q.display();
    q.pushBack(60);
    q.display();
    q.pushFront(120);
    q.display();
    q.popBack();
    q.display();
}
