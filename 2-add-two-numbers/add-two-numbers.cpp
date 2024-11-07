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
    ListNode* reverse(ListNode* head) {
        ListNode* dummy = NULL, *temp = head,*nex;

        while(temp != NULL){
            nex = temp->next;
            temp->next = dummy;
            dummy = temp;
            temp = nex;
        }
        return dummy;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return (l2);
        if(l2 == NULL) return (l1);
        int sum = 0,carry = 0;
        ListNode* ans = NULL,*temp = NULL;
        while(l1 != NULL && l2 != NULL){
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            ListNode* nn = new ListNode(sum % 10);
            if(ans == NULL){
                ans = nn;
                temp = ans;
            }
            else{
                temp->next = nn;
                temp = temp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1 != NULL){
            while(carry != 0 && l1 != NULL ){
                    sum = l1->val  + carry;
                    carry = sum / 10;
                    ListNode* nn = new ListNode(sum % 10);
                    temp->next = nn;
                    temp = temp->next;
                    l1 = l1->next;
            } 
            if(l1 != NULL) temp->next = l1;
        }

        if(l2 != NULL){
            while(carry != 0 && l2 != NULL ){
                    sum = l2->val  + carry;
                    carry = sum / 10;
                    ListNode* nn = new ListNode(sum % 10);
                    temp->next = nn;
                    temp = temp->next;
                    l2 = l2->next;
            }
            if(l2 != NULL) temp ->next = l2;
        } 
        if(carry > 0){
            ListNode* nn = new ListNode(carry);
            temp->next = nn;
        }
        return (ans);
    }
};