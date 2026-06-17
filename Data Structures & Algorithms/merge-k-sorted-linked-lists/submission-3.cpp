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
ListNode*divide(vector<ListNode*>&lists,int l,int r){
    if(l>r){
        return NULL;
    }
    if(l==r){
        return lists[l];
    }
    int mid = l+(r-l)/2;
    ListNode*left = divide(lists,l,mid);
    ListNode*right = divide(lists,mid+1,r);
    return merge(left,right);
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
        return divide(lists,0,n-1);
    }
};
