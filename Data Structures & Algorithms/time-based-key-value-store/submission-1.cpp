class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string,vector<pair<int,string>>>mp;
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto &it = mp[key];
        int l =0;
        int r = it.size()-1;
        string ans = "";
        while(l<=r){
            int m = (l+r)/2;
            if(it[m].first<=timestamp){
                ans = it[m].second;
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
     return ans;
    }
};
