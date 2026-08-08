class Solution {
public:
    vector<int> partitionLabels(string s) {
       int n = s.size();
       unordered_map<int,int>lastIdx;
       for(int i =0;i<n;i++){
        lastIdx[s[i]]=i;
       } 
       int size =0;int end = 0;
       vector<int>res;
       for(int i =0;i<n;i++){
        size++;
        end = max(end,lastIdx[s[i]]);
        if(i == end){
            res.push_back(size);
            size = 0;
        }
       }
       return res;
    }
};
