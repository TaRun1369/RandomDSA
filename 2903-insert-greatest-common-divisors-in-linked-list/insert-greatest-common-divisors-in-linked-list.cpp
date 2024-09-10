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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL){
            int v1 = temp->val;
            int v2 = temp->next->val;
            int gcd = __gcd(v1,v2);
            ListNode* nn = new ListNode(gcd);
            nn->next = temp->next;
            temp->next = nn;
            temp = temp->next->next;
        }

        return head;
    }
};