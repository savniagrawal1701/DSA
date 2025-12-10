#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};


void push(Node*& head, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = head;
    if (head != nullptr) {
        head->prev = new_node;
    }
    head = new_node;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

Node *deleteAllOccurrences(Node*& head, int key) {
   Node *temp=head;
   while(temp!=nullptr){
    if(temp->data==key){
        if(temp==head){
            head=temp->next;
        }
        Node *nextNode=temp->next;
        Node *prevNode =temp->prev;
        if(nextNode!=nullptr) nextNode->prev=prevNode;
        if(prevNode!=nullptr) prevNode->next=nextNode;
        free(temp);
        temp=nextNode;
    }
    else{
        temp=temp->next;
    }
   }
   return head;
}

int main() {
    Node* head = nullptr;

    push(head, 2);
    push(head, 5);
    push(head, 2);
    push(head, 8);
    push(head, 2);
    push(head, 10);

    cout << "Original Doubly Linked List: ";
    printList(head);

    int keyToDelete = 2;
    deleteAllOccurrences(head, keyToDelete);

    cout << "Doubly Linked List after deleting all occurrences of " << keyToDelete << ": ";
    printList(head);


    return 0;
}