class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        vector<int> ans; 
        for(int a : asteroids)
        {
            bool alive = true;
            while(alive && !ans.empty() && ans.back() > 0 && a < 0)
            {
                int top = ans.back();
                if(top + a < 0)
                {
                    ans.pop_back();
                }
                else if(top + a == 0)
                {
                    ans.pop_back();
                    alive = false;
                }
                else
                    alive = false;
            }
            if(alive)
                ans.push_back(a);
        } 
        return ans;  
    }
};
