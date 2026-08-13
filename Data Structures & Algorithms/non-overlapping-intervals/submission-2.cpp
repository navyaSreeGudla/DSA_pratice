class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        int cnt = 0;
        vector<int> v = intervals[0];

        for(int i = 1; i < n; i++) {
            if(v[1] > intervals[i][0]) {
                cnt++;
                if(intervals[i][1] < v[1])
                    v = intervals[i];
            }
            else {
                v = intervals[i];
            }
        }

        return cnt;
    }
};