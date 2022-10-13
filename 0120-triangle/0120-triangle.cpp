class Solution {
public:
    int fun(int i, int j, int m, int n,vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(i==m-1) return grid[m-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int d=grid[i][j]+fun(i+1,j,m,n,grid,dp);
        int diag=grid[i][j]+fun(i+1,j+1,m,n,grid,dp);
        return dp[i][j]=min(d,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[0].size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return fun(0,0,triangle.size(),triangle[0].size(),triangle,dp);
    }
};