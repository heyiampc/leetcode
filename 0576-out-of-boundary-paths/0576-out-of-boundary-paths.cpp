class Solution {
public:
    int N,M;
    int dp[51][51][51];
    const int MOD=1e9+7;
    int fun(int i,int j, int moves)
    {
        if(i<0 || i>=N || j<0 || j>=M)
            return 1;
        if(dp[i][j][moves]!=-1)
            return dp[i][j][moves];
        int mv=0;
        if(moves>0)
        {
            mv=(mv+fun(i,j+1,moves-1))%MOD; //->
            mv=(mv+fun(i,j-1,moves-1))%MOD; //<-
            mv=(mv+fun(i+1,j,moves-1))%MOD; //down
            mv=(mv+fun(i-1,j,moves-1))%MOD; //up
        }
        return dp[i][j][moves]=mv;
    }
    int findPaths(int m, int n, int maxMove, int i, int j) {
        M=n;
        N=m;
        memset(dp,-1,sizeof(dp));
        return fun(i,j,maxMove);
    }
};