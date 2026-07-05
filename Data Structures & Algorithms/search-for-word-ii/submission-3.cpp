class Trie{
    public:
    Trie*children[26];
    string s;
    Trie(){
        s = "";
        for(int i =0;i<26;i++){
            children[i]=NULL;
        }
    }
    void insert(const string &s){
        Trie*root = this;
        for(int i =0;i<s.size();i++){
            if(root->children[s[i]-'a']==NULL){
                root->children[s[i]-'a']=new Trie();
            }
            root = root->children[s[i]-'a'];
        }
        root->s = s;
    }
};
class Solution {
public:  
    void dfs(int r,int c,Trie*root,vector<vector<char>>& board,vector<string>& res){
        if(r>=board.size() || r<0||c<0||c>=board[0].size() || board[r][c]=='#'||root->children[board[r][c]-'a']==NULL){
            return;
        }
        char ch = board[r][c];
        root = root->children[ch-'a'];
        board[r][c]='#';
         if(root->s!=""){
          res.push_back(root->s);
          root->s="";
          }
        dfs(r+1,c,root,board,res);
        dfs(r-1,c,root,board,res);
        dfs(r,c+1,root,board,res);
        dfs(r,c-1,root,board,res);
        board[r][c]=ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie*root= new Trie();
        vector<string>res;
        for(string word:words){
            root->insert(word);
        }
        for(int r = 0;r<board.size();r++){
            for(int c = 0;c<board[0].size();c++){
               dfs(r,c,root,board,res);
            }
        }
        return res;
    }
};
