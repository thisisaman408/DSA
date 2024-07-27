#include <iostream>
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

int main()
{
    LinkedList ll;
    int choice, value, index;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at Index\n";
        cout << "4. Get Value at Index\n";
        cout << "5. Delete at Head\n";
        cout << "6. Delete at Tail\n";
        cout << "7. Delete at Index\n";
        cout << "8. Display\n";
        cout << "9. Display size\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at end: ";
            cin >> value;
            ll.insertAtEnd(value);
            break;
        case 2:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            ll.insertAtBeginning(value);
            break;
        case 3:
            cout << "Enter index and value to insert: ";
            cin >> index >> value;
            ll.insertAtIndex(index, value);
            break;
        case 4:
            cout << "Enter index to get value: ";
            cin >> index;
            value = ll.getAtIdx(index);
            if (value != -1)
            {
                cout << "Value at index " << index << ": " << value << endl;
            }
            break;
        case 5:
            ll.deleteAtHead();
            break;
        case 6:
            ll.deleteAtTail();
            break;
        case 7:
            cout << "Enter index to delete: ";
            cin >> index;
            ll.deleteAtIndex(index);
            break;
        case 8:
            ll.display();
            break;
        case 9:
            cout << ll.size << endl;
            break;
        case 10:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 10);

    return 0;
}
