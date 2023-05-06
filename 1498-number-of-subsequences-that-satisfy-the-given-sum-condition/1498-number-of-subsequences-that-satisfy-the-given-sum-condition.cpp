class Solution {
public:
    const int MOD=1e9+7;
    vector<int> pow;
    void calc(int n)
    {
        pow[0]=1;
        for(int i=1;i<=n;i++)
        {
            pow[i]=(2*pow[i-1])%MOD;
        }
    }
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        //power calc
        pow.resize(n+1);
        calc(n);
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]*2>target)
                break;
            int tar=target-nums[i];
            int ub=upper_bound(nums.begin(),nums.end(),tar)-nums.begin();
            cout<<ub-i-1<<" ";
            // count+=pow(2,ub-i-1);
            count=(count+pow[ub-i-1])%MOD;
        }
        return count;
    }
};