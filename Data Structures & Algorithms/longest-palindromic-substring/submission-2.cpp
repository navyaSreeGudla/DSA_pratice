class Solution {
public:
    bool isPalindrome(string word){
        int l = 0;
        int r = word.size()-1;
        while(l<=r){
            if(word[l]!=word[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    string solve(int l,int r,string &s, unordered_map<string,string>&dp){
        if(l>r){
            return "";
        }
      string k = s.substr(l,r-l+1);
      if(isPalindrome(k)){
        return k;
      }
      if(dp.find(k)!=dp.end()){
        return dp[k];
      }
      string left = solve(l+1,r,s,dp);
      string right = solve(l,r-1,s,dp);
      if(left.size()>right.size()){
        return dp[k]=left;
      }
      return dp[k]=right;
    }
    string longestPalindrome(string s) {
      int n = s.size();
      int l =0;
      int r = n-1;  
      unordered_map<string,string>dp;
      return solve(0,n-1,s,dp);
    }
};
