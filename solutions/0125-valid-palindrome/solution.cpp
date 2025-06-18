class Solution {
public:
    bool isPalindrome(string s) 
    {
        string str = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')  str += s[i];
            else if(s[i] >= 'A' && s[i] <= 'Z') str += (s[i]+32);
            else if(s[i] >='0' && s[i] <= '9')  str += s[i];
            else    continue;
        }
        cout << str << endl;
        int i=0, j=str.length()-1;
        while(i<j)
        {
            if(str[i] != str[j])
                return false;
            else
            {
                i++;
                j--;
            }
        }   
        return true;    
    }
};
