class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string>st;
        for(int i =0;i<n;i++){
            if(tokens[i]!= "+" && tokens[i]!="-"&& tokens[i]!="*"&& tokens[i]!="/"){
                st.push(tokens[i]);
            }
            else{
                int ans = stoi(st.top());
                st.pop();
                int val = stoi(st.top());
                st.pop();
                if(tokens[i]=="+"){
                     ans = ans+val;
                }
                if(tokens[i]=="-"){
                     ans = val-ans;
                    
                }
                if(tokens[i]=="*"){
                     ans = ans * val;     
                }
                if(tokens[i]=="/"){
                    ans = val/ans;                  
                }
                st.push(to_string(ans));
            }
        }
        return stoi(st.top());
    }
};
