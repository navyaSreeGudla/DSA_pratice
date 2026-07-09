class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(int i = 0;i<prerequisites.size();i++){
            indegree[prerequisites[i][1]]++;
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        queue<int>q;
        for(int i =0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(int neigh:adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        return cnt == numCourses;
    }
};
