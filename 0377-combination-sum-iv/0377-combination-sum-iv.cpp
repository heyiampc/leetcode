class Solution {
public:
    int fun(vector<int>& nums, int target,vector<int> &dp)
    {
        if(target<0)
            return 0;
        if(target==0)
            return 1;
        if(dp[target]!=-1)
            return dp[target];
        int take=0;
        for(int i=0;i<nums.size();i++)
        take+=fun(nums,target-nums[i],dp);
        return dp[target]=take;
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return fun(nums,target,dp);
    }
};