class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        int n = hand.size();
        if(n % groupSize != 0)  return false;
        map<int, int> m;
        for(int i=0;i<n;i++)
            m[hand[i]]++;
        while(!m.empty())
        {
            int small = m.begin() -> first;
            for(int j=small;j<small+groupSize;j++)
            {
                auto it = m.find(j);
                if(it != m.end())
                {
                    if(--(it->second) == 0)  
                        m.erase(it);
                }
                else
                    return false;
            }
        }
        return true;
    }
};
