class Solution {
public:
    int solve(int i,string &s,unordered_map<int,int>& dp){
        if(i == s.size()){
            return dp[i]=1;
        }
        if(s[i]=='0'){
            return dp[i]=0;
        }
        if(dp.find(i)!=dp.end()){
            return dp[i];
        }
        int ways = solve(i+1,s,dp);
        if(i+1<s.size()){
            int num = (s[i]-'0')*10+(s[i+1]-'0');
            if(num>=10 && num<=26){
                ways+=solve(i+2,s,dp);
            }
        }
        return dp[i]=ways;
    }
    int numDecodings(string s) {
        unordered_map<int,int>dp;
        return solve(0,s,dp);
    }
};
