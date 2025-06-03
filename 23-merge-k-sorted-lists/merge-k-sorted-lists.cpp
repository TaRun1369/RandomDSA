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
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* temp = new ListNode(-1);
        ListNode* nexans = temp;

        ListNode* t1 = left,*t2 = right;

        while(t1 != NULL && t2 != NULL){
            if(t1->val < t2->val){
                temp->next = t1;
                temp = temp->next;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = temp->next;
                t2 = t2->next;
            }
            
        }

        if(t1 != NULL) temp->next = t1;
        if(t2 != NULL) temp->next = t2;

        return nexans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        ListNode* head = lists[0];
        for(int i = 1;i<lists.size();i++){
            head = merge(head,lists[i]);
        }
        return head;
    }
};