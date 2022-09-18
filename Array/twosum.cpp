// #include <iostream>
// #include <vector>
// using namespace std;
// class Solution
// {
// public:
//     vector<int> twoSum(vector<int> &nums, int target)
//     {
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int sum = 0;
//             for (int j = i+1; j < nums.size(); j++)
//             {
//                 sum = nums[i] + nums[j];
//                 if (sum == target)
//                 {
//                     vector<int> ans;
//                     ans.push_back(nums[i]);
//                     ans.push_back(nums[j]);
//                     return ans;
//                 }
//             }
//         }
//     }
// };

// Efficient Approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            int diff=target-nums[i];
            if(m.find(diff)!=m.end())
            {
                auto p=m.find(diff);
                v.push_back(p->second);
                v.push_back(i);
            }
            m.insert(make_pair(nums[i],i));
        }
        return v;
    }
};