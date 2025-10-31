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
    ListNode* oddEvenList(ListNode* head) {
         if(head == NULL || head->next == NULL) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;

        while(even!=NULL && even->next!=NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
    
};
int main() {

    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
     Solution obj;
    ListNode *newHead = obj.oddEvenList(head);
    cout << "LinkedList After Segregration " << endl;
    PrintList(newHead);
    return 0;
}