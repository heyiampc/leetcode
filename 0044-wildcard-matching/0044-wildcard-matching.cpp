class Solution {
public:
    bool fun(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        //Base Case
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(i>=0 && j<0)
        {
            for(int ii=0;ii<=i;ii++)
                if(s1[ii]!='*')
                    return false;
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j] || s1[i]=='?')
            return dp[i][j]=fun(i-1,j-1,s1,s2,dp);
        if(s1[i]=='*')
        {
            //fun(i-1,j,s1,s2) '*' as blank
            //fun(i,j-1,s1,s2) '*' as s2[j]
            return dp[i][j]=fun(i-1,j,s1,s2,dp) || fun(i,j-1,s1,s2,dp);
        }
        return false;
    }
    bool isMatch(string &s, string &p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,p,s,dp);
    }
};