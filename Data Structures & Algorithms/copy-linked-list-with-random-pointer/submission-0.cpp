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
        unordered_map<Node*,Node*>mp;
        mp[NULL]=NULL;
        Node*mover = head;
        while(mover){
            Node*temp = new Node(mover->val);
            mp[mover]=temp;
            mover = mover->next;
        }
        mover = head;
        while(mover){
            Node*copy = mp[mover];
            copy->next = mp[mover->next];
            copy->random = mp[mover->random];
            mover = mover->next;
        }
        return mp[head];
    }
};
