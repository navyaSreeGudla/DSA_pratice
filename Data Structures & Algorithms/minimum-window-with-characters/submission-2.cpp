class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m>n){
            return "";
        }
        unordered_map<char,int>mp1;
        for(int i =0;i<m;i++){
           mp1[t[i]]++;
        }
        int need = mp1.size();
        int l =0;
        int r =0;
        int start = 0;
        int min_len = INT_MAX;
        unordered_map<char,int>mp2;
        while(r<n){
            mp2[s[r]]++;
            if(mp1.find(s[r])!=mp1.end()){
             if(mp2[s[r]]==mp1[s[r]]){
                need--;
            }
            }
        
            while(need == 0){
    if(min_len > r-l+1){
        min_len = r-l+1;
        start = l;
    }

    char ch = s[l];

    mp2[ch]--;

    if(mp1.find(ch) != mp1.end() &&
       mp2[ch] < mp1[ch]){
        need++;
    }

    if(mp2[ch] == 0){
        mp2.erase(ch);
    }

    l++;
}
            r++;
        }
        if(min_len == INT_MAX){
    return "";
}

return s.substr(start, min_len);
       
    }
};
