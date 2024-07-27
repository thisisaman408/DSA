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

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    int size;
    DoublyLinkedList() : head(NULL), tail(NULL), size(0) {}

    void insertAtEnd(int val)
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

    void insertAtBeginning(int val)
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

    void insertAtIndex(int idx, int val)
    {
        if (idx < 0 || idx > size)
        {
            cout << "Invalid Index" << endl;
        }
        else if (idx == 0)
        {
            insertAtBeginning(val);
        }
        else if (idx == size)
        {
            insertAtEnd(val);
        }
        else
        {
            Node *temp = new Node(val);
            Node *t = head;
            for (int i = 1; i < idx; i++)
            {
                t = t->next;
            }
            temp->next = t->next;
            temp->prev = t;
            t->next->prev = temp;
            t->next = temp;
            size++;
        }
    }

    int getAtIdx(int idx)
    {
        if (idx < 0 || idx >= size)
        {
            cout << "Invalid Index" << endl;
            return -1;
        }
        else if (idx == 0)
        {
            return head->value;
        }
        else if (idx == size - 1)
        {
            return tail->value;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < idx; i++)
            {
                temp = temp->next;
            }
            return temp->value;
        }
    }

    void deleteAtHead()
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

    void deleteAtTail()
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

    void deleteAtIndex(int idx)
    {
        if (idx < 0 || idx >= size)
        {
            cout << "Invalid Index" << endl;
        }
        else if (idx == 0)
        {
            deleteAtHead();
        }
        else if (idx == size - 1)
        {
            deleteAtTail();
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < idx; i++)
            {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
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
    DoublyLinkedList ll;

    cout << "Insertion at the end" << endl;
    ll.insertAtEnd(10);
    ll.display();
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.display();
    cout << ll.size << endl;

    cout << "Insertion in the beginning" << endl;
    ll.insertAtBeginning(9);
    ll.display();
    ll.insertAtBeginning(8);
    ll.display();

    ll.insertAtIndex(2, 78);
    ll.display();
    ll.insertAtIndex(0, 19);
    ll.insertAtIndex(ll.size, 38);
    ll.display();
    cout << ll.size << endl;

    cout << "Checking the getAtIndex function" << endl;
    cout << ll.getAtIdx(5) << endl;

    cout << "From here, we are checking the deleting functions" << endl;
    cout << "Before deleting head" << endl;
    ll.display();
    ll.deleteAtHead();
    cout << "After deleting head" << endl;
    ll.display();

    cout << "We are deleting at tail now" << endl;
    cout << "Before deleting tail" << endl;
    ll.display();
    ll.deleteAtTail();
    cout << "After deleting tail" << endl;
    ll.display();
    cout << ll.size << endl;

    cout << "Here we are deleting value at index" << endl;
    cout << "Before deleting at index" << endl;
    ll.display();
    ll.deleteAtIndex(2);
    cout << "After deleting index" << endl;
    ll.display();
    cout << ll.size << endl;

    return 0;
}
