class Solution {
public:
    int gmaxi;
    int fun(vector<int> &nums,int n)
    {
        if(n==1)
            return nums[0];
        int curmax=max(nums[n-1],fun(nums,n-1)+nums[n-1]);
        gmaxi=max(gmaxi,curmax);
        return curmax;
    }
    int maxSubArray(vector<int>& nums) {
        gmaxi=nums[0];
        fun(nums,nums.size());
        return gmaxi;
    }
};