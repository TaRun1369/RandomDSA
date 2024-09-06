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
    // void deletenode(ListNode* temp){
        
    // }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s (nums.begin(),nums.end());
        ListNode* temp = head;
        while(s.find(head->val) != s.end()){
            head = head->next;
        }
        while(temp != NULL && temp->next != NULL){
            if(s.find(temp->next->val) != s.end()){
                // deletenode(temp);
                temp->next = temp->next->next;
            }
            else 
            temp = temp->next;
        }

        return head;
    }
};