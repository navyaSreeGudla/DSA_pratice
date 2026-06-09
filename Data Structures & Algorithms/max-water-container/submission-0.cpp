class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;
        int max_area = 0;
        while(l<=r){
            int min_height = min(heights[l],heights[r]);
            int area = min_height*(r-l);
            if(heights[l]<heights[r]){
                l++;
            }
            else{
                r--;
            }
            max_area = max(max_area,area);
        }
        return max_area;
    }
};
