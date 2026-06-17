class Node{
public:
    int key;
    int val;
    Node*prev;
    Node*next;

    Node(int k,int v):key(k),val(v),prev(NULL),next(NULL){}
};
class LRUCache {
private:
   int cap;
   unordered_map<int,Node*>cache;
   Node*left;
   Node*right;
   void remove(Node*node){
    Node*prev = node->prev;
    Node*nxt = node->next;
    prev->next = nxt;
    nxt->prev = prev;
   }
   void insert(Node*node){
      Node*prev = right->prev;
      node->prev = prev;
      prev->next = node;
      node->next = right;
      right->prev = node;
   }
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node*node= cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            Node*temp = cache[key];
            remove(temp);
        }
        Node*newNode = new Node(key,value);
        cache[key]=newNode;
        insert(newNode);
        if(cache.size()>cap){
            Node*head = left->next;
            remove(head);
            cache.erase(head->key);
            delete head;
        }
    }
};
