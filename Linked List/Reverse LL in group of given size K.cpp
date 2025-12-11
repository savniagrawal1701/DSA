#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nextNode = nullptr;
        while (curr != nullptr)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    ListNode *getKthNode(ListNode *curr, int k)
    {
        while (curr && k > 0)
        {
            curr = curr->next;
            k--;
        }
        return curr;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {

        ListNode *temp = head;
        ListNode *prevLast = NULL;
        while (temp != NULL)
        {
            ListNode *Kthnode = getKthNode(temp, k-1);
            if (Kthnode == NULL)
            {
                if (prevLast)
                    prevLast->next = temp;
                break;
            }
            ListNode *nextnode = Kthnode->next;
            Kthnode->next = NULL;
            reverseLinkedList(temp);
            if (temp == head)
            {
                head = Kthnode;
            }
            else
            {
                prevLast->next = Kthnode;
            }
            prevLast = temp;
            temp = nextnode;
        }
        return head;
    }
};

int main()
{
    Solution obj;

    // Creating the linked list: 1->2->3->4->5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *result = obj.reverseKGroup(head, 2);

    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
