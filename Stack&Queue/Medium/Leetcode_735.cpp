class Solution {
public:
    /*
    1. Focus on the asteroids whether they will be alive or dead after the operations are done as mentioned. Initially consider all the asteroids are alive.
    2.  Operations are only done when the top asteroid is in positive direction and curr asteroid is in negative direction.
    3. With magnitude of both the top and current asteroids make operations and decide whether the current asteroid is alive or dead.*/
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
