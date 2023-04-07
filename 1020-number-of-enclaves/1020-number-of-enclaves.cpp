class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& g)
    {
        if(i<0 || j<0 || i>=g.size() || j>=g[0].size())
            return;
        if(g[i][j]==0)
            return;
        g[i][j]=0; //Mark visited
        dfs(i,j+1,g);
        dfs(i,j-1,g);
        dfs(i-1,j,g);
        dfs(i+1,j,g);
    }
    int numEnclaves(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        // //1st Row
        // for(int i=0;i<m;i++)
        //     if(g[0][i]==1)
        //         dfs(0,i,g);
        // //las Row
        // for(int i=0;i<m;i++)
        //     if(g[n-1][i]==1)
        //         dfs(n-1,i,g);
        // //1st col
        // for(int i=0;i<m;i++)
        //     if(g[i][0]==1)
        //         dfs(i,0,g);
        // //last col
        // for(int i=0;i<m;i++)
        //     if(g[m-1][i]==1)
        //         dfs(m-1,i,g);
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(g[i][j]==1)
                    {
                        dfs(i,j,g);
                    }
                }
            }
        }
                for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(g[i][j]==1)
                    count++;
            }
        }
        return count;
    }
};