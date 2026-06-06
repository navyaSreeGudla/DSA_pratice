class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        set<int>st;
        int num = INT_MAX;
        for(int i =0;i<n;i++){
            st.insert(nums[i]);
            num = min(num,nums[i]);
        }
        int max_len = 1;
        int count = 1;
        for(auto x:st){
           if(x==num){
            continue;
           }
           else if(x == (num+1)){
            num = num+1;
            count++;
           }
           else{
            num = x;
            count = 1;
           }
           max_len = max(max_len,count);
        }
        return max_len;
    }
};
