class Solution {
public:
    string addBinary(string a, string b) 
    {
        int n = a.length(), m = b.length();
        int i = n-1, j = m-1, carry = 0;
        string ans = "";
        while(i>=0 || j>=0 || carry)
        {
            if(i >= 0)  carry += a[i--]-'0';
            if(j >= 0)  carry += b[j--]-'0';
            ans += carry % 2 + '0';
            carry /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
