class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        map<char, char> m;
        for(int i=0;i<26;i++)
            m[order[i]] = ('a' + i);
        for(int i=0;i<words.size();i++)
        {
            int j = 0;
            while(j < words[i].size())
            {
                words[i][j] = m[words[i][j]];
                j++;
            }
        } 
        return is_sorted(words.begin(), words.end());   
    }
};
