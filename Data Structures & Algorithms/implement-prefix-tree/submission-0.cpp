class Trie{
    public:
    Trie*children[26];
    bool isEnd;
    Trie(){
        isEnd = false;
        for(int i =0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class PrefixTree {
    Trie*root;
public:
    PrefixTree() {
        root = new Trie();
    }
    
    void insert(string word) {
        Trie*node = root;
        for(char c:word){
            int idx = c-'a';
            if(node->children[idx]==NULL){
                node->children[idx]=new Trie();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie*node = root;
        for(char c:word){
            int idx = c-'a';
            if(node->children[idx]==NULL){
                return false;
            }
            node = node->children[idx];
        }
        if(node->isEnd){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie*node = root;
        for(char c:prefix){
            int idx = c-'a';
            if(node->children[idx]==NULL){
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }
};
