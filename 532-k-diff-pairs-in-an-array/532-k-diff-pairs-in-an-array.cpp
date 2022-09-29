class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int n=nums.size();
        int count=0;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++)
            map[nums[i]]++;
        if(k==0)
        {
            for(auto x:map)
                if(x.second>1) count++;
            return count;
        }
        else
        {
            for(auto x:map)
            {
                if(map.count(x.first-k)) count++;
            }
            return count;
        }
        return count;
    }
};