class Solution {
public:
    int dp[101][101];
    int fun(int l, int r, string s)
    {
        if(l==r)
            return 1;
        if(l>r)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        int i=l+1;
        while(i<=r && s[i]==s[l])
            i++;
        if(i==r+1)
            return 1;
        int basic=1+fun(i,r,s);
        int greedy=1e9;
        for(int j=i;j<=r;j++)
        {
            if(s[j]==s[l])
            {
                int p1=fun(i,j-1,s);
                int p2=fun(j,r,s);
                greedy=min(greedy,p1+p2);
            }
        }
        return dp[l][r]=min(basic,greedy);
    }
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        return fun(0,s.size()-1,s);
    }
};