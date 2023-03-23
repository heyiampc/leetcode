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
#define ll long long
class Solution {
public:
    vector<vector<pair<ll,ll>>> ans;
    vector<pair<ll,ll>> temp;
    queue<pair<TreeNode*,ll>> q;
    ll maxi=0;
    void fun(TreeNode* root)
    {
        q.push({root,0});
        while(!q.empty())
        {
            int n=q.size();
            ll minil=q.front().second;
            for(int i=0;i<n;i++)
            {
            pair<TreeNode*,ll> front=q.front();
            ll curr=front.second-minil;
            q.pop();
            if(front.first->left)
                q.push({front.first->left,2*(curr)+1});
            if(front.first->right)
                q.push({front.first->right,2*(curr)+2});   
            temp.push_back({front.first->val,front.second});
            }
            ans.push_back(temp);
            ll n_1=ans.size();
            ll n1=ans[n_1-1].size();
            maxi=max(maxi,abs(ans[n_1-1][0].second-ans[n_1-1][n1-1].second)+1);
            temp.clear();
        }
    }
    void print(vector<vector<pair<ll,ll>>> &ans)
    {
        for(auto x:ans)
        {
            for(auto j:x)
                cout<<j.second<<" ";
            cout<<endl;
        }
    }
    int levelOrder(TreeNode* root) {
        if(root==NULL)
            return 0;
        fun(root);
        print(ans);
        return maxi;
    }
    int widthOfBinaryTree(TreeNode* root) {
        return levelOrder(root);
    }
};