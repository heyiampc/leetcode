class Solution {
public:
    int fun(int m, int n, int dp[100][100],vector<vector<int>> &grid)
    {
        if(m<0 || n<0 || grid[m][n]==1) return 0;
        if(m==0 &&n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        int up=fun(m-1,n,dp,grid);
        int left=fun(m,n-1,dp,grid);
        return dp[m][n]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[100][100];
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        memset(dp,-1,sizeof dp);
        return fun(m-1,n-1,dp,obstacleGrid);
    }
};