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
    ListNode*getKth(int k,ListNode*a){
        if(a==NULL){
            return a;
        }
        ListNode*curr = a;
        while(curr && k>0){
           curr = curr->next;
           k--;
        }
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next ==NULL){
            return head;
        }
        ListNode*dummy = new ListNode(0,head);
        ListNode*groupPrev = dummy;
        while(true){
            ListNode*kth = getKth(k,groupPrev);
            if(!kth){
                break;
            }
            ListNode*groupNext = kth->next;
            ListNode*prev = kth->next;
            ListNode*curr=groupPrev->next;
            while(curr!=groupNext){
                ListNode*temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode*nxt = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = nxt;
        }
        return dummy->next;
    }
};
