class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        int l =0;
        int r = 0;
        int max_len = 0;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
            }
            max_len = max(r-l+1,max_len);
            r++;
        }
        return max_len;
    }
};
