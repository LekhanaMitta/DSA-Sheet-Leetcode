class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        int n = bits.size();
        if(n == 1 && bits[0] == 0)  return true;
        if(n == 1 && bits[0] == 1)  return false;
        int i =0, j=1;
        while(i < j && i < n)
        {
            if(bits[i] == 1 && (bits[j] == 0 || bits[j] == 1))
            {
                i+=2;
                j+=2;
            }
            else if(bits[i] == 0)
            {
                i++;
                j++;
            }
            if(i == n-1)    return true;
            // if(i >= n)  return false;
        }
        return false;
    }
};
