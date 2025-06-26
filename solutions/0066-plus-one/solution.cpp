class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int n = digits.size();
        int carry = (++digits[n-1])/10;
        digits[n-1] %= 10;
        for(int i=digits.size()-2;i>=0;i--)
        {
            digits[i] += carry;
            carry = digits[i]/10;
            digits[i] %= 10;
        } 
        if(carry)   
            digits.insert(digits.begin(), carry);
        return digits;
    }
};
