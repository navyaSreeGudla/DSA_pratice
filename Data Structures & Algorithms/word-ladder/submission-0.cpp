class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end() || beginWord == endWord) return 0;
        int res = 0;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            res++;
            int len = q.size();
            for(int i =0;i<len;i++){
                string curr = q.front();
                q.pop();
                if(curr == endWord){
                    return res;
                }
                for(int j = 0;j<curr.size();j++){
                    char temp = curr[j];
                    for(char ch= 'a';ch<='z';ch++){
                        curr[j]=ch;
                        if(ch==temp){
                            continue;
                        }
                        if(st.find(curr)!=st.end()){
                            q.push(curr);
                            st.erase(curr);
                        }
                    }
                    curr[j]=temp;
                }
            }
        }
        return 0;
    }
};
