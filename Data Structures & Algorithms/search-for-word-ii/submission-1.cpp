class Solution {
public:
    bool dfs(int r,int c,vector<vector<char>>& board,string& word,int i){
        int n = board.size();
        int m = board[0].size();
        if(i == word.size()){
            return true;
        }
        if(r>=n || c>=m || c<0 || r<0 || board[r][c]=='#' || board[r][c]!=word[i]){
            return false;
        }
        board[r][c]='#';
        bool res =  dfs(r+1,c,board,word,i+1)||
               dfs(r,c+1,board,word,i+1)||
               dfs(r-1,c,board,word,i+1)||
               dfs(r,c-1,board,word,i+1);
        board[r][c]= word[i];
        return res;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        vector<string>res;
        for(string &word:words){
            bool flag = false;
            for(int r = 0;r<n&&!flag;r++){
                for(int c = 0;c<m;c++){
                    if(board[r][c]!=word[0]){
                        continue;
                    }
                    if(dfs(r,c,board,word,0)){
                        res.push_back(word);
                        flag = true;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
