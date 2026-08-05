class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i =0;i<n;i++){
            int tank = 0;
            bool possible = true;
            for(int cnt = 0;cnt<n;cnt++){
                int curr  =(i+cnt)%n;
                tank = tank+gas[curr]-cost[curr];
                if(tank<0){
                    possible = false;
                    break;
                }
            }
            if(possible){
                    return i;
                }
        }
        return -1;
    }
};
