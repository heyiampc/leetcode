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
    TreeNode* insert(TreeNode* root, TreeNode* node, int val)
    {
        if(root==NULL)
            return node;
        if(val>root->val)
            root->right=insert(root->right,node,val);
        else
            root->left=insert(root->left,node,val);
        
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node= new TreeNode(val);
        if(root==NULL)
            return node;
        return insert(root,node,val);
    }
};