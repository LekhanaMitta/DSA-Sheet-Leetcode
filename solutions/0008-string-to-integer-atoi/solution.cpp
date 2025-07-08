class Solution {
public:
    int myAtoi(string s) 
    {
        bool flag = true;
        int i = 0;
        long long num = 0;
            while(s[i] == ' ') i++;
            if(s[i] == '-' || s[i] == '+' || (s[i] >= '0' && s[i] <= '9'))
            {
                if(s[i] == '-')
                {
                    i++;
                    flag = false;
                }
                else if(s[i] == '+')    i++;
                while(i < s.length() && s[i] == '0')  i++;
                while(i < s.length() && s[i] >= '0' && s[i] <= '9')
                {
                    if(flag && num > 2147483647)    
                        return 2147483647;
                    else if(!flag && num > 2147483648)   
                        return -2147483648;
                    else
                    {
                        cout << num << " ";
                        num *= 10;
                        num += (s[i] - '0');
                        i++;
                    }
                }
            }
        if(flag && num > 2147483647)    
                        return 2147483647;
        else if(!flag && num > 2147483648)   
                        return -2147483648;
        return flag?num:-num;
    }
};
