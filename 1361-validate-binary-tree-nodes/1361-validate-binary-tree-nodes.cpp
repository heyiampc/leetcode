class Solution {
public:
    void bfs(int root,map<int,vector<int>> &adj , set<int> &vis)
    {
        queue<int> q;
        q.push(root);
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            vis.insert(it);
            for(int i=0;i<adj[it].size();i++)
            {
                q.push(adj[it][i]);
            }
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        map<int,int> parent;
        map<int,vector<int>> adj;
        for(int i=0;i<n;i++)
        {
            int lc=leftChild[i];
            int rc=rightChild[i];
            if(lc!=-1){
                adj[i].push_back(lc);
                if(parent.find(lc)!=parent.end())
                    return false;
                parent[lc]=i;
            }
            if(rc!=-1){
                adj[i].push_back(rc);
                if(parent.find(rc)!=parent.end())
                    return false;
                parent[rc]=i;
            }
        }
        int root=-1;
        int cnt=0;//number of trees so count roots
        for(int i=0;i<n;i++)
        {
            if(parent.find(i)==parent.end()){
                root=i;
                cnt++;
                if(cnt>1)
                    return false;
            }
        }
       if(cnt==0)
           return false;
        set<int> vis;
        bfs(root,adj,vis);
        if(vis.size()!=n)
            return false;
        return true;
    }
};