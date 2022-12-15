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
        
        //DP Solution
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return fun(prices,0,prices.size(),1,dp);
    }
};