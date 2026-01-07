/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;   // min-heap
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*,vector<ListNode*> ,Compare>q;

        ListNode* head = nullptr;
        ListNode* root = head;
        for(auto& it : lists){
            if(it!=nullptr){
                q.push(it);
            }
        }

        while(!q.empty()){
           ListNode* node = q.top();
           q.pop();
           if(head==nullptr){
            head = node;
            root = head;
            }
           else{
            head->next = node;
            head = node;
           } 
           if(node->next!=nullptr){
             q.push(node->next);
           }
    }
      return root;
    }
};