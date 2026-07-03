class Solution {
public:
    bool isPalindrome(string res){
       string k = res;
       reverse(res.begin(),res.end());
       if(k==res){
        return true;
       }
       return false;
    }
    void solve(int i,vector<string>& res,vector<vector<string>>& ans,string s){
        int n = s.size();
       
        if(i==n){
            ans.push_back(res);
            return;
        }
        for(int j = i;j<n;j++){
            string next = s.substr(i,j-i+1);
            if(isPalindrome(next)){
                res.push_back(next);
                solve(j+1,res,ans,s);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>res;
        vector<vector<string>>ans;
        solve(0,res,ans,s);
        return ans;
    }
};
