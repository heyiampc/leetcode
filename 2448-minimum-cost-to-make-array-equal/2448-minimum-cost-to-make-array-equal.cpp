#define ll long long
class Solution {
public:
    ll isPossible(vector<int> &nums, vector<int> &cost , ll target)
    {
        ll count=0;
        for(int i=0;i<nums.size();i++)
        {
            count+=cost[i]*(abs(nums[i]-target));
        }
        return count;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        int left=*min_element(nums.begin(),nums.end());
        int right=*max_element(nums.begin(),nums.end());
        ll ans=LLONG_MAX;
        while(left<=right)
        {
            ll mid=left+(right-left)/2;
            ll x=isPossible(nums,cost,mid);
            ll y=isPossible(nums,cost,mid+1);
            if(x<y)
            {
                ans=min(ans,x);
                right=mid-1;
            }
            else
            {
                ans=min(ans,y);
                left=mid+2;
            }
        }
        return ans;
    }
};