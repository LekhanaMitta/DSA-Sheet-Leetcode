class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int idx = 0, curr_cost = 0, min_cost = INT_MAX;
        int n = gas.size();
        for(int i=0;i<n;i++)
        {
            curr_cost += gas[i] - cost[i];
            if(min_cost > curr_cost)
            {
                min_cost = min(min_cost, curr_cost);
                idx = i;
            }
        }
        if(curr_cost < 0)   return -1;
        return (idx+1)%n;
    }
};
