class Solution {
public:
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
    void solve(int i,string &res,vector<string>& ans,string digits){
        int n = digits.size();
        if(i==n){
            ans.push_back(res);
            return;
        }
        int idx = digits[i]-'0';
        string curr = digitToChar[idx];
        for(int j =0;j<curr.size();j++){
            res.push_back(curr[j]);
            solve(i+1,res,ans,digits);
            res.pop_back();
        }
    }                            
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0){
            return {};
        }
        vector<string>ans;
        string res;
        solve(0,res,ans,digits);
        return ans;
    }
};
