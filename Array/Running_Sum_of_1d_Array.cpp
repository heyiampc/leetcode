//Brute Force
// class Solution {
// public:
//     int sumrun(vector<int>nums,int b)
//     {
//         int sum=0;
//         for(int i=0;i<b;i++)
//         {
//             sum+=nums[i];
//         }
//         return sum;
//     }
//     vector<int> runningSum(vector<int>& nums) {
//         vector<int> ans;
//         ans.push_back(nums[0]);
//         for(int i=1;i<nums.size();i++)
//         {
//             int res=sumrun(nums,i+1);
//             ans.push_back(res);
//         }
//         return ans;
//     }
// };

//Efficient Approach
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++)
        {
            nums[i]+=nums[i-1];
        }
        return nums;
    }
};