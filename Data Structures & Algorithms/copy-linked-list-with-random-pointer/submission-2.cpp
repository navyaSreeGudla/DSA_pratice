/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        Node*mover = head;
        while(mover!=NULL){
            Node*next = mover->next;
            Node*temp = new Node(mover->val);
            mover->next = temp;
            temp->next = next;
            mover = next;
        }
        Node*mov = head;
        while(mov){
           if(mov->random){
            mov->next->random = mov->random->next ;
           } 
           mov = mov->next->next;
        }
        Node*dummy = new Node(-1);
        Node*newhead = dummy;
        mover = head;
        while(mover){
            Node*temp = mover->next;
            mover->next = temp->next;
            newhead->next = temp;
            newhead = temp;
            mover = mover->next;
        }
        return dummy->next;
    }
};
