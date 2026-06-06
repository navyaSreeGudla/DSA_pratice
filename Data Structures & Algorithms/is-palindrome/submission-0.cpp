class Solution {
public:
    bool isPalindrome(string s) {
       string ans = "";
       stringstream ss(s);
       string token;
       while(ss>>token){
        ans = ans+token;
       }
       string result = "";
       for(char c : ans){
        if(isalnum(c)){
        result += c;
        }
}
       transform(result.begin(), result.end(), result.begin(), ::tolower);
       string rev = result;
       reverse(rev.begin(),rev.end());
       if(rev == result){
        return true;
       }
       return false;
    }

};
