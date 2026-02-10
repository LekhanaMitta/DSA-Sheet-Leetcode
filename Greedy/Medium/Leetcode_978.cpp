class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) 
    {
        int n = arr.size(), maxLen = 0, len = 0, curr = 0;
        if(n == 1)  return 1;
        curr = (arr[0] == arr[1]) ? 0 : (arr[0] > arr[1] ? -1 : 1);
        if(curr != 0)   
            len = 1;
        for(int i=2;i<n;i++)
        {
            int prev = curr;
            curr = (arr[i-1] == arr[i]) ? 0 : (arr[i-1] > arr[i] ? -1 : 1);
            if(prev + curr == 0 && prev != 0)
            {
                len++;
                maxLen = max(len, maxLen);
            }
            else if(curr == 0 && prev == 0)
                len = 0;
            else
                len = 1;
        }  
        return max(len,maxLen)+1;  
    }
};
