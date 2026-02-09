// Last updated: 2/9/2026, 1:27:21 PM
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        // map<int, long long> m;
        // long long ans = 0;
        // for(int i = 0;i<time.size();i++)
        //     m[time[i]%60]++;
        // for(auto it = m.begin(); it != m.end();it++)
        // {
        //     int curr = it->first;
        //     auto it1 = m.find(60 - curr);
        //     if(it1 != m.end() && it != it1)
        //         // cout << it->second << " " << it1->second << endl;
        //         ans += (it->second * it1-> second);
        // }
        // long long sum_60 = (m[0]*(m[0]-1))/2;
        // long long sum_30 = (m[30]*(m[30]-1))/2;
        // return ans/2 + sum_30 + sum_60;
        vector<int> vec(60, 0);
        int cnt = 0;
        for(int i = 0;i<time.size();i++)
        {
            int x = time[i]%60;
            if(x == 0) cnt += vec[0];
            else    cnt += vec[60 - x];
            vec[x]++;
        }
        return cnt;
    }
};