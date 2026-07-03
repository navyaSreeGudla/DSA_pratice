class Solution {
public:
    void solve(string &res,int open,int close,vector<string>&ans,int n){
        if(open == n && close==n){
           ans.push_back(res);
           return;
        }
        if(open<n){
            res = res+'(';
            open++;
            solve(res,open,close,ans,n);
            open--;
            res.pop_back();
        }
        if(open>close){
            res = res +')';
            close++;
            solve(res,open,close,ans,n);
            close--;
            res.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        solve(s,0,0,ans,n);
        return ans;
    }
};
