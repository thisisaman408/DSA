// in this implementation we represent graph as an array of linked list
// i am going to implement graph using the adjaceny list

// here, basically it is a vector//array of linked list
/*
let us understand here

say graph is something like this

i am drawing graph as per the edges only, i mean i will write vertex to edge

1-> 2
1-> 4
1-> 5
2->5
2->4
2->3
3-> 5

say this is a simple graph

how do we implement this, mathematically??

LinkedList arr[];
here, how will I represent the above graph??

at 0th index there will be a list of every element which is connected to 1

as here,
first index of array will contain

1->2->4->->5

second index
2->5->4->3

third index
3->5

so that's how we can represent and implement our graph using array and linked list


and we call this implementation as adjaceny list....
we will be representing our graph by adjaceny matrix for appprox say, 99% of the time~

*/

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int val) : value(val), next(NULL) {}
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int size;

    LinkedList() : head(NULL), tail(NULL), size(0) {}

    void insertAtEnd(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        {
            head = tail = temp;
        }
        else
        {
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
            for (int i = 0; i < idx - 1; i++)
            {
                t = t->next;
            }
            temp->next = t->next;
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
            head = head->next;
            delete temp;
            size--;
            if (size == 0)
            {
                tail = NULL;
            }
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
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = NULL;
            size--;
        }
    }

    void deleteAtIndex(int idx)
    {
        if (size <= 0)
        {
            cout << "Linked List is empty" << endl;
        }
        else if (idx < 0 || idx >= size)
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
            Node *left = head;
            Node *right = head->next;
            for (int i = 0; i < idx - 1; i++)
            {
                left = left->next;
                right = right->next;
            }
            left->next = right->next;
            delete right;
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

    ~LinkedList()
    {
        while (head != NULL)
        {
            deleteAtHead();
        }
    }
};

int main(){
    LinkedList graph[];
    graph[0] = new Node (1);
    graph[0]->next = new Node(2);
    graph[0]->next->next = new Node(3);
    graph[1] = new Node(2);
    graph[1]->next = new Node(3);
    for(int i = 0; i< sizeof(graph)/sizeof(graph[0]); i++){
        cout<<graph[i]<<" ";
        Node * temp = graph[i];
        while(temp){
            temp = temp->next;
            cout<<temp->value<<" ";
        }
        cout<<endl;
    }
}