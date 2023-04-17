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
    int dfs(TreeNode* root ,int x,int d)
    {
        if(root==NULL)
            return 0;
        if(root->val==x)
            return d;
        int a=dfs(root->left,x,d+1);
        int b=dfs(root->right,x,d+1);
        return a+b;
    }
    TreeNode* dfs1(TreeNode* root, int x)
    {
        if(root==NULL || root->val==x)
            return root;
        if((root->left && root->left->val==x) || (root->right && root->right->val==x) )
            return root;
        TreeNode* l=dfs1(root->left,x);
        if(l)
            return l;
        TreeNode* r=dfs1(root->right,x);
        if(r)
            return r;
        return NULL;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int l1=dfs(root,x,0);
        int l2=dfs(root,y,0);
        TreeNode* p1;
        TreeNode* p2;
        p1=dfs1(root,x);
        p2=dfs1(root,y);
        // if(p1)
        // cout<<p1->val<<" ";
        // else
        //     cout<<"NULL ";
        // if(p2)
        // cout<<p2->val<<endl;
        // else
        //     cout<<"NULL "<<endl;
        return l1==l2 && p1!=p2;
    }
};