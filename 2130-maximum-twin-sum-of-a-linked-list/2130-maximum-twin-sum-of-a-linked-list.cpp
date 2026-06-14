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
class Solution {
public:
    
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        if(head->next==nullptr)return (slow->val+fast->val);

        while(fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* prev = slow;
        ListNode* curr = slow->next;
        prev->next = nullptr;
        while(curr->next!=nullptr){
            ListNode* temp = curr;
            curr = curr->next;
            temp->next= prev;
            prev = temp;
        }
        curr->next  = prev;
        int temp = 0;
        while(head!=nullptr&&curr!=nullptr){
           temp = max(curr->val+head->val, temp);
           curr = curr->next;
           head = head->next;
        }
        return temp;
    }
};