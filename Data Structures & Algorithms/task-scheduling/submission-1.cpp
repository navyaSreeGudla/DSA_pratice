class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        int maxFreq= 0;
        vector<int>freq(26,0);
        for(int i = 0;i<m;i++){
            freq[tasks[i]-'A']++;
        }
        for(int i=0;i<26;i++){
           maxFreq = max(maxFreq,freq[i]);
        }
        int countMax =0;
        for(int i =0;i<26;i++){
            if(freq[i]==maxFreq){
                countMax++;
            }
        }
        return max((int)tasks.size(),(maxFreq-1)*(n+1)+countMax);
    }
};
