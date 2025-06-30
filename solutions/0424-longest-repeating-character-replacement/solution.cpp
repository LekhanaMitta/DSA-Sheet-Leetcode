class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int i = 0, j = 0;
        int mx = 0, ans = 0;
        vector<int> freq(26,0);
        while(j < s.length())
        {
            freq[s[j] - 'A']++;
            mx = max(mx, freq[s[j]-'A']);
            while((j - i + 1) - mx > k)
            {
                freq[s[i]-'A']--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
