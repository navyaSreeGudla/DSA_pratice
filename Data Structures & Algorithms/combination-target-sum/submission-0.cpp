class Solution {
public:
    void solve(int i,vector<int>& res,vector<int>& nums,vector<vector<int>>& ans,int target){
        int n = nums.size();
        if(target==0){
            ans.push_back(res);
            return;
        }
        if(i==n || target<0){
            return;
        }
        res.push_back(nums[i]);
        solve(i,res,nums,ans,target-nums[i]);
        res.pop_back();
        solve(i+1,res,nums,ans,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       int n = nums.size();
       vector<int>res;
       vector<vector<int>>ans;

       solve(0,res,nums,ans,target);
       return ans;
    }
};
