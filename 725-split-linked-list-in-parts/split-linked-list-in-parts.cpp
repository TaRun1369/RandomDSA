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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int c = 0;
        ListNode* temp = head;
        while(temp != NULL){
            c++;
            temp = temp->next;
        }
        int rem = c % k;
        int div = c / k;
        temp = head;

        while(temp != NULL){
            ListNode* nn = temp;
            ListNode* prev = temp;
            for(int i = 0;i<div && temp != NULL;i++){
                prev = temp;
                temp = temp->next;
            }
            if(rem > 0 && temp != NULL){
                prev = temp;
                temp = temp->next;
                rem--;
            }
            prev -> next = NULL;
            ans.push_back(nn);
        }

        // if(ans.size() < k){
            while(ans.size() < k){
                ListNode* nn;
                ans.push_back(nn);
            }
        // }
        return ans;
    }
};