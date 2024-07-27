#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int v) : value(v), next(NULL) {}
};

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;  // Move to the next node
    }
    cout << endl;
}

void insertAtEnd(int val, Node *head)
{
    Node *t = new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = t;
}

int main()
{
    // 10 20 30 40
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);

    // Connect nodes together to form a linked list
    a.next = &b;
    b.next = &c;
    c.next = &d;

    // Display the initial linked list
    display(&a);

    // Insert a new node with value 50 at the end
    insertAtEnd(50, &a);

    // Display the updated linked list
    display(&a);

    return 0;
}
