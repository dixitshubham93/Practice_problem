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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr){return head;}
        
        ListNode* counter = head;
        int count  = 0;
       
        while(counter->next!=nullptr)
        {
            counter = counter->next;
            count++;
        }
        count++;
        counter->next = head;
        if(count!=0){
        k = k%count;}
        count = count - k-1;
        counter = head;
        while(count--&&counter!=nullptr)
        {
          counter = counter->next; 
        }
        head = counter->next;
        counter->next = nullptr;
        return head;
    }
};