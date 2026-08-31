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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==nullptr||head->next==nullptr||head->next->next==nullptr)return {-1 , -1};
        int first = -1;
        int last= -1;
        int minDistance = INT_MAX;
        int count = 2;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* p3 = head->next->next;

        while(p3!=nullptr){
          if((p1->val<p2->val&&p2->val>p3->val)||(p1->val>p2->val&&p2->val<p3->val)){
            if(first ==-1){
                first = count;
            }
            if(last !=-1){
            minDistance = min(minDistance , count - last);
            }
            last = count;
          }
          p1 = p2;
          p2 = p3;
          p3 = p3->next;
          count++;   
        }
        if(last == first)return {-1 , -1};
       return {minDistance ,  last - first};
    }
};