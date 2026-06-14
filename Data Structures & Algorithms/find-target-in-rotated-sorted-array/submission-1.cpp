class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n = nums.size();
       int l =0;
       int h = n-1;
       while(l<=h){
        int m = (h-l)/2+l;
        if(nums[m]==target){
            return m;
        }
        if(nums[l]<=nums[m]){
            if(nums[l]<=target && nums[m]>=target){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        else{
            if(nums[m]<target && target<=nums[h]){
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
       } 
       return -1;
    }
};
