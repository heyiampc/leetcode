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
    int maxi=0;
    int height(TreeNode* root,int start) {
         if (root == NULL) {
            return 0;
        }
        int lh=height(root->left,start);
        int rh=height(root->right,start);
        if(root->val==start)
        {
            maxi=max(lh,rh);
            return -1;
            // return -1*(max(lh,rh)+1); 
        }
        else if(lh>=0 && rh>=0)
        {
            // maxi=max(lh,rh);
            return max(lh,rh)+1;
        }
        else
        {
            int a=abs(lh)+abs(rh);
            maxi=max(maxi,a);
            return min(lh,rh)-1;
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        height(root,start);
        return maxi;
    }
};