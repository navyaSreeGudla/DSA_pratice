class Solution {
public:
    void solve(int i,vector<int>& nums,vector<int>& res,vector<vector<int>>& ans,int target){
        int n = nums.size();
        if(target ==0){
            sort(res.begin(),res.end());
            ans.push_back(res);
            return;
        }
        if(i==n || target<0){
            return;
        }
        res.push_back(nums[i]);
        solve(i+1,nums,res,ans,target-nums[i]);
        res.pop_back();
        int idx = i;
        while(idx+1<n && nums[idx]==nums[idx+1]){
            idx++;
        }
        solve(idx+1,nums,res,ans,target);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>res;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,res,ans,target);
        return ans;
    }
};
