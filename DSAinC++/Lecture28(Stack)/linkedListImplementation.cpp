#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int val) : value(val), next(NULL) {}
};

class Stack
{
public:
    Node *head;
    int size;
    Stack() : size(0), head(NULL) {}

    void push(int val)
    {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }

    void pop()
    {
        if (head == NULL)
            cout << "Stack is empty";

        else
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }

    int top()
    {

        return head->value;
    }

    void print(Node *temp)
    {
        if (temp == NULL)
            return;
        print(temp->next);
        cout << temp->value << " ";
    }
    void display()
    {
        Node *temp = head;
        print(temp);
        cout << endl;
    }
};
int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout << st.top();
    cout << endl;
    st.display();

    st.pop();
    cout << endl;
    cout << st.top();
    cout << endl;
    st.display();
    cout << endl;
}