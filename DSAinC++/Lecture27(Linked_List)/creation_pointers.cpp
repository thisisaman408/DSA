#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int v) : val(v), next(NULL) {}
};

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";

        temp = temp->next;
    }
}
int size(Node *head)
{
    Node *temp = head;
    int n = 0;
    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    return n;
}
void display_recursively(Node *head)
{
    if (head == NULL)
        return;
    cout << head->val << " ";
    display_recursively(head->next);
}
void reverse_order(Node *head)
{
    if (head == NULL)
        return;
    reverse_order(head->next);
    cout << head->val << " ";
}
int main()
{
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    a->next = b;
    b->next = c;
    c->next = d;
    display(a);
    cout << endl;
    cout << size(a) << endl;
    display_recursively(a);
    cout << endl;
    reverse_order(a);
    // a better method to print the entire linked list
}
