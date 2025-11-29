/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<long long, int> prefixSum;
    int path(TreeNode* root, int target, long long sum)
    {
        if(!root)   return 0;
        int cnt = 0;
        
        sum += root -> val;
        if(prefixSum.find(sum - target) != prefixSum.end())   
            cnt = prefixSum[sum-target];
        prefixSum[sum]++;
        cnt += path(root -> left, target, sum);
        cnt += path(root -> right, target, sum);
        prefixSum[sum]--;
        sum -= root -> val;

        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) 
    {
        if(!root)   return 0;
        prefixSum[0] = 1;
        return path(root, targetSum, 0);
    }
};
