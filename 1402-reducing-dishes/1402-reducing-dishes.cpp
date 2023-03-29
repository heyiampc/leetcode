class Solution {
public:
    int dp[501][501];
    int fun(vector<int> &nums, int time, int ind)
    {
        //Base Case
        if(ind==nums.size())
            return 0;
        if(dp[ind][time]!=-1)
            return dp[ind][time];
        int take=nums[ind]*time + fun(nums,time+1,ind+1);
        int not_take=0+fun(nums,time,ind+1);
        return dp[ind][time]=max(take,not_take);
        
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        memset(dp,-1,sizeof(dp));
        return fun(satisfaction,1,0);
    }
};