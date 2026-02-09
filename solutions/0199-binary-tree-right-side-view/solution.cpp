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
    vector<int> rightSideView(TreeNode* root) 
    {
        if(!root)   return {};
        queue<TreeNode*> q;    
        q.push(root);
        vector<int> v;
        bool flag = false;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(!flag)
                    v.push_back(curr -> val);
                flag = true;
                if(curr -> right)   q.push(curr -> right);
                if(curr -> left)    q.push(curr -> left);
            }
            flag = false;
        }
        return v;
    }
};
