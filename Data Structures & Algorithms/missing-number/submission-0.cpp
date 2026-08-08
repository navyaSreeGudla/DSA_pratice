class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int k =0;
        while(k<=n){
            auto it = find(nums.begin(), nums.end(), k);
            if(it==nums.end()){
                return k;
            }
            k++;
        }
        return -1;
    }
};
