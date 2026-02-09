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
    vector<vector<int>> ans;
    vector<int> v, temp;
    void path(TreeNode* root, int targetSum, int curr_sum, vector<int> v)
    {
        if(!root)
            return;
        if(!root -> left && !root -> right)
        {
            if(curr_sum == targetSum)
                ans.push_back(v);
            return;
        }
        if(root -> left)
        {
            v.push_back(root -> left -> val);
            path(root -> left, targetSum, curr_sum + root -> left -> val, v);
            v.pop_back();
        }
        if(root -> right)
        {
            v.push_back(root -> right -> val);
            path(root -> right, targetSum, curr_sum + root -> right -> val, v);
            v.pop_back();
        }
    } 
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        if(!root) return {};
        path(root, targetSum, root -> val, {root -> val});
        return ans;    
    }
};
