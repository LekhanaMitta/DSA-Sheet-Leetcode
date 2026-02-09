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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        if(!root)   return {{}};
        queue<tuple<TreeNode*,int,int>> q;
        map<int, map<int, multiset<int>>> m;
        q.push({root,0,0}); 
        while(!q.empty())
        {
            auto [node, row, col] = q.front();q.pop();
            m[col][row].insert(node->val);
            if(node -> left)  q.push({node -> left, row + 1, col - 1});
            if(node->right )  q.push({node -> right, row + 1, col + 1});
        } 
        vector<vector<int>> ans;
        for(auto &it : m)
        {
            vector<int> vec;
            for (auto &it1 : it.second) {
                vec.insert(vec.end(), it1.second.begin(), it1.second.end());
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
