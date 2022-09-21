class Solution {
public:
    //1st Approach
     int majorityElement(vector<int>& nums) {
    //     unordered_map<int,int> um;
    //     for(auto i:nums)
    //     {
    //         um[i]++;
    //         if(um[i]>nums.size()/2) return i;
    //     }
    //     return -1;
    // }
    //2nd Approach
    sort(nums.begin(),nums.end());
    return nums[nums.size()/2];
     }
};