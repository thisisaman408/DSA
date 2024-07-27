#include <iostream>
using namespace std;

class ListNode
{
public:
    int value;
    ListNode *next;
    ListNode(int val) : value(val), next(NULL) {}
};
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        bool flag = false;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            return NULL;
        else
        {
            ListNode *help = head;
            while (help != slow)
            {
                slow = slow->next;
                help = help->next;
            }
            return slow;
        }
    }
};
// dry run to get the feel, easy peasy questions
/*

why slow and fast actually works

let the total distance of the linked list is = l;
the distance of nodes which are not in cycle = n ;
the distance from the starting node of cycle to the node where slow and fast are equal = m ;
Now, say slow == fast at m,
now, distance travveled by slow = n + m;
also distance travelled by fast = l + m + l -n -m = 2l - n;
now, we know that fast always travelss, twice the distance than slow,
thus, if this is true, that slow and fast are meeting, then there should be some value of m (real).

Thus, distance travelled by slow = n + m
distance travelled by fast - 2l - n;
now,
as per our logic
2n + 2m = 2l - n;
n + 2m = 2l;
m = (2l - n)/2;
thus m exist, hence it is satisfacory condition

*/