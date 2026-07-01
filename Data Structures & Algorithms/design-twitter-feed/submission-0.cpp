class Twitter {
public:
    int count;
    unordered_map<int,vector<pair<int,int>>>tweetMap;
    unordered_map<int,unordered_set<int>>followerMap;
    struct Node{
        int time;
        int tweetId;
        int userId;
        int index;
    };
    struct compare{
        bool operator()(Node &a,Node &b){
            return a.time>b.time;
        }
    };
    Twitter() {
        count=0; 
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count,tweetId});
        count--;
        if(tweetMap[userId].size()>10){
            tweetMap[userId].erase(tweetMap[userId].begin());
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Node,vector<Node>,compare>pq;
        followerMap[userId].insert(userId);
        for(int followeeId:followerMap[userId]){
            if(tweetMap[followeeId].empty()){
                continue;
            }
            int idx = tweetMap[followeeId].size()-1;
            pq.push({
                tweetMap[followeeId][idx].first,
                tweetMap[followeeId][idx].second,
                followeeId,
                idx
            });      
        }
        vector<int>ans;
        while(!pq.empty() && (int)ans.size()<10){
            Node curr = pq.top();
            pq.pop();
            int user = curr.userId;
            ans.push_back(curr.tweetId);
            if(curr.index>0){
                int idx = curr.index-1;
                pq.push({
                    tweetMap[user][idx].first,
                    tweetMap[user][idx].second,
                    user,
                    idx
                });
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followerMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerMap[followerId].find(followeeId)!=followerMap[followerId].end()){
            followerMap[followerId].erase(followeeId);
        }
    }
};
