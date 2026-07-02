class MedianFinder {
public:
    MedianFinder() { 
    }
    priority_queue<int>maxHeap;// lower half
    priority_queue<int,vector<int>,greater<int>>minHeap;//higher half
    void addNum(int num) {
       if(maxHeap.empty() || num<=maxHeap.top()){
        maxHeap.push(num);
       }
       else{
        minHeap.push(num);
       }
        while(maxHeap.size()>minHeap.size()+1){
            int val = maxHeap.top();
            minHeap.push(val);
            maxHeap.pop();
        }
        while(maxHeap.size()<minHeap.size()){
            int val = minHeap.top();
            maxHeap.push(val);
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size()<maxHeap.size()){
            return (double)maxHeap.top();
        }
        return ((double)minHeap.top()+(double)maxHeap.top())/2.0;
    }
};
