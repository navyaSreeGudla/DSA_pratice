class Solution {
public:
    bool check(int r,int c,vector<string>res){
        int n = res[0].size();
        //check row  && col
        for(int i =0;i<n;i++){
            if(res[r][i]=='Q' || res[i][c]=='Q'){
                return false;
            }
        }
        for(int i  = 0;i<n;i++){
            if(r+i<n && c+i<n){
              if(res[r+i][c+i]=='Q'){
                return false;
              }
            }
            if(r-i>=0 && c-i>=0){
                if(res[r-i][c-i]=='Q'){
                    return false;
                }
            }
            if(r-i>=0 && c+i<n){
                if(res[r-i][c+i]=='Q'){
                    return false;
                }
            }
            if(r+i<n && c-i>=0){
                if(res[r+i][c-i]=='Q'){
                    return false;
                }
            }
        }
        return true;
    }
    void solve(int i,vector<string>& res,vector<vector<string>>& ans){
        int n = res[0].size();
        if(i == n){
            ans.push_back(res);
            return;
        }
        for(int k = 0;k<n;k++){
           if(check(i,k,res)){
            res[i][k]='Q';
            solve(i+1,res,ans);
            res[i][k]='.';
           }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> res(n, string(n, '.'));
        
    solve(0,res,ans);
    return ans;
    }
};
