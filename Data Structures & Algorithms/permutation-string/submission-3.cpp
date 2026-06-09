class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        unordered_map<char,int>mp1;
        for(int i =0;i<s1.size();i++){
            mp1[s1[i]]++;
        }
        int need = mp1.size();
        for(int i = 0;i<s2.size();i++){
            unordered_map<char,int>mp2;
            int curr =0;
            for(int j = i;j<s2.size();j++){
                char c = s2[j];
                mp2[c]++;
                if(mp1[c]<mp2[c]){
                    break;
                }
                if(mp1[c]==mp2[c]){
                    curr++;
                }
                if(curr==need){
                    return true;
                }
            }
        }
        return false;
    }
};
