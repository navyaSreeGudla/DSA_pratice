class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        sort(s1.begin(),s1.end());//o(n1logn1)
        if(n1>n2){
            return false;
        }
        int l = 0;
        int r = n1-1;
        while(r<n2){//o(n2)
            string k = s2.substr(l,r-l+1);
            sort(k.begin(),k.end());//o(n1logn1)
            if(s1==k){
                return true;
            }
            l++;
            r++;
        }
        return false;
    }
};
//o(n1n2logn1)