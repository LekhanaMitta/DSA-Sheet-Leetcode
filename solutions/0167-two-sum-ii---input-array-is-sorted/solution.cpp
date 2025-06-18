class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int i=0, j=numbers.size()-1;
        while(i < j)
        {
            // while(i < j && numbers[i] == numbers[i+1])  i++;
            // while(j > i && numbers[j-1] == numbers[j])  j--;
            int sum = numbers[i] + numbers[j];
            if(sum == target)   return {i+1, j+1};
            else if(sum < target)   i++;
            else    j--;
        }  
        return {0,0};  
    }
};
