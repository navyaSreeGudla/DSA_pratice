class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l =0;
        int r =0;
        vector<int>freq(26);
        int maxfreq = 0;
        int ans = 0;
        while(r<n){
            freq[s[r]-'A']++;
            maxfreq = max(maxfreq,freq[s[r]-'A']);
            while((r-l+1)-maxfreq>k){
                freq[s[l]-'A']--;
                l++;
            }
        ans = max(ans,r-l+1);
        r++;
        }
        return ans;
    }
};
