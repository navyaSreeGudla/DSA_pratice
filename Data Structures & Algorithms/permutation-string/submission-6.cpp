class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2){
            return false;
        }
        unordered_map<char,int>mp1;
        for(int i =0;i<n1;i++){
            mp1[s1[i]]++;
        }
        int l =0;
        int r = n1-1;
        unordered_map<char,int>mp2;//window freq
        for(int i = l;i<=r;i++){
            mp2[s2[i]]++;
        }

        while(r<n2-1){
            if(mp2==mp1){
                return true;
            }
            mp2[s2[l]]--;
            if(mp2[s2[l]]==0){
                mp2.erase(s2[l]);
            }
            l++;
            r++;
            mp2[s2[r]]++;
        }
        return mp2==mp1;
    }
};
