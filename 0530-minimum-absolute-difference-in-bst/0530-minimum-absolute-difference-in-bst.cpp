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
    vector<int> vec;
    void fun(TreeNode* root)
    {
        if(root==NULL)
            return;
        fun(root->left);
        vec.push_back(root->val);
        fun(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        fun(root);
        int mini=INT_MAX;
        for(int i=0;i<vec.size();i++)
        {
            for(int j=0;j<vec.size();j++)
            {
                if(i==j)
                    continue;
                mini=min(mini,abs(vec[i]-vec[j]));
            }
        }
        return mini;
    }
};