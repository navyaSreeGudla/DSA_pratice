class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        int i =1;
        vector<int>v=intervals[0];
        while(i<n){
           if(v[1]>=intervals[i][0]){
             v[0]=min(v[0],intervals[i][0]);
             v[1]=max(v[1],intervals[i][1]);
           }
           else{
               res.push_back(v);
               v = intervals[i];
           }
           i++;
        }
        res.push_back(v);
        return res;
    }
};
