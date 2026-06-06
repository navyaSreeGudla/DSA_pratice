class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        unordered_set<int>st(nums.begin(),nums.end());
        int max_len =1;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int len =1;
                while(st.find(it+len)!=st.end()){
                    len++;
                }
                max_len = max(max_len,len);
            }
        }
    return max_len;
    }
};
