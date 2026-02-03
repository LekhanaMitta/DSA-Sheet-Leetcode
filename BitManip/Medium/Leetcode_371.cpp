class Solution {
public:
    int getSum(int a, int b) 
    {
        // Loop until there is no carry left
        while (b)
        {
            // carry contains common set bits of a and b,
            // shifted left because carry affects the next higher bit
            int carry = (a & b) << 1;

            // XOR adds a and b without considering carry
            a = a ^ b;

            // b now stores the carry to be added in next iteration
            b = carry;
        }
        // When b becomes 0, a contains the final sum
        return a;
    }
};
