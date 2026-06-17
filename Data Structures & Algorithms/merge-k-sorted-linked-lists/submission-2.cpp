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
private:
ListNode*merge(ListNode*a,ListNode*b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    ListNode*mover1 = a;
    ListNode*mover2 = b;
    ListNode*dummy = new ListNode(-1);
    ListNode*head = dummy;
    while(mover1 && mover2){
        if(mover1->val>mover2->val){
            ListNode*nxt = mover2->next;
            mover2->next = NULL;
            head->next = mover2;
            head = mover2;
            mover2=nxt;
        }
        else{
            ListNode*nxt = mover1->next;
            mover1->next = NULL;
            head->next = mover1;
            head = mover1;
            mover1 = nxt;
        }
    }
    while(mover1){
        ListNode*nxt = mover1->next;
            mover1->next = NULL;
            head->next = mover1;
            head = mover1;
            mover1 = nxt;
        
    }
    while(mover2){
         ListNode*nxt = mover2->next;
            mover2->next = NULL;
            head->next = mover2;
            head = mover2;
            mover2=nxt;
    }
    return dummy->next;
}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0){
            return NULL;
        }
        if(n==1){
            return lists[0];
        }
        ListNode*head = lists[0];
        for(int i=1;i<n;i++){
            ListNode*temp = lists[i];
            head = merge(head,temp);
        }
        return head;
    }
};
