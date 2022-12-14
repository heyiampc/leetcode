class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        long profit=0;
        int n=prices.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1)); //nx2 dp required only
        // return fun(prices,0,1,profit,dp);
        
        //Tabulation
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        //base case
        dp[n][0]=dp[n][1]=0;
        for(int index=n-1;index>=0;index--)
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
        {
            long profit1=-prices[index]+dp[index+1][0]; //buy
            long profit2=0+dp[index+1][1]; //not buy this time go for next
            profit=max(profit1,profit2);
        }
        else
        {
            long profit1=prices[index]+dp[index+1][1]-fee; //sell
            long profit2=0+dp[index+1][0]; // not sell
            profit=max(profit1,profit2);
        }
                dp[index][buy]=profit;
            }
        return dp[0][1];
    }
};