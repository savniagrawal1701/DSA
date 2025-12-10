#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class solution{
    public:
    Node* findTail(Node* head) {
  Node* tail = head;
  while(tail->next != NULL) tail = tail->next;
  return tail;
}

vector<pair<int, int>> findPairs(Node* head, int k)
{
  vector<pair<int, int>> ans;
  if (head == NULL) return ans;
  Node* left = head;
  Node* right = findTail(head);
  while(left->data < right->data) {
    if(left->data + right->data == k) {
      ans.push_back({left->data, right->data});
      left = left->next;
      right = right->prev;
    }
    else if (left->data + right->data < k) {
      left = left->next;
    }
    else right = right->prev;
  }
  return ans;
}
};
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    solution s;
    int k = 5;
    vector<pair<int, int>> result = s.findPairs(head, k);

    for (const auto& p : result) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
