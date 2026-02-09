// Last updated: 2/9/2026, 1:27:25 PM
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        set<int> day(days.begin(), days.end());
        int last_day = days[days.size()-1];
        vector<int> dp(last_day+1, 0);
        dp[0] = 0;
        for(int i=1;i<=last_day;i++)
        {
            if(day.find(i) == day.end())
                dp[i] = dp[i-1];
            else
                dp[i] = min({dp[i-1]+costs[0], dp[max(0, i-7)]+costs[1], dp[max(0, i-30)]+costs[2]});
        }    
        return dp[last_day];
    }
};