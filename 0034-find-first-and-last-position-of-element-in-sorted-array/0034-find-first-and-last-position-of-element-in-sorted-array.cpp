class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        if(binary_search(nums.begin(),nums.end(),target))
        {
        ans[0]=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        ans[1]=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        }
        return ans;
    }
};