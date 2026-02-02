#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Compare {
public:
    
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        
        for (auto list : lists) {
            if (list != NULL)
                pq.push(list);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            
            ListNode* smallest = pq.top();
            pq.pop();
 
            tail->next = smallest;
            tail = tail->next;
            
            if (smallest->next != NULL)
                pq.push(smallest->next);
        }

        return dummy->next;
    }
};


int main() {
    Solution sol;

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode*> lists = {list1, list2, list3};
    ListNode* result = sol.mergeKLists(lists);
    
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
