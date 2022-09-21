class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++)
        {
            um[nums[i]]++;
        }
        int max=0;
        int max_freq;
        for(auto it:um)
        {
            if(max<it.second) 
            {
                max=it.second;
                max_freq=it.first;
            }
        }
        return max_freq;
    }
};