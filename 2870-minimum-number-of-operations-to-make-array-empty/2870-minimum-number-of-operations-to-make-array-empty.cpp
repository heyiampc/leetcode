class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(auto &x:nums)
        {
            mp[x]++;
        }
        // for(auto &[a,b]:mp)
        // {
        //     cout<<a<<" "<<b<<endl;
        // }
        int cnt=0;
        for(auto &[a,x]:mp)
        {
            if(x==1)
                return -1;
            //[14,12,14,14,12,14,14,12,12,12,12,14,14,12,14,14,14,12,12]
            //[14==>10 times , 12==>9 times] take ceil for of 10/3 =>4(ceil) operation instead of 10/2=>5 operations
            cnt+=ceil((double)x/3*1.0);
        }
        return cnt;
    }
};