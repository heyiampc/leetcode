class Solution {
public:
int fun(vector<int> &nums , int ind, int prev_ind, int n, vector<vector<int>> &dp)
    {
        //Base Case
        if(ind==n)
            return 0;
    if(dp[ind][prev_ind+1]!=-1)
        return dp[ind][prev_ind+1];
        int len1=0+fun(nums,ind+1,prev_ind,n,dp); //not take
        int len2=0;
        if( prev_ind==-1 || nums[ind]>nums[prev_ind])
            len2=1+fun(nums,ind+1,ind,n,dp);
        return dp[ind][prev_ind+1]=max(len1,len2);
    }
    //     int f(int i,int prev, vector<int>& nums, int n,vector<vector<int>>&dp){
    //     if(i==n)return 0;
    //     if(dp[i][prev+1]!=-1)return dp[i][prev+1];
    //     int len=0+f(i+1,prev,nums,n,dp);
    //     if(prev==-1||nums[i]>nums[prev]){
    //         len=max(len,1+f(i+1,i,nums,n,dp));
    //     }
    //     return dp[i][prev+1]=len;
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return fun(nums,0,-1,n,dp);
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--)
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
            {
        int len1=0+dp[ind+1][prev_ind+1]; //not take cordinate shift therefore second parameter +1
        int len2=0;
        if( prev_ind==-1 || nums[ind]>nums[prev_ind])
            len2=1+dp[ind+1][ind+1]; //cordinate shift therefore second parameter +1
       dp[ind][prev_ind+1]=max(len1,len2);
        }
        return dp[0][-1+1];
    }
    
};