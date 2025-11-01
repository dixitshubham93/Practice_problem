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
    void removeNode(ListNode*& prev , ListNode*& root,ListNode*& head){
        if(prev==nullptr){
            head = head->next;
        }else{
            prev->next = root->next;
        }
    }
    
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* prev = nullptr;
        unordered_set<int>s(nums.begin() , nums.end());
        ListNode* root = head;
        while(root!=nullptr){
            if(s.find(root->val)!=s.end()){
                removeNode(prev ,root, head);
                root = root->next;
            }else{
                prev = root;
                root =root->next;
            }  
        }
        return head ;
    }
};