class Solution {
public:
    void solve(int i,vector<int>& nums,vector<int>& res,vector<vector<int>>& ans){
        int n = nums.size();
        if(i==n){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[i]);
        solve(i+1,nums,res,ans);
        res.pop_back();
        solve(i+1,nums,res,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>res;
        vector<vector<int>>ans;
        solve(0,nums,res,ans);
        return ans;
    }
};
