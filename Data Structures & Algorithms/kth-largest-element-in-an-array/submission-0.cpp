class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int n = nums.size();
        int ans = -1;
        for(int i =0;i<n;i++){
            pq.push(nums[i]);
        }
        while(!pq.empty() && k>0){
         ans = pq.top();
         pq.pop();
         k--;
        }
        return ans;
    }
};
