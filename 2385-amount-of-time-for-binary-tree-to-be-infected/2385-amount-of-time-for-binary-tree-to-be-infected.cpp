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
    int height(TreeNode* root,int start)
    {
        if(!root)
            return 0;
        int lh=height(root->left,start);
        int rh=height(root->right,start);
        if(root->val==start)
        {
            maxi=max(lh,rh); //start subtree max height
            return -1; //to indicate start
        }
        if(lh>=0 && rh>=0)
        {
            return max(lh,rh)+1;
        }
        else
        {
            int dist=abs(lh)+abs(rh);
            maxi=max(maxi,dist);
            return min(lh,rh)-1; //return start dist with adding 1
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        height(root,start);
        return maxi;
    }
};