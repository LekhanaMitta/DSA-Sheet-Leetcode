class Solution {
public:
    vector<string> ans;
    map<char, vector<char>> m;
    void letters(string letter, string digits, int idx)
    {
        if(idx == digits.size())
        {
            ans.push_back(letter);
            return;
        }
        vector<char> numpad = m[digits[idx]];
        for(int j=0;j<numpad.size();j++)
            letters(letter+numpad[j], digits, idx+1);
    }
    vector<string> letterCombinations(string digits) 
    {
        m['2'] = {'a', 'b', 'c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};
        letters("", digits, 0);    
        return ans;
    }
};
