//optimised solution
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data; 
    Node* next;     
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
class solution{
public:
Node* deletenode(Node *head,int n){
    Node *fast=head;
   
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    Node *slow=head;
    if(fast==NULL){
        Node *newhead=head->next;;
        delete(head);
        return newhead;
    }
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    Node *delnode=slow->next;
    slow->next=slow->next->next;
    delete(delnode);
return head;
    
}
void printLL(Node* head) {
        while (head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
    }
};
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;

    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    solution sol;
 
    head = sol.deletenode(head, N);

    sol.printLL(head);
}