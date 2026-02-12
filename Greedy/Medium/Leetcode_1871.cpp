class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        int n = s.length();
        vector<bool> reach(n);
        reach[0] = true;
        // for(int i=minJump;i<s.length();i++)
        // {
        //     int first = i-minJump;
        //     int second = max(0, i-maxJump);
        //     if(s[i] == '1') reach[i] = false;
        //     else
        //     {
        //         for(int j=second;j<=first;j++)
        //             reach[i] = reach[i] || reach[j];
        //     }
        //     cout << i << " " << reach[i] << endl;
        // }   
        int window = 0;
        for(int i=1;i<s.length();i++)
        {
            if(i-minJump >= 0)
                window += reach[i-minJump];
            if(i-maxJump-1 >= 0)
                window -= reach[i-maxJump-1];
            if(s[i] == '0' && window > 0)   reach[i] = true;
        } 
        return reach[n-1];
    }
};
