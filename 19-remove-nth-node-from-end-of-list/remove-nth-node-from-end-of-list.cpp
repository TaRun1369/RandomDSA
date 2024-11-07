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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = NULL, *temp = head,*nex;

        while(temp != NULL){
            nex = temp->next;
            temp->next = dummy;
            dummy = temp;
            temp = nex;
        }
        return dummy;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         head = reverseList(head);
        if(n == 1) head = head->next;
        else{
            ListNode* temp = head;
            for(int i = 2;i<n;i++){
                temp = temp->next;
            }
            if(temp->next != NULL)
            temp->next = temp->next->next;
        }
         head = reverseList(head);
         return head;



    }
};