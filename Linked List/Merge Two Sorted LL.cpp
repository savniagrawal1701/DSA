#include <bits/stdc++.h>
using namespace std;
class ListNode {
public:
    int val; 
    ListNode* next;     
    ListNode(int data1, ListNode* next1) {
        val = data1;
        next = next1;
    }
    ListNode(int data1) {
        val = data1;
        next = nullptr;
    }
};
void PrintList(ListNode *head) // Function to print the LinkedList
{
    ListNode *curr = head;
    for (; curr != nullptr; curr = curr->next)
        cout << curr->val << "-->";
    cout << "null" << endl;
}
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* dnode = new ListNode(-1);
        ListNode* temp = dnode;
        while (t1 != NULL && t2 != NULL) {
            if (t1->val < t2->val) {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            } else {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        if (t1)
            temp->next = t1;
        else
            temp->next = t2;
             return dnode->next;
    }
   

}
;
int main() {
//list1
    ListNode* head1 = new ListNode(3);
    ListNode* second = new ListNode(7);
    ListNode* third = new ListNode(9);
    ListNode* fourth = new ListNode(10);
    ListNode* fifth = new ListNode(11);
    
    head1->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

//list2
ListNode* head2 = new ListNode(4);
    ListNode* second2 = new ListNode(5);
    ListNode* third2 = new ListNode(6);
    ListNode* fourth2 = new ListNode(8);
    ListNode* fifth2 = new ListNode(12);
    
    head2->next = second2;
    second2->next = third2;
    third2->next = fourth2;
    fourth2->next = fifth2;
     Solution obj;
    ListNode *newHead = obj.mergeTwoLists(head1,head2);
    cout << "LinkedList After merging " << endl;
    PrintList(newHead);
    return 0;
}
