class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n-k+1);
        deque<int>q;
        int l =0;
        int r =0;
        while(r<n){
            while(!q.empty() && nums[q.back()]<nums[r]){
                q.pop_back();
            }
            q.push_back(r);
            if(q.front()<l){
                q.pop_front();
            }
            if(r+1>=k){
                ans[l]=nums[q.front()];
                l++;
            }
            r++;
        }
        return ans;
    }
};
