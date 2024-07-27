// in this we will create a class of linked list, in which we will create all the fucntions, to do basic operation on linked list
// first node is known as head, and the last node is  known as tail,

#include <iostream>
using namespace std;
class Node // user defined data type
{
public:
    int value;
    Node *next;
    Node(int val) : value(val), next(NULL) {}
};

class LinkedList // user defined data structure(as we used to create array etc)
{
public:
    Node *head; // will point at the first node
    Node *tail; // will point at the last node
    int size;
    // these head and tail has their value and their next, ofcourse as their data type is Node, which we have initialised before
    // now we have to make both of them as NULL, as in starting there is no linked list or there is empty linked list

    LinkedList() : head(NULL), tail(NULL), size(0) {}
    // size is 0 initially as there is no linked list at the moment

    // function to enter the value at the tail of the linked list
    void insertAtEnd(int val)
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
            head = temp;
        }
        size++;
    }

    // function to insert at the index

    void insertAtIndex(int idx, int val)
    {
        if (idx < 0 || idx > size)
            cout << "Invalid Index" << endl;
        else if (idx == 0)
            insertAtBeginning(val);
        else if (idx == size)
            insertAtEnd(val);
        else
        {
            Node *temp = new Node(val);
            Node *t = head;
            for (int i = 0; i < idx - 1; i++)
            {
                t = t->next;
            }
            temp->next = t->next;
            t->next = temp;
            size++;
        }
    }

    // fucntino to get the value at the index in a linked list ofcourse

    int getAtIdx(int idx)
    {
        if (idx < 0 || idx >= size)
        {
            cout << "Invalid Index" << endl;
            return -1;
        }
        else if (idx == 0)
            return head->value;
        else if (idx == size - 1)
            return tail->value;
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

    // function to delete at head
    void deleteAtHead()
    {
        if (size == 0)
            cout << "Linked List is empty" << endl;
        else
        {
            head = head->next;
            size--;
        }
    }

    // delete at tail
    void deleteAtTail()
    {
        if (size == 0)
            cout << "Linked List is empty" << endl;
        else if (size == 1)
        {
            head = tail = NULL;
            size = 0;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            tail = temp;
            size--;
        }
    }

    // function to delete a node at some particular index

    void deleteAtIndex(int idx)
    {
        if (size <= 0)
            cout << "Linked List is empty" << endl;
        else if (idx == 0)
            deleteAtHead();
        else if (idx == (size - 1))
            deleteAtTail();
        else
        {
            Node *left = head;
            Node *right = head->next;
            for (int i = 0; i < idx - 1; i++)
            {
                left = left->next;
                right = right->next;
            }
            left->next = right->next;
            size--;
        }
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
    LinkedList ll;

    cout << "Insertion at the end" << endl;
    ll.insertAtEnd(10);
    ll.display();
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.display();
    // thus our code is working
    cout << ll.size << endl;

    // let's add something at the beginning
    cout << "Insertion in the beginning" << endl;
    ll.insertAtBeginning(9);
    ll.display();
    ll.insertAtBeginning(8);
    ll.display();

    // let's now add values at some indexes in between
    ll.insertAtIndex(2, 78);
    ll.display();
    ll.insertAtIndex(0, 19);
    ll.insertAtIndex(ll.size, 38);
    ll.display();
    cout << ll.size << endl;

    cout << "Checking the getAtIndex function" << endl;
    // let's get the value at some indexes
    cout << ll.getAtIdx(5) << endl;
    // this is working perfectly

    cout << "From here, we are checking the deleting functions" << endl;
    // let us delete the head node, and see
    cout << "Before deleting head" << endl;
    ll.display();
    ll.deleteAtHead();
    cout << "After deleting head" << endl;
    ll.display();
    // thus it is working

    // now delete at tail
    cout << "We are deleting at tail now" << endl;
    cout << "Before deleting tail" << endl;
    ll.display();
    ll.deleteAtTail();
    cout << "After deleting tail" << endl;
    ll.display();
    cout << ll.size << endl;

    
    //now we will delete the value at some index
    cout<<"Here we are deleting value at index"<<endl;
    cout << "Before deleting at index" << endl;
    ll.display();
    ll.deleteAtIndex(2);
    cout << "After deleting index" << endl;
    ll.display();
    cout << ll.size << endl;
    //this is working perfectly
}
