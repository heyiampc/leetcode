class Solution {
public:
        long fun(vector<int> &prices, int index, int buy, int cap, vector<vector<vector<int>>> &dp, long profit)
    {
        if(index==prices.size())
            return 0;
        if(cap==0)
            return 0;
        if(dp[index][buy][cap]!=-1)
            return dp[index][buy][cap];
        if(buy)
        {
            //buy
            long profit1=-prices[index]+fun(prices,index+1,0,cap,dp,profit);
            long profit2=0+fun(prices,index+1,1,cap,dp,profit);
            profit= max(profit1,profit2);
        }
        else
        {
            //sell
            long profit1=prices[index]+fun(prices,index+1,1,cap-1,dp,profit);
            long profit2=0+fun(prices,index+1,0,cap,dp,profit);
            profit= max(profit1,profit2);
        }
        return dp[index][buy][cap]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        long profit=0;
        //n-> size 2-> 0/1 buy or not buy cap-> 0/1/2
        vector<vector<vector<int> > > dp(n, vector<vector<int> >(2, vector<int>(k+1, -1)));
        return fun(prices,0,1,k,dp,profit);
    }
};