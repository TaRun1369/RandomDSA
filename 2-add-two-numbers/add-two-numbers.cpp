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

    // 2-4-3
    // dum - null node pe
    // curr - 2
    // nex - 2->next
    ListNode* reverse(ListNode* node){
        ListNode* dum = NULL;

        ListNode* curr = node;

        while(curr != NULL){
            ListNode* nex = curr->next;
            curr->next = dum;
            dum = curr;
            curr = nex;
        }
        return dum;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverse(l1);
        // l2 = reverse(l2);

        // ListNode* temp = l1;
        // while(temp != NULL){
        //     cout<<temp->val;
        //     temp = temp->next;
        // }
        // return l2;

        ListNode* temp1 = l1,*temp2 = l2,*temp;
        ListNode* nn = new ListNode(0);
        temp = nn;
        int carry = 0;
        while(temp1 != NULL && temp2 != NULL){
            int sum = temp1->val + temp2->val + carry;
            carry = sum /10;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1 != NULL){
            int sum = temp1->val + carry;
            carry = sum /10;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            int sum = temp2->val + carry;
            carry = sum /10;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            temp2 = temp2->next;
        }
        if(carry != 0) temp->next = new ListNode(carry);
        

        return nn->next;
    }
};