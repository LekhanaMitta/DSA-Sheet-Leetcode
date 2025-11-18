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
    void dfs(TreeNode* root, int level)
    {
        if(!root)   return;
        if(level == ans.size())
            ans.push_back(vector<int>());
        ans[level].push_back(root -> val);
        dfs(root->left, level+1);
        dfs(root -> right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        // queue<TreeNode*> q;
        // if(!root)   return {};
        // q.push(root);   
        // while(!q.empty())
        // {
        //     vector<int> v;
        //     int len = q.size();
        //     for(int i=0;i<len;i++)
        //     {
        //         TreeNode* temp = q.front();
        //         q.pop();
        //         v.push_back(temp -> val);
        //         if(temp -> left)    q.push(temp -> left);
        //         if(temp -> right)   q.push(temp-> right);
        //     }
        //     ans.push_back(v);
        // } 
        // return ans;

        dfs(root, 0);
        return ans;
    }
};
