#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *child;
    ListNode() {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2) {
        val = data1;
        next = next1;
        child = next1;
    }
};

class Solution {
private:
   
    ListNode* merge(ListNode* list1, ListNode* list2){
      
        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode;
    
        
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                res->child = list1;
                res = list1;
                list1 = list1->child;
            }
            else{
                res->child = list2;
                res = list2;
                list2 = list2->child;
            }
            res->next = NULL;
        }
    
        
        if(list1){
            res->child = list1;
        } else {
            res->child = list2;
        }
    
        if(dummyNode->child){
            dummyNode->child->next = NULL;
        }
        
        return dummyNode->child;
    }

public:
  
    ListNode* flattenLinkedList(ListNode* head) {
       
        if(head == NULL || head->next == NULL){
            return head; // Return head
        }
    
       
        ListNode* mergedHead = flattenLinkedList(head->next);
        
        // Merge the lists
        head = merge(head, mergedHead);
        return head;
    }
};

// Function to print the linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->child;
    }
    cout << endl;
}


void printOriginalLinkedList(ListNode* head, int depth) {
    while (head != nullptr) {
        cout << head->val;

        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        // Add vertical bars for each level in the grid
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main() {

    ListNode* head = new ListNode(5);
    head->child = new ListNode(14);

    head->next = new ListNode(4);
    head->next->child = new ListNode(10);

    head->next->next = new ListNode(12);
    head->next->next->child = new ListNode(22);
    head->next->next->child->child = new ListNode(33);

    head->next->next->next = new ListNode(7);
    head->next->next->next->child = new ListNode(17);

    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    Solution sol;
    
    ListNode* flattened = sol.flattenLinkedList(head);
    

    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}