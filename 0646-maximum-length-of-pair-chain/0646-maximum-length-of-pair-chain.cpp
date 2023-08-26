class Solution {
public:
    // map<pair<int,int>,int> dp;
    long long dp[2500][2500];
    void print(vector<vector<int>> &nums)
    {
        for(auto &x:nums)
            cout<<"{"<<x[0]<<" "<<x[1]<<"}"<<" ";
        cout<<endl;
    }
    int lis(int i,vector<vector<int>> &nums,int prev)
    {
        if(i>=nums.size())
            return 0;
        // if(dp.find({i,prev})!=dp.end())
        //     return dp[{i,prev}];
        if(dp[i+1001][prev+1001]!=-1)
            return dp[i+1001][prev+1001];
        int take=0;
        if(nums[i][0]>prev){
            take=1+lis(i+1,nums,nums[i][1]);
        }
        int not_take=0+lis(i+1,nums,prev);
        return dp[i+1001][prev+1001]=max(take,not_take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        // print(pairs);
        memset(dp,-1,sizeof(dp));
        int ans=lis(0,pairs,-1001);
        return ans;
    }
};