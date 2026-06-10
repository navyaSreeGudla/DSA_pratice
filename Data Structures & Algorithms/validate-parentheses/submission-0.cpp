class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char>st;
        for(int i = 0;i<n;i++){
            char c = s[i];
            if(!st.empty() && (st.top()== '(') && c ==')'){
                st.pop();
            }
            else if(!st.empty() && (st.top()== '[') && c ==']'){
                st.pop();
            }
            else if(!st.empty() && (st.top()== '{') && c =='}'){
                st.pop();
            }
            else{
             st.push(c);
            }  
        }
        return st.empty();
    }
};
