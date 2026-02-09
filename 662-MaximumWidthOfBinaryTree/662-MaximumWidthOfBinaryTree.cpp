// Last updated: 2/9/2026, 1:27:48 PM
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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(!root)   return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root,1});
        long long res = 0;
        while(!q.empty())
        {
            int sz = q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            res = max(res, end - start + 1);
            for(int i=0;i<sz;i++)
            {
                pair<TreeNode*,long long> curr = q.front();
                q.pop();
                long long index = curr.second - start;
                // if(curr.first ->left)  q.push({curr.first->left, 2*curr.second + 1});
                // if(curr.first->right)  q.push({curr.first->right,2*curr.second + 2});
                if(curr.first ->left)  q.push({curr.first->left, 2*index + 1});
                if(curr.first->right)  q.push({curr.first->right,2*index + 2});
            }

        }
        return res;
    }
};