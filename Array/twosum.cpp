#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i+1; j < nums.size(); j++)
            {
                sum = nums[i] + nums[j];
                if (sum == target)
                {
                    vector<int> ans;
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                    return ans;
                }
            }
        }
    }
};