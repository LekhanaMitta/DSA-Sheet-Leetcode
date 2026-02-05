class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int five = 0, ten = 0;
        for(int i=0;i<bills.size();i++)
        {
            int bill = bills[i];
            if(bill == 5)
                five++;
            else if(bill == 10)
            {
                if(five == 0)   return false;
                ten++;
                five--;
            }
            else
            {
                if(five == 0)   return false;
                if(ten)
                {
                    ten--;
                    five--;
                }
                else
                {
                    if(five < 3)    return false;
                    else    five -= 3;
                }
            }
        }
        return true;    
    }
};
