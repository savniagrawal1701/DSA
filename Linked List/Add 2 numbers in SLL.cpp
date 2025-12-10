#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *createList(vector<int> &arr)
    {
        ListNode *head = new ListNode(arr[0]);
        ListNode *temp = head;
        for (int i = 1; i < arr.size(); i++)
        {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return head;
    }

    void printList(ListNode *head)
    {
        while (head)
        {
            cout << head->val;
            if (head->next)
                cout << " -> ";
            head = head->next;
        }
        cout << endl;
    }
    ListNode *addtwonumbers(ListNode *num1, ListNode *num2)
    {
        ListNode *dummyhead = new ListNode();
        ListNode *curr = dummyhead;
        ListNode *temp1 = num1;
        ListNode *temp2 = num2;
        int carry = 0;
        while (temp1 != NULL || temp2 != NULL)
        {
            int sum = carry;
            if (temp1)
                sum += temp1->val;
            if (temp2)
                sum += temp2->val;
            ListNode *newnode = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = newnode;
            curr = curr->next;

            if (temp1)
                temp1 = temp1->next;
            if (temp2)
                temp2 = temp2->next;
        }
        if (carry)
        {
            ListNode *newnode = new ListNode(carry);
            curr->next = newnode;
        }
        return dummyhead->next;
    }
};
int main()
{
    vector<int> num1 = {1,2, 4, 3}; // represents 342
    vector<int> num2 = {9,5, 6, 4}; // represents 465
Solution s1;
    ListNode *l1 = s1.createList(num1);
    ListNode *l2 = s1.createList(num2);

    Solution sol;
    ListNode *result = sol.addtwonumbers(l1, l2);
    sol.printList(result); // Output: 7 -> 0 -> 8
    return 0;
}
