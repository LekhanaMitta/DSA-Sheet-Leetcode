// Last updated: 2/9/2026, 1:26:51 PM
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        int cost = 0, i=0;
        while(i < colors.size())
        {
            char curr = colors[i];
            int mx = 0;
            while(colors[i] == curr && i < colors.size())
            {
                cost += neededTime[i];
                cout << cost << " ";
                mx = max(mx, neededTime[i]);
                i++;
            }
            cost -= mx;
            cout << cost << " ";
        } 
        return cost;   
    }
};