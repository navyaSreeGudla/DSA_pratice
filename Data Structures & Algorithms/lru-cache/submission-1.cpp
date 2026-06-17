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
    Node*prv = node->prev;
    Node*nxt = node->next;
    prv->next = nxt;
    nxt->prev = prv;
}
void insert(Node*node){
    Node*prv = right->prev;
    prv->next = node;
    node->prev = prv;
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
            Node*temp = cache[key];
            remove(temp);
            insert(temp);
            return temp->val;
        }
        return -1;
    } 
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            remove(cache[key]);
        }
        Node*temp = new Node(key,value);
        cache[key]=temp;
        insert(temp);
        if(cache.size()>cap){
            Node*p = left->next;
            remove(p);
            cache.erase(p->key);
            delete p;
        }
    }
};
