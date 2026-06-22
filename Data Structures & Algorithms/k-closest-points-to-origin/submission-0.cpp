class Solution {
public:
    struct compare{
        bool operator()(vector<int>a,vector<int>b){
            int x = a[0]*a[0]+a[1]*a[1];
            int y = b[0]*b[0]+b[1]*b[1];
            return x>y;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<vector<int>,vector<vector<int>>,compare>pq;
        for(int i =0;i<n;i++){
            pq.push(points[i]);
        }
        vector<vector<int>>ans;
        while(!pq.empty() && k>0){
            ans.push_back(pq.top());
            pq.pop();
            k--;
        }
        return ans;
    }
};
