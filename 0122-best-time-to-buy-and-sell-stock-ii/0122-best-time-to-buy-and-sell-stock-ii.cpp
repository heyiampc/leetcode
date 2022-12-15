class Solution {
public:
    int profit=0;
    int fun(vector<int> &nums, int i, int n, int buy, vector<vector<int>> &dp)
    {
        if(i==n)
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy)
        {
            int take=-nums[i]+fun(nums,i+1,n,0,dp);
            int nottake=0+fun(nums,i+1,n,1,dp);
            profit=max(take,nottake);
        }
        else
        {
            int take=nums[i]+fun(nums,i+1,n,1,dp);
            int nottake=0+fun(nums,i+1,n,0,dp);
            profit=max(take,nottake);
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        //Greedy Solution
        // int max_profit=0;
        // for(int i=1;i<prices.size();i++)
        // {
        //     if(prices[i]>prices[i-1])max_profit+=prices[i]-prices[i-1];
        // }
        // return max_profit;
        
        //DP Solution memoization
        // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        // return fun(prices,0,prices.size(),1,dp);
        
        //DP Tabulation
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        int n=prices.size();
        //Base Condition
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
            for(int buy=0;buy<=1;buy++)
            {
                 if(buy)
            {
            int take=-prices[i]+dp[i+1][0];
            int nottake=0+dp[i+1][1];
            profit=max(take,nottake);
            }
                else
                    {
            int take=prices[i]+dp[i+1][1];
            int nottake=0+dp[i+1][0];
            profit=max(take,nottake);
                 }
        dp[i][buy]=profit;
    }
        return dp[0][1];
    }
};