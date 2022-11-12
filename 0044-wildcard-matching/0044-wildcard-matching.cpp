class Solution {
public:
    bool fun(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        //Base Case
        if(i==0 && j==0) return true;
        if(i==0 && j>0) return false;
        if(i>0 && j==0)
        {
            for(int ii=1;ii<=i;ii++)
                if(s1[ii-1]!='*')
                    return false;
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i-1]==s2[j-1] || s1[i-1]=='?')
            return dp[i][j]=fun(i-1,j-1,s1,s2,dp);
        if(s1[i-1]=='*')
        {
            //fun(i-1,j,s1,s2) '*' as blank
            //fun(i,j-1,s1,s2) '*' as s2[j]
            return dp[i][j]=fun(i-1,j,s1,s2,dp) || fun(i,j-1,s1,s2,dp);
        }
        return false;
    }
    // Recursion
    // bool isMatch(string &s, string &p) {
    //     int n=s.size();
    //     int m=p.size();
    //     vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    //     return fun(m,n,p,s,dp);
    // }
    //Tabulation
    bool isMatch(string &s2, string &s1) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        //Base Case
        for(int j=1;j<=m;j++)
            dp[0][j]=false;
        for(int i=1;i<=n;i++)
        {
            for(int ii=1;ii<=i;ii++)
                if(s1[ii-1]!='*') 
                {dp[i][0]=false;
                 break;
                }
            else
                dp[i][0]=true;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
            if(s1[i-1]==s2[j-1] || s1[i-1]=='?')
            dp[i][j]=dp[i-1][j-1];
            else if(s1[i-1]=='*')
           {
            dp[i][j]=dp[i-1][j] || dp[i][j-1];
           }
            else
                dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};