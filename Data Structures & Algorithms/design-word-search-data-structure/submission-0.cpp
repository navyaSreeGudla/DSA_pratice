class trie{
    public:
    trie*children[26];
    bool isEnd;
    trie(){
        isEnd = false;
        for(int i = 0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class WordDictionary {
public:
    trie*root;
    WordDictionary() {
        root = new trie();
    }
    
    void addWord(string word) {
        trie*node = root;
        for(char c:word){
            int idx = c-'a';
            if(node->children[idx]==NULL){
                node->children[idx] = new trie();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    bool dfs(int pos, string &word,trie*node){
        if(node == NULL){
            return false;
        }
       if(pos == word.size()){
        return node->isEnd;
       }
       char c = word[pos];
       if(c!='.'){
        int idx = c-'a';
        return dfs(pos+1,word,node->children[idx]);
       }
       else{
          for(int i =0;i<26;i++){
            if(dfs(pos+1,word,node->children[i])){
                return true;
            }
          }
       }
       return false;
    }
    bool search(string word) {
        return dfs(0,word,root);
    }
};
