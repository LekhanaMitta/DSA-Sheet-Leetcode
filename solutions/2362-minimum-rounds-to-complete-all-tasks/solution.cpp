class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        map<int,int> m;
        // int mx = INT_MIN, cnt =0;
        // for(int i=0;i<tasks.size();i++)
        //     m[tasks[i]]++;
        // for(auto it : m)
        //     mx = max(mx, it.second);
        // if(mx == 1) return -1;
        // vector<int> dp(mx+1,0);
        // dp[1] = 1, dp[2] = 1;
        // for(int i=3;i<=mx;i++)
        //     dp[i] = min(dp[i-2],dp[i-3])+1;
        // for(auto it : m)
        // {
        //     if(it.second == 1)  return -1;
        //     else    cnt += dp[it.second];
        // }
        // return cnt;

        int cnt = 0;
        for(int i=0;i<tasks.size();i++)
            m[tasks[i]]++;
        for(auto it : m)
        {
            int c = it.second;
            if(c == 1)  return -1;
            else
            {
                cnt += c/3;
                if(c % 3 == 1 || c % 3 == 2)    cnt++;
            }
        }
        return cnt;
    }
};
