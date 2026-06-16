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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*dummy = new ListNode(-1);
        ListNode*newhead = dummy;
        int carry =0;
        while(l1!=NULL || l2!=NULL){
            int sum = 0;
            if(l1){
                sum = sum+l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum = sum+l2->val;
                l2 = l2->next;
            }
            if(carry){
                sum = sum+carry;
            }
            ListNode*temp = new ListNode(sum%10);
            carry = sum/10;
            newhead->next = temp;
            newhead = temp;
        }
        if(carry!=0){
            newhead->next = new ListNode(carry);
        }
       return dummy->next;
    }
};
