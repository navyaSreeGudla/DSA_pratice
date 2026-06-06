class Solution {
public:
    bool isPalindrome(string s) {
       string result = "";
       for(char c : s){
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
