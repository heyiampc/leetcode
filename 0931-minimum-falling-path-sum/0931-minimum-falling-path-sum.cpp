class Solution {
public:
    int fun(vector<vector<int>>& a, int i, int j, int m, vector<vector<int>>& dp)
    {
        // Base Case
        if(j<0 || j>=m) return 1e9;
        if(i==0) return a[i][j]; //or a[0][j]
        if(dp[i][j]!=-1) return dp[i][j];
        int up=a[i][j]+fun(a,i-1,j,m,dp);
        int ld=a[i][j]+fun(a,i-1,j-1,m,dp);
        int ud=a[i][j]+fun(a,i-1,j+1,m,dp);
        return dp[i][j]=min(up,min(ld,ud));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini=INT_MAX;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++)
        mini=min(mini,fun(matrix,n-1,j,m,dp));
        return mini;
    }
};