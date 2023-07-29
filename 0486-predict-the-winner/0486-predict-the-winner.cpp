class Solution {
public:
    using ll=long long;
    int n;
    ll fun(int i,int j,vector<int> &nums)
    {
        if(i>j)
            return 0;
        ll p1_i=nums[i]+min(fun(i+2,j,nums),fun(i+1,j-1,nums));
        ll p1_j=nums[j]+min(fun(i+1,j-1,nums),fun(i,j-2,nums));
        return max(p1_i,p1_j);
    }
    bool PredictTheWinner(vector<int>& nums) {
        n=nums.size();
        ll player1=fun(0,nums.size()-1,nums); // pl score
        ll total=accumulate(nums.begin(),nums.end(),0); // total score
        ll player2=total-player1; // p2 score
        return player1>=player2;
    }
};