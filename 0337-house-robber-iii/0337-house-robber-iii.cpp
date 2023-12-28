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
    map<pair<TreeNode*,bool>,int> dp;
    int fun(TreeNode* root,int t)
    {
        if(root==NULL)
            return 0;
        int take=0,not_take=0;
        if(dp.find({root,t})!=dp.end())
            return dp[{root,t}];
        if(t)
        {
            take=root->val+fun(root->left,0)+fun(root->right,0);
            not_take=0+fun(root->left,1)+fun(root->right,1);
        }
        if(!t)
        {
            take=0+fun(root->left,1)+fun(root->right,1);
            not_take=0+fun(root->left,1)+fun(root->right,1);
        }
        return dp[{root,t}]=max(take,not_take);
    }
    int rob(TreeNode* root) {
        return fun(root,1);
    }
};