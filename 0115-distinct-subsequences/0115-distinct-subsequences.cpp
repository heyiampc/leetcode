class Solution {
public:
    int fun(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        //Base Case
        if(j<0) return 1; // s2 all characters matched in s1
        if(i<0) return 0; // s1 string ended and s2 characters is not matched
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])
        {
            return dp[i][j]=fun(i-1,j-1,s1,s2,dp)+fun(i-1,j,s1,s2,dp);
        }
        else
            return dp[i][j]=fun(i-1,j,s1,s2,dp);
    }
    int numDistinct(string &s, string &t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fun(n-1,m-1,s,t,dp);
    }
};