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
        if(k == 0 || head == NULL) return head;
        int siz = 0;
        ListNode* temp = head,*end = head;
        while(temp != NULL) {
            siz++;
            end = temp;
            temp = temp->next;
        }
        k%=siz;
        if(k == 0) return head;
        temp = head;
        int kadam = siz - k;
        ListNode* prev;
        while(kadam-- && temp != NULL){
            cout<<temp->val<<endl;
            prev = temp;
            temp = temp->next;

        }
        end->next = head;
        prev->next = NULL;
        return temp;
    }
};