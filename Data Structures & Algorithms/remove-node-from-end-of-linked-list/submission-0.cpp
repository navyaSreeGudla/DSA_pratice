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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*mover = head;
        int count = 1;
        ListNode*prev = NULL;
        while(mover->next!=NULL){
        count++;
        prev = mover;
        mover = mover->next;
        }
        if(count<n){
            return NULL;
        }
        if(count == n){
            ListNode*temp = head->next;
            head->next = NULL;
            delete(head);
            return temp;
        }
        if(n==1){
           prev->next = NULL;
           delete(mover);
           return head;
        }
        ListNode*prev1 = NULL;
        ListNode*temp = head;
        while(count-n-1>=0){
            prev1=temp;
            temp = temp->next;
            n++;
        }
        ListNode*next1 = temp->next;
        temp->next=NULL;
        prev1->next=NULL;
        delete(temp);
        prev1->next = next1;
        return head;
    }
};
