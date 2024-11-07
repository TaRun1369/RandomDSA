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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        if(list1->val > list2->val) return mergeTwoLists(list2,list1);

        ListNode* l1 = list1,*l2 = list2,*ans = new ListNode(0);
        ListNode* tans = ans;
        while(l1 != NULL && l2 != NULL){
            if(l1->val > l2->val){
                tans->next = l2;
                tans = tans ->next;
                l2=l2->next;
                tans->next = NULL;

            }
            else{
                tans->next = l1;
                tans = tans->next;
                l1 = l1->next;
                tans->next = NULL;
            }
        }
        if(l1 != NULL) tans->next = l1;
        if(l2 != NULL) tans->next = l2;


        return ans->next;

    }
};