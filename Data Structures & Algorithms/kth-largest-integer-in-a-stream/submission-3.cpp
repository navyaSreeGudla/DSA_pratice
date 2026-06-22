class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        this->kth = k;
        int cap = kth;
        for(int i =0;i<nums.size();i++){
            pq.push(nums[i]);
            }
        while(pq.size()>cap){
            pq.pop();
        }
    }
    
    int add(int val) {
        int cap = kth;
        if(pq.size()<cap-1){
            return -1;
        }
        if(pq.size()==cap-1){
            pq.push(val);
            return pq.top();
        }
        pq.push(val);
        pq.pop();
        return pq.top();
    }
};
