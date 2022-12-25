class Solution {
public:
    long fun(vector<int> &v, int index, int buy, long &profit, vector<vector<int>> &dp) 
    {
        //(+) selling stock money increased (-) buying stock money decreasd
        if(index==v.size())
            return 0;
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        if(buy)
        {
            long profit1=-v[index]+fun(v,index+1,0,profit,dp); //buy
            long profit2=0+fun(v,index+1,1,profit,dp); //not buy this time go for next
            profit=max(profit1,profit2);
        }
        else
        {
            long profit1=v[index]+fun(v,index+1,1,profit,dp); //sell
            long profit2=0+fun(v,index+1,0,profit,dp); // not sell
            profit=max(profit1,profit2);
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        long profit=0;
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1)); //nx2 dp required only
        return fun(prices,0,1,profit,dp);
    }
};