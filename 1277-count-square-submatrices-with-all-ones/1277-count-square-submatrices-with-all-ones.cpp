class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        //Copy first row and columnn to dp
        for(int i=0;i<m;i++) dp[0][i]=matrix[0][i];
        for(int j=0;j<n;j++) dp[j][0]=matrix[j][0];
        
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==0)
                    dp[i][j]=0;
                else
                {
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans+=dp[i][j];
        return ans;
    }
};