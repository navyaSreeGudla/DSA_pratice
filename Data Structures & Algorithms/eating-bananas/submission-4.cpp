class Solution {
public:
    bool isenough(int rate,vector<int>& piles, int h){
        int totalTime =0;
        for (int p : piles) {
                totalTime += (p + rate - 1) / rate;
            }
        return h>=totalTime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       int n = piles.size();
       int low = 1;
       int high = *max_element(piles.begin(), piles.end());

        int ans = high;
       
       while(low<=high){
        int mid = (high -low)/2 + low;
        if(isenough(mid,piles,h)){
            ans = min(mid,ans);
            high = mid-1;
        }
        else {
            low = mid+1;
        }
       }
       return ans;
    }
};
