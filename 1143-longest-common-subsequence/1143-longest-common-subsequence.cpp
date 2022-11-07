class Solution {
public:
    int fun(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
    {
        //Base Case
        if(ind1<0 || ind2<0)
            return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2])
            return 1+fun(ind1-1,ind2-1,s1,s2,dp);
        return dp[ind1][ind2]=max(fun(ind1-1,ind2,s1,s2,dp),fun(ind1,ind2-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(text1.length(),vector<int>(text2.length(),-1));
        // return fun(text1.length()-1,text2.length()-1,text1,text2,dp);
        //Tabulation
        int n=text1.size(), m=text2.size();
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int j=0;j<=m;j++)
            dp[0][j]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
            if(text1[i-1]==text2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};