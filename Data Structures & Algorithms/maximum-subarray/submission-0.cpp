class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int n = nums.size();
     int maxSum = nums[0];
     int curr = 0;
     for(int num: nums){
        if(curr<0){
            curr = 0;
        }
        curr = curr+num;
        maxSum = max(curr,maxSum);
     }
     return maxSum;
    }
};
