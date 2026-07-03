class Solution {
public:
    void solve(int idx,vector<int>& nums,vector<int>& res,vector<vector<int>>& ans){
        int n = nums.size();
        if(idx == n){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[idx]);
        solve(idx+1,nums,res,ans);
        res.pop_back();
        while(idx+1<nums.size() && nums[idx]==nums[idx+1]){
            idx++;
        }
        solve(idx+1,nums,res,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>res;
        vector<vector<int>>ans;
        solve(0,nums,res,ans);
        return ans;
    }
};
