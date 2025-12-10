#include <bits/stdc++.h>
using namespace std;
class node {
public:
    int data; 
    node* next;     
    node(int data1, node* next1) {
        data = data1;
        next = next1;
    }
    node(int data1) {
        data = data1;
        next = nullptr;
    }
};
class solution{
public:
void insertNode(node* &head, int val) {
    node* newNode = new node(val);
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
}
int getDifference(node* head1, node* head2) {
    int len1 = 0, len2 = 0;
    while (head1 != NULL || head2 != NULL) {
        if (head1 != NULL) {
            ++len1;
            head1 = head1->next;
        }
        if (head2 != NULL) {
            ++len2;
            head2 = head2->next;
        }
    }
    return len1 - len2;  
}


node* intersectionPresent(node* head1, node* head2) {
    if(head1==NULL || head2==NULL) return NULL;
   node* t1=head1;
    node* t2=head2;
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
    
    if(t1==t2) return t1;
    if(t1==nullptr) t1=head2;
 if(t2==nullptr) t2=head1;}
 return t1;
}

void printList(node* head) {
    while (head->next != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << head->data << endl;
}


};
int main() {
    node* head = NULL;
    solution sol;
    sol.insertNode(head, 1);
    sol.insertNode(head, 3);
    sol.insertNode(head, 1);
    sol.insertNode(head, 2);
    sol.insertNode(head, 4);
    node* head1 = head;
    head = head->next->next->next;  // Intersection point
    node* headSec = NULL;
    sol.insertNode(headSec, 3);
    node* head2 = headSec;
    headSec->next = head;  // Creating intersection
    
    // Printing the lists
    cout << "List1: ";
    sol.printList(head1);
    cout << "List2: ";
    sol.printList(head2);
    
    // Checking if intersection is present
solution s1;
    node* answerNode = s1.intersectionPresent(head1, head2);
    if (answerNode == NULL) 
        cout << "No intersection\n";
    else 
        cout << "The intersection point is " << answerNode->data<< endl;
    
    return 0;
}