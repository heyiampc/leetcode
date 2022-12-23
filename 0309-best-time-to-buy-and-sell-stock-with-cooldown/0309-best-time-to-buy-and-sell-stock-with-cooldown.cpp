class Solution {
public:
     int dp[5001][2];
    int solve(vector<int> &ar, int i, bool bought) {
        if(i >= ar.size()) return 0;
        if(dp[i][bought]!=-1) return dp[i][bought];
        
        if(bought)
        return dp[i][bought]=max( solve(ar,i+2,false)+ar[i] ,solve(ar,i+1,true));
        else
        return dp[i][bought]=max( solve(ar,i+1,true)-ar[i], solve(ar,i+1,false)); 
    }
    int maxProfit(vector<int>& prices) {
         memset(dp,-1,sizeof dp);
        return solve(prices,0,false);
    }
};